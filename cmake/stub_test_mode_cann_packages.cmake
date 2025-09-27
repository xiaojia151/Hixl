# Copyright (c) 2024 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ======================================================================================================================

# todo 整改后，不再因为XX_DT导致重新configure cmake工程，测试工程的打桩策略保持一致
# todo 整改后，gcov模式下不需要打桩的package,挪到`find_common_cann_packages`中
if (ENABLE_TEST)
    message(STATUS "GE DT mode")
    include(cmake/create_headers.cmake)
else ()
    message(WARNING "GCOV general mode")
endif ()
