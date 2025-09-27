# ----------------------------------------------------------------------------
# This program is free software, you can redistribute it and/or modify.
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ----------------------------------------------------------------------------

include(cmake/function.cmake)
find_package_if_target_not_exists(slog MODULE REQUIRED)
find_package_if_target_not_exists(runtime MODULE REQUIRED)
find_package_if_target_not_exists(mmpa MODULE REQUIRED)
find_package_if_target_not_exists(msprof MODULE REQUIRED)
find_package_if_target_not_exists(hccl MODULE REQUIRED)
find_package_if_target_not_exists(runtime_static MODULE REQUIRED)
find_package_if_target_not_exists(ascendcl MODULE REQUIRED)
find_package_if_target_not_exists(metadef MODULE REQUIRED)