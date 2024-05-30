#pragma once
#include <ydb/library/actors/core/actor_bootstrapped.h>
#include <ydb/library/actors/core/interconnect.h>
#include <ydb/library/actors/core/mon.h>
#include <ydb/library/services/services.pb.h>
#include <ydb/core/viewer/json/json.h>
#include <library/cpp/json/json_writer.h>
#include "viewer.h"
#include "json_pipe_req.h"

namespace NKikimr {
namespace NViewer {

using namespace NActors;

class TJsonPDiskRestart : public TViewerPipeClient<TJsonPDiskRestart> {
    enum EEv {
        EvRetryNodeRequest = EventSpaceBegin(NActors::TEvents::ES_PRIVATE),
        EvEnd
    };

    static_assert(EvEnd < EventSpaceEnd(NActors::TEvents::ES_PRIVATE), "expect EvEnd < EventSpaceEnd(TEvents::ES_PRIVATE)");

    struct TEvRetryNodeRequest : NActors::TEventLocal<TEvRetryNodeRequest, EvRetryNodeRequest> {
        TEvRetryNodeRequest()
        {}
    };

protected:
    using TThis = TJsonPDiskRestart;
    using TBase = TViewerPipeClient<TThis>;
    IViewer* Viewer;
    NMon::TEvHttpInfo::TPtr Event;
    TJsonSettings JsonSettings;
    bool AllEnums = false;
    ui32 Timeout = 0;
    ui32 ActualRetries = 0;
    ui32 Retries = 0;
    TDuration RetryPeriod = TDuration::MilliSeconds(500);

    std::unique_ptr<TEvBlobStorage::TEvAskWardenRestartPDiskResult> Response;

    ui32 NodeId = 0;
    ui32 PDiskId = 0;

    TActorId SessionId;

public:
    static constexpr NKikimrServices::TActivity::EType ActorActivityType() {
        return NKikimrServices::TActivity::VIEWER_HANDLER;
    }

    TJsonPDiskRestart(IViewer* viewer, NMon::TEvHttpInfo::TPtr& ev)
        : Viewer(viewer)
        , Event(ev)
    {}

    void Bootstrap() {
        const auto& params(Event->Get()->Request.GetParams());
        NodeId = FromStringWithDefault<ui32>(params.Get("node_id"), 0);
        PDiskId = FromStringWithDefault<ui32>(params.Get("pdisk_id"), Max<ui32>());

        if (PDiskId == Max<ui32>()) {
            TBase::Send(Event->Sender, new NMon::TEvHttpInfoRes(
                Viewer->GetHTTPBADREQUEST(Event->Get(), "text/plain", "field 'pdisk_id' is required"),
                0, NMon::IEvHttpInfoRes::EContentType::Custom));
            return PassAway();
        }
        if (Event->Get()->Request.GetMethod() != HTTP_METHOD_POST) {
            TBase::Send(Event->Sender, new NMon::TEvHttpInfoRes(
                Viewer->GetHTTPBADREQUEST(Event->Get(), "text/plain", "Only POST method is allowed"),
                0, NMon::IEvHttpInfoRes::EContentType::Custom));
            return PassAway();
        }

        if (!NodeId) {
            NodeId = TlsActivationContext->ActorSystem()->NodeId;
        }
        TBase::InitConfig(params);

        Timeout = FromStringWithDefault<ui32>(params.Get("timeout"), 10000);
        Retries = FromStringWithDefault<ui32>(params.Get("retries"), 0);
        RetryPeriod = TDuration::MilliSeconds(FromStringWithDefault<ui32>(params.Get("retry_period"), RetryPeriod.MilliSeconds()));

        SendRequest();

        TBase::Become(&TThis::StateWork, TDuration::MilliSeconds(Timeout), new TEvents::TEvWakeup());
    }

    STATEFN(StateWork) {
        switch (ev->GetTypeRewrite()) {
            hFunc(TEvBlobStorage::TEvAskWardenRestartPDiskResult, Handle);
            cFunc(TEvRetryNodeRequest::EventType, HandleRetry);
            cFunc(TEvents::TEvUndelivered::EventType, Undelivered);
            hFunc(TEvInterconnect::TEvNodeConnected, Connected);
            hFunc(TEvInterconnect::TEvNodeDisconnected, Disconnected);
            cFunc(TEvents::TSystem::Wakeup, HandleTimeout);
        }
    }

    void SendRequest() {
        auto request = MakeHolder<TEvBlobStorage::TEvAskWardenRestartPDisk>(PDiskId);
        TBase::SendRequest(MakeBlobStorageNodeWardenID(NodeId),
                           request.Release(),
                           IEventHandle::FlagTrackDelivery | IEventHandle::FlagSubscribeOnSession,
                           NodeId);
    }

    bool RetryRequest() {
        if (Retries) {
            if (++ActualRetries <= Retries) {
                TBase::Schedule(RetryPeriod, new TEvRetryNodeRequest());
                return true;
            }
        }
        return false;
    }

    void Undelivered() {
        if (!RetryRequest()) {
            TBase::RequestDone();
        }
    }

    void Connected(TEvInterconnect::TEvNodeConnected::TPtr& ev) {
        SessionId = ev->Sender;
    }

    void Disconnected(TEvInterconnect::TEvNodeDisconnected::TPtr&) {
        SessionId = {};
        if (!RetryRequest()) {
            TBase::RequestDone();
        }
    }

    void Handle(TEvBlobStorage::TEvAskWardenRestartPDiskResult::TPtr& ev) {
        Response.reset(ev->Release().Release());
        ReplyAndPassAway();
    }

    void HandleRetry() {
        SendRequest();
    }

    void HandleTimeout() {
        Send(Event->Sender, new NMon::TEvHttpInfoRes(
            Viewer->GetHTTPGATEWAYTIMEOUT(Event->Get(), "text/plain", "Timeout receiving response from NodeWarden"),
            0, NMon::IEvHttpInfoRes::EContentType::Custom));
    }

    void PassAway() override {
        if (SessionId) {
            TBase::Send(SessionId, new TEvents::TEvUnsubscribe());
        }
        TBase::PassAway();
    }

    void ReplyAndPassAway() {
        NJson::TJsonValue json;
        if (Response != nullptr) {
            json["result"] = Response->RestartAllowed;
            if (Response->Details) {
                json["error"] = Response->Details;
            }
        } else {
            json["result"] = false;
            json["error"] = "No response was received from the NodeWarden";
        }
        TBase::Send(Event->Sender, new NMon::TEvHttpInfoRes(Viewer->GetHTTPOKJSON(Event->Get(), NJson::WriteJson(json)), 0, NMon::IEvHttpInfoRes::EContentType::Custom));
        PassAway();
    }
};

template <>
YAML::Node TJsonRequestSwagger<TJsonPDiskRestart>::GetSwagger() {
    return YAML::Load(R"___(
        post:
          tags:
          - pdisk
          produces:
          - application/json
          summary: Restart PDisk
          description: Restart PDisk on the specified node
          parameters:
          - name: node_id
            in: query
            description: node identifier
            type: integer
          - name: pdisk_id
            in: query
            description: pdisk identifier
            required: true
            type: integer
          - name: timeout
            in: query
            description: timeout in ms
            required: false
            type: integer
          - name: retries
            in: query
            description: number of retries
            required: false
            type: integer
          - name: retry_period
            in: query
            description: retry period in ms
            required: false
            type: integer
            default: 500
          responses:
            200:
              description: OK
              schema:
                type: object
                properties:
                  result:
                    type: boolean
                    description: was operation successful or not
                  error:
                    type: string
                    description: details about failed operation
            400:
              description: Bad Request
            403:
              description: Forbidden
            504:
              description: Gateway Timeout
        )___");
}

}
}