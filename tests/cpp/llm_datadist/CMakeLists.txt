# ----------------------------------------------------------------------------
# This program is free software, you can redistribute it and/or modify.
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------

set(LLM_DATADIST_TEST_FILES
        test_data_cache_engine.cc
        test_llm_datadist_v2_api.cc
        test_adxl_engine_api.cc
        llm_comm_link_manager_unittest.cc
        llm_datadist_v2_api_unittest.cc
        llm_utils_v2_unittest.cc
        data_cache_engine_unittest.cc
        aligned_ptr_unittest.cc
        adxl_engine_api_unittest.cc
        segment_table_unittest.cc
)
set(LLM_DATADIST_STUB_SRC_FILES
        "${AIR_CODE_DIR}/tests/depends/llm_datadist/src/data_cache_engine_test_helper.cc"
        "${AIR_CODE_DIR}/tests/depends/llm_datadist/src/ascend_string_stub.cc"
        "${AIR_CODE_DIR}/tests/depends/llm_datadist/src/hccl_stub.cc"
)

file(GLOB LLM_V2_SRC_LIST
        "${AIR_CODE_DIR}/src/llm_datadist/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/api/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/adxl/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/common/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/cache_mgr/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/link_mgr/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/hccl/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/fsm/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/utils/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/data_transfer/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/memory/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/memory/allocator/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/memory/config/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/memory/span/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/memory/type/*.cc"
        "${AIR_CODE_DIR}/src/llm_datadist/memory/util/*.cc")

add_executable(llm_datadist_test
        ${LLM_DATADIST_TEST_FILES}
        ${LLM_DATADIST_STUB_SRC_FILES}
        ${LLM_V2_SRC_LIST}
        )

target_compile_options(llm_datadist_test PRIVATE
        ${COMMON_COMPILE_OPTION}
        -Wno-deprecated-declarations
        -Wall -Wfloat-equal
        )

target_include_directories(llm_datadist_test PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${AIR_CODE_DIR}/include
        ${AIR_CODE_DIR}/src/llm_datadist
        ${AIR_CODE_DIR}/tests
        ${AIR_CODE_DIR}/tests/depends/llm_datadist/src
        )

set_target_properties(llm_datadist_test PROPERTIES CXX_STANDARD 17)

target_link_libraries(llm_datadist_test
        ${COMMON_LINK_OPTION}
        c_sec
        mmpa_headers
        hccl_headers
        runtime_headers
        metadef_headers
        intf_pub
        json
        -ldl
        slog_stub
        mmpa_stub
        runtime_stub
        error_manager_stub
        msprof_headers
        GTest::gtest GTest::gtest_main
        GTest::gmock)

include(CTest)
enable_testing()



