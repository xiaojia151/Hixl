# Copyright (c) 2024 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ======================================================================================================================

if (CMAKE_BUILD_TYPE MATCHES GCOV)
    message("GCOV test mode")
    set(COMMON_COMPILE_OPTION
            -O0
            -g
            --coverage -fprofile-arcs -ftest-coverage
            -fsanitize=address -fsanitize=leak -fsanitize-recover=address
            )
    set(COV_COMPILE_OPTION
            --coverage -fprofile-arcs -ftest-coverage
            )
    if (TARGET_SYSTEM_NAME STREQUAL "Android")
        set(COMMON_LINK_OPTION
                -fsanitize=address -fsanitize=leak -fsanitize-recover=address
                -ldl -lgcov
                )
    else ()
        set(COMMON_LINK_OPTION
                -fsanitize=address -fsanitize=leak -fsanitize-recover=address
                -lrt -ldl -lgcov
                )
    endif ()
elseif(CMAKE_BUILD_TYPE MATCHES DT)
    message("Dump graph test mode")
    set(COMMON_COMPILE_OPTION -O0 -g)
    set(COV_COMPILE_OPTION ${COMMON_COMPILE_OPTION})
else ()
    if (TARGET_SYSTEM_NAME STREQUAL "Windows")
        if (CMAKE_CONFIGURATION_TYPES STREQUAL "Debug")
            set(COMMON_COMPILE_OPTION /MTd)
        else ()
            set(COMMON_COMPILE_OPTION /MT)
        endif ()

    else ()
        set(COMMON_COMPILE_OPTION -fvisibility=hidden -O2 -Werror -fno-common -Wextra -Wfloat-equal)
    endif ()

endif (CMAKE_BUILD_TYPE MATCHES GCOV)
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message("common compile options ${COMMON_COMPILE_OPTION}")
message("common link options ${COMMON_LINK_OPTION}")
