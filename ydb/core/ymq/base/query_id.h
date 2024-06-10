#pragma once

#include <util/system/defaults.h>

namespace NKikimr::NSQS {

enum EQueryId {
    DELETE_MESSAGE_ID,
    LOCK_GROUP_ID,
    READ_MESSAGE_ID,
    WRITE_MESSAGE_ID,
    PURGE_QUEUE_ID,
    CHANGE_VISIBILITY_ID,
    CLEANUP_DEDUPLICATION_ID,
    CLEANUP_READS_ID,
    LIST_QUEUES_ID,
    SET_QUEUE_ATTRIBUTES_ID,
    SET_RETENTION_ID,
    LOAD_MESSAGES_ID,
    INTERNAL_GET_QUEUE_ATTRIBUTES_ID,
    PURGE_QUEUE_STAGE2_ID,
    GET_MESSAGE_COUNT_METRIC_ID,
    GET_OLDEST_MESSAGE_TIMESTAMP_METRIC_ID,
    GET_RETENTION_OFFSET_ID,
    LOAD_INFLY_ID,
    ADD_MESSAGES_TO_INFLY_ID,
    LIST_DEAD_LETTER_SOURCE_QUEUES_ID,
    LOAD_OR_REDRIVE_MESSAGE_ID,
    READ_OR_REDRIVE_MESSAGE_ID,
    GET_USER_SETTINGS_ID,
    GET_QUEUES_LIST_ID,
    GET_STATE_ID,
    
    QUERY_VECTOR_SIZE,
};

} // namespace NKikimr::NSQS