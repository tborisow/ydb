TExecFunc arrow_any_in() { return MakeIndirectExec<true, true>(&any_in); }
TExecFunc arrow_any_out() { return MakeIndirectExec<true, false>(&any_out); }
TExecFunc arrow_anyarray_in() { return MakeIndirectExec<true, false>(&anyarray_in); }
TExecFunc arrow_anyarray_out() { return MakeIndirectExec<true, false>(&anyarray_out); }
TExecFunc arrow_anyarray_recv() { return MakeIndirectExec<true, false>(&anyarray_recv); }
TExecFunc arrow_anyarray_send() { return MakeIndirectExec<true, false>(&anyarray_send); }
TExecFunc arrow_anycompatible_in() { return MakeIndirectExec<true, true>(&anycompatible_in); }
TExecFunc arrow_anycompatible_out() { return MakeIndirectExec<true, false>(&anycompatible_out); }
TExecFunc arrow_anycompatiblearray_in() { return MakeIndirectExec<true, false>(&anycompatiblearray_in); }
TExecFunc arrow_anycompatiblearray_out() { return MakeIndirectExec<true, false>(&anycompatiblearray_out); }
TExecFunc arrow_anycompatiblearray_recv() { return MakeIndirectExec<true, false>(&anycompatiblearray_recv); }
TExecFunc arrow_anycompatiblearray_send() { return MakeIndirectExec<true, false>(&anycompatiblearray_send); }
TExecFunc arrow_anycompatiblemultirange_in() { return MakeIndirectExec<true, false>(&anycompatiblemultirange_in); }
TExecFunc arrow_anycompatiblemultirange_out() { return MakeIndirectExec<true, false>(&anycompatiblemultirange_out); }
TExecFunc arrow_anycompatiblenonarray_in() { return MakeIndirectExec<true, true>(&anycompatiblenonarray_in); }
TExecFunc arrow_anycompatiblenonarray_out() { return MakeIndirectExec<true, false>(&anycompatiblenonarray_out); }
TExecFunc arrow_anycompatiblerange_in() { return MakeIndirectExec<true, false>(&anycompatiblerange_in); }
TExecFunc arrow_anycompatiblerange_out() { return MakeIndirectExec<true, false>(&anycompatiblerange_out); }
TExecFunc arrow_anyelement_in() { return MakeIndirectExec<true, true>(&anyelement_in); }
TExecFunc arrow_anyelement_out() { return MakeIndirectExec<true, false>(&anyelement_out); }
TExecFunc arrow_anyenum_in() { return MakeIndirectExec<true, true>(&anyenum_in); }
TExecFunc arrow_anyenum_out() { return MakeIndirectExec<true, false>(&anyenum_out); }
TExecFunc arrow_anymultirange_in() { return MakeIndirectExec<true, false>(&anymultirange_in); }
TExecFunc arrow_anymultirange_out() { return MakeIndirectExec<true, false>(&anymultirange_out); }
TExecFunc arrow_anynonarray_in() { return MakeIndirectExec<true, true>(&anynonarray_in); }
TExecFunc arrow_anynonarray_out() { return MakeIndirectExec<true, false>(&anynonarray_out); }
TExecFunc arrow_anyrange_in() { return MakeIndirectExec<true, false>(&anyrange_in); }
TExecFunc arrow_anyrange_out() { return MakeIndirectExec<true, false>(&anyrange_out); }
TExecFunc arrow_cstring_in() { return MakeIndirectExec<true, false>(&cstring_in); }
TExecFunc arrow_cstring_out() { return MakeIndirectExec<true, false>(&cstring_out); }
TExecFunc arrow_cstring_recv() { return MakeIndirectExec<true, false>(&cstring_recv); }
TExecFunc arrow_cstring_send() { return MakeIndirectExec<true, false>(&cstring_send); }
TExecFunc arrow_event_trigger_in() { return MakeIndirectExec<false, true>(&event_trigger_in); }
TExecFunc arrow_event_trigger_out() { return MakeIndirectExec<true, false>(&event_trigger_out); }
TExecFunc arrow_fdw_handler_in() { return MakeIndirectExec<false, true>(&fdw_handler_in); }
TExecFunc arrow_fdw_handler_out() { return MakeIndirectExec<true, false>(&fdw_handler_out); }
TExecFunc arrow_ginhandler() { return MakeIndirectExec<true, true>(&ginhandler); }
TExecFunc arrow_hypothetical_cume_dist_final() { return MakeIndirectExec<false, true>(&hypothetical_cume_dist_final); }
TExecFunc arrow_hypothetical_dense_rank_final() { return MakeIndirectExec<false, true>(&hypothetical_dense_rank_final); }
TExecFunc arrow_hypothetical_percent_rank_final() { return MakeIndirectExec<false, true>(&hypothetical_percent_rank_final); }
TExecFunc arrow_hypothetical_rank_final() { return MakeIndirectExec<false, true>(&hypothetical_rank_final); }
TExecFunc arrow_index_am_handler_in() { return MakeIndirectExec<false, true>(&index_am_handler_in); }
TExecFunc arrow_index_am_handler_out() { return MakeIndirectExec<true, false>(&index_am_handler_out); }
TExecFunc arrow_internal_in() { return MakeIndirectExec<false, true>(&internal_in); }
TExecFunc arrow_internal_out() { return MakeIndirectExec<true, false>(&internal_out); }
TExecFunc arrow_language_handler_in() { return MakeIndirectExec<false, true>(&language_handler_in); }
TExecFunc arrow_language_handler_out() { return MakeIndirectExec<true, false>(&language_handler_out); }
TExecFunc arrow_mode_final() { return MakeIndirectExec<false, true>(&mode_final); }
TExecFunc arrow_multirangesel() { return MakeIndirectExec<true, true>(&multirangesel); }
TExecFunc arrow_ordered_set_transition() { return MakeIndirectExec<false, true>(&ordered_set_transition); }
TExecFunc arrow_ordered_set_transition_multi() { return MakeIndirectExec<false, true>(&ordered_set_transition_multi); }
TExecFunc arrow_percentile_cont_float8_final() { return MakeIndirectExec<false, true>(&percentile_cont_float8_final); }
TExecFunc arrow_percentile_cont_float8_multi_final() { return MakeIndirectExec<false, false>(&percentile_cont_float8_multi_final); }
TExecFunc arrow_percentile_cont_interval_final() { return MakeIndirectExec<false, false>(&percentile_cont_interval_final); }
TExecFunc arrow_percentile_cont_interval_multi_final() { return MakeIndirectExec<false, false>(&percentile_cont_interval_multi_final); }
TExecFunc arrow_percentile_disc_final() { return MakeIndirectExec<false, true>(&percentile_disc_final); }
TExecFunc arrow_percentile_disc_multi_final() { return MakeIndirectExec<false, false>(&percentile_disc_multi_final); }
TExecFunc arrow_pg_ddl_command_in() { return MakeIndirectExec<true, true>(&pg_ddl_command_in); }
TExecFunc arrow_pg_ddl_command_out() { return MakeIndirectExec<true, false>(&pg_ddl_command_out); }
TExecFunc arrow_pg_ddl_command_recv() { return MakeIndirectExec<true, true>(&pg_ddl_command_recv); }
TExecFunc arrow_pg_ddl_command_send() { return MakeIndirectExec<true, false>(&pg_ddl_command_send); }
TExecFunc arrow_pg_jit_available() { return MakeIndirectExec<true, true>(&pg_jit_available); }
TExecFunc arrow_pg_lsn_cmp() { return MakeIndirectExec<true, true>(&pg_lsn_cmp); }
TExecFunc arrow_pg_lsn_eq() { return MakeIndirectExec<true, true>(&pg_lsn_eq); }
TExecFunc arrow_pg_lsn_ge() { return MakeIndirectExec<true, true>(&pg_lsn_ge); }
TExecFunc arrow_pg_lsn_gt() { return MakeIndirectExec<true, true>(&pg_lsn_gt); }
TExecFunc arrow_pg_lsn_hash() { return MakeIndirectExec<true, true>(&pg_lsn_hash); }
TExecFunc arrow_pg_lsn_hash_extended() { return MakeIndirectExec<true, true>(&pg_lsn_hash_extended); }
TExecFunc arrow_pg_lsn_in() { return MakeIndirectExec<true, true>(&pg_lsn_in); }
TExecFunc arrow_pg_lsn_larger() { return MakeIndirectExec<true, true>(&pg_lsn_larger); }
TExecFunc arrow_pg_lsn_le() { return MakeIndirectExec<true, true>(&pg_lsn_le); }
TExecFunc arrow_pg_lsn_lt() { return MakeIndirectExec<true, true>(&pg_lsn_lt); }
TExecFunc arrow_pg_lsn_mi() { return MakeIndirectExec<true, false>(&pg_lsn_mi); }
TExecFunc arrow_pg_lsn_mii() { return MakeIndirectExec<true, true>(&pg_lsn_mii); }
TExecFunc arrow_pg_lsn_ne() { return MakeIndirectExec<true, true>(&pg_lsn_ne); }
TExecFunc arrow_pg_lsn_out() { return MakeIndirectExec<true, false>(&pg_lsn_out); }
TExecFunc arrow_pg_lsn_pli() { return MakeIndirectExec<true, true>(&pg_lsn_pli); }
TExecFunc arrow_pg_lsn_recv() { return MakeIndirectExec<true, true>(&pg_lsn_recv); }
TExecFunc arrow_pg_lsn_send() { return MakeIndirectExec<true, false>(&pg_lsn_send); }
TExecFunc arrow_pg_lsn_smaller() { return MakeIndirectExec<true, true>(&pg_lsn_smaller); }
TExecFunc arrow_pg_node_tree_in() { return MakeIndirectExec<true, false>(&pg_node_tree_in); }
TExecFunc arrow_pg_node_tree_out() { return MakeIndirectExec<true, false>(&pg_node_tree_out); }
TExecFunc arrow_pg_node_tree_recv() { return MakeIndirectExec<true, false>(&pg_node_tree_recv); }
TExecFunc arrow_pg_node_tree_send() { return MakeIndirectExec<true, false>(&pg_node_tree_send); }
TExecFunc arrow_shell_in() { return MakeIndirectExec<false, true>(&shell_in); }
TExecFunc arrow_shell_out() { return MakeIndirectExec<true, false>(&shell_out); }
TExecFunc arrow_spg_quad_choose() { return MakeIndirectExec<true, true>(&spg_quad_choose); }
TExecFunc arrow_spg_quad_config() { return MakeIndirectExec<true, true>(&spg_quad_config); }
TExecFunc arrow_spg_quad_inner_consistent() { return MakeIndirectExec<true, true>(&spg_quad_inner_consistent); }
TExecFunc arrow_spg_quad_leaf_consistent() { return MakeIndirectExec<true, true>(&spg_quad_leaf_consistent); }
TExecFunc arrow_spg_quad_picksplit() { return MakeIndirectExec<true, true>(&spg_quad_picksplit); }
TExecFunc arrow_table_am_handler_in() { return MakeIndirectExec<false, true>(&table_am_handler_in); }
TExecFunc arrow_table_am_handler_out() { return MakeIndirectExec<true, false>(&table_am_handler_out); }
TExecFunc arrow_trigger_in() { return MakeIndirectExec<false, true>(&trigger_in); }
TExecFunc arrow_trigger_out() { return MakeIndirectExec<true, false>(&trigger_out); }
TExecFunc arrow_tsm_handler_in() { return MakeIndirectExec<false, true>(&tsm_handler_in); }
TExecFunc arrow_tsm_handler_out() { return MakeIndirectExec<true, false>(&tsm_handler_out); }
TExecFunc arrow_tsvectorin() { return MakeIndirectExec<true, false>(&tsvectorin); }
TExecFunc arrow_tsvectorout() { return MakeIndirectExec<true, false>(&tsvectorout); }
TExecFunc arrow_tsvectorrecv() { return MakeIndirectExec<true, false>(&tsvectorrecv); }
TExecFunc arrow_tsvectorsend() { return MakeIndirectExec<true, false>(&tsvectorsend); }
TExecFunc arrow_void_in() { return MakeIndirectExec<true, true>(&void_in); }
TExecFunc arrow_void_out() { return MakeIndirectExec<true, false>(&void_out); }
TExecFunc arrow_void_recv() { return MakeIndirectExec<true, true>(&void_recv); }
TExecFunc arrow_void_send() { return MakeIndirectExec<true, false>(&void_send); }