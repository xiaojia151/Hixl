# Copyright (c) 2024 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ======================================================================================================================

cmake_minimum_required(VERSION 3.7)
project(llm_datadist)
set(INC_DIR
        "${AIR_CODE_DIR}/inc/external"
        "${METADEF_DIR}/inc/external"
        "${CMAKE_CURRENT_LIST_DIR}"
        "${CMAKE_CURRENT_LIST_DIR}/link_mgr"
        "${CMAKE_CURRENT_LIST_DIR}/cache_mgr"
        "${CMAKE_CURRENT_LIST_DIR}/hccl"
        "${CMAKE_CURRENT_LIST_DIR}/common"
        "${CMAKE_CURRENT_LIST_DIR}/fsm"
        "${CMAKE_BINARY_DIR}/proto/graphengine_protos/"
        )
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

file(GLOB LLM_SRC_LIST
        "${CMAKE_CURRENT_LIST_DIR}/api/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/adxl/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/common/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/cache_mgr/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/link_mgr/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/hccl/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/fsm/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/utils/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/data_transfer/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/memory/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/memory/allocator/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/memory/config/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/memory/span/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/memory/type/*.cc"
        "${CMAKE_CURRENT_LIST_DIR}/memory/util/*.cc"
        )

message("llm_datadist utils: ${CMAKE_CURRENT_LIST_DIR}")
message("llm_datadist CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message("llm_datadist AIR_CODE_DIR: ${AIR_CODE_DIR}")

add_library(llm_datadist SHARED ${LLM_SRC_LIST})

target_include_directories(llm_datadist PRIVATE ${INC_DIR})

target_compile_options(llm_datadist PRIVATE
        -ftrapv
        -O2
        -fno-common
        -Wfloat-equal
        -Wall
        -Werror
        -Wextra)

target_link_libraries(llm_datadist PRIVATE
        $<BUILD_INTERFACE:intf_pub>
        $<BUILD_INTERFACE:slog_headers>
        $<BUILD_INTERFACE:mmpa_headers>
        $<BUILD_INTERFACE:hccl_headers>
        PUBLIC c_sec
        static_mmpa
        alog
        error_manager
        metadef # for acend string
        json
        runtime
        -ldl
        runtime_headers
        msprof_headers
        -O2 -fPIC -Wextra -Wfloat-equal
        )

set(INSTALL_LIBRARY_DIR lib)
install(TARGETS llm_datadist OPTIONAL
        EXPORT llm_datadist-targets
        LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR}
        RUNTIME DESTINATION ${INSTALL_LIBRARY_DIR})

