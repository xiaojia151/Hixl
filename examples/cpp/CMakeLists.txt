# ----------------------------------------------------------------------------
# This program is free software, you can redistribute it and/or modify.
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.5.1)
project(llm_datadist_sample)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY TRUE)

if (DEFINED ENV{ASCEND_INSTALL_PATH})
    set(ASCEND_PATH $ENV{ASCEND_INSTALL_PATH})
else ()
    set(ASCEND_PATH /usr/local/Ascend/latest)
endif ()

set(INCLUDE_DIR ${ASCEND_PATH}/include)

set(common_compile_options
        --std=c++11
        -g
        -Wall
)

set(common_compile_definitions
        _GLIBCXX_USE_CXX11_ABI=0
)

add_executable(prompt_pull_cache_and_blocks "prompt_pull_cache_and_blocks.cpp")

target_compile_options(prompt_pull_cache_and_blocks PRIVATE
        ${common_compile_options}
)

target_compile_definitions(prompt_pull_cache_and_blocks PRIVATE
        ${common_compile_definitions}
)

target_include_directories(prompt_pull_cache_and_blocks PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(prompt_pull_cache_and_blocks PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(prompt_pull_cache_and_blocks PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(decoder_pull_cache_and_blocks "decoder_pull_cache_and_blocks.cpp")

target_compile_options(decoder_pull_cache_and_blocks PRIVATE
        ${common_compile_options}
)

target_compile_definitions(decoder_pull_cache_and_blocks PRIVATE
        ${common_compile_definitions}
)

target_include_directories(decoder_pull_cache_and_blocks PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(decoder_pull_cache_and_blocks PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(decoder_pull_cache_and_blocks PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(prompt_push_cache_and_blocks "prompt_push_cache_and_blocks.cpp")

target_compile_options(prompt_push_cache_and_blocks PRIVATE
        ${common_compile_options}
)

target_compile_definitions(prompt_push_cache_and_blocks PRIVATE
        ${common_compile_definitions}
)

target_include_directories(prompt_push_cache_and_blocks PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(prompt_push_cache_and_blocks PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(prompt_push_cache_and_blocks PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(decoder_push_cache_and_blocks "decoder_push_cache_and_blocks.cpp")

target_compile_options(decoder_push_cache_and_blocks PRIVATE
        ${common_compile_options}
)

target_compile_definitions(decoder_push_cache_and_blocks PRIVATE
        ${common_compile_definitions}
)

target_include_directories(decoder_push_cache_and_blocks PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(decoder_push_cache_and_blocks PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(decoder_push_cache_and_blocks PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(prompt_switch_roles "prompt_switch_roles.cpp")

target_compile_options(prompt_switch_roles PRIVATE
        ${common_compile_options}
)

target_compile_definitions(prompt_switch_roles PRIVATE
        ${common_compile_definitions}
)

target_include_directories(prompt_switch_roles PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(prompt_switch_roles PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(prompt_switch_roles PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(decoder_switch_roles "decoder_switch_roles.cpp")

target_compile_options(decoder_switch_roles PRIVATE
        ${common_compile_options}
)

target_compile_definitions(decoder_switch_roles PRIVATE
        ${common_compile_definitions}
)

target_include_directories(decoder_switch_roles PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(decoder_switch_roles PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(decoder_switch_roles PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(client_server_h2d "client_server_h2d.cpp")

target_compile_options(client_server_h2d PRIVATE
        ${common_compile_options}
)

target_compile_definitions(client_server_h2d PRIVATE
        ${common_compile_definitions}
)

target_include_directories(client_server_h2d PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(client_server_h2d PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(client_server_h2d PRIVATE
        llm_datadist
        graph
        ascendcl
)

add_executable(server_server_d2d "server_server_d2d.cpp")

target_compile_options(server_server_d2d PRIVATE
        ${common_compile_options}
)

target_compile_definitions(server_server_d2d PRIVATE
        ${common_compile_definitions}
)

target_include_directories(server_server_d2d PRIVATE
        ${INCLUDE_DIR}
        ${INCLUDE_DIR}/external/ge_common
)

target_link_directories(server_server_d2d PRIVATE
        ${ASCEND_PATH}/lib64
)

target_link_libraries(server_server_d2d PRIVATE
        llm_datadist
        graph
        ascendcl
)