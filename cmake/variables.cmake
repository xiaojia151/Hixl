# ----------------------------------------------------------------------------
# This program is free software, you can redistribute it and/or modify.
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------

if ("$ENV{USER}" STREQUAL "root")
    set(ASCEND_DEFAULT_PATH /usr/local/Ascend)
else()
    set(ASCEND_DEFAULT_PATH $ENV{HOME}/Ascend)
endif()

if (NOT DEFINED ASCEND_INSTALL_PATH)
    if (DEFINED ENV{ASCEND_HOME_PATH})
        set(ASCEND_INSTALL_PATH $ENV{ASCEND_HOME_PATH})
    else()
        if (EXISTS ${ASCEND_DEFAULT_PATH}/ascend-toolkit/latest)
            set(ASCEND_INSTALL_PATH ${ASCEND_DEFAULT_PATH}/ascend-toolkit/latest)
        elseif (EXISTS ${ASCEND_DEFAULT_PATH}/latest)
            set(ASCEND_INSTALL_PATH ${ASCEND_DEFAULT_PATH}/latest)
        else()
            message(FATAL_ERROR "Please set ASCEND_INSTALL_PATH or env:ASCEND_HOME_PATH")
        endif()
    endif()
    message("auto detect ASCEND_INSTALL_PATH:${ASCEND_INSTALL_PATH}")
else()
    message("use defined ASCEND_INSTALL_PATH:${ASCEND_INSTALL_PATH}")
endif()

set(CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/cmake/modules
    ${CMAKE_MODULE_PATH}
)
message("CMAKE_MODULE_PATH:${CMAKE_MODULE_PATH}")

set(CMAKE_PREFIX_PATH
    ${ASCEND_INSTALL_PATH}
)
message("CMAKE_PREFIX_PATH:${CMAKE_PREFIX_PATH}")

if (NOT DEFINED CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX
        ${PROJECT_SOURCE_DIR}/output
    )
endif()
message("CMAKE_INSTALL_PREFIX:${CMAKE_INSTALL_PREFIX}")

if (NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_INSTALL_PREFIX
        ${PROJECT_SOURCE_DIR}/output
    )
endif()
message("CMAKE_INSTALL_PREFIX:${CMAKE_INSTALL_PREFIX}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE True)
set(INSTALL_LIBRARY_DIR lib)
set(INSTALL_INCLUDE_DIR include)
set(DXL_CODE_DIR ${PROJECT_SOURCE_DIR})
set(HI_PYTHON python3)
set(TARGET_SYSTEM_NAME "Linux")

