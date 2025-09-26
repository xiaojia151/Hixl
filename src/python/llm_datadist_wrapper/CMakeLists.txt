# Copyright (c) 2024 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ======================================================================================================================

if (NOT ENABLE_TEST)
    add_library(llm_wrapper MODULE
            llm_wrapper.cc
            llm_tensor.cc
            llm_datadist_wrapper.cc)

    target_include_directories(llm_wrapper PRIVATE
            ${HI_PYTHON_INC}
            ${pybind11_INCLUDE_DIR}
            ${METADEF_DIR}/inc/external
            ${AIR_CODE_DIR}/inc/external
            ${AIR_CODE_DIR}/runtime/llm_datadist/v1
    )

    target_link_libraries(llm_wrapper PRIVATE
            $<BUILD_INTERFACE:intf_pub>
            $<BUILD_INTERFACE:slog_headers>
            $<BUILD_INTERFACE:mmpa_headers>
            $<BUILD_INTERFACE:hccl_headers>
            alog
            flow_graph
            llm_engine
    )

    set_target_properties(llm_wrapper
            PROPERTIES
            PREFIX ""
    )

    target_compile_definitions(llm_wrapper PRIVATE
            PYBIND11_NO_ASSERT_GIL_HELD_INCREF_DECREF
    )

    target_compile_options(llm_wrapper PRIVATE
            -O2
            -Xlinker -export-dynamic
    )

    target_link_options(llm_wrapper PRIVATE
            -s
    )

    add_library(llm_datadist_wrapper MODULE
            llm_wrapper_v2.cc
            llm_datadist_v2_wrapper.cc)

    target_include_directories(llm_datadist_wrapper PRIVATE
            ${HI_PYTHON_INC}
            ${pybind11_INCLUDE_DIR}
            ${METADEF_DIR}/inc/external
            ${AIR_CODE_DIR}/inc/external
            ${AIR_CODE_DIR}/runtime/llm_datadist/v2
    )

    target_link_libraries(llm_datadist_wrapper PRIVATE
            $<BUILD_INTERFACE:intf_pub>
            $<BUILD_INTERFACE:slog_headers>
            $<BUILD_INTERFACE:mmpa_headers>
            $<BUILD_INTERFACE:hccl_headers>
            alog
            llm_datadist
    )

    set_target_properties(llm_datadist_wrapper
            PROPERTIES
            PREFIX ""
    )

    target_compile_definitions(llm_datadist_wrapper PRIVATE
            PYBIND11_NO_ASSERT_GIL_HELD_INCREF_DECREF
    )

    target_compile_options(llm_datadist_wrapper PRIVATE
            -O2
            -Xlinker -export-dynamic
    )

    target_link_options(llm_datadist_wrapper PRIVATE
            -s
    )
endif ()
