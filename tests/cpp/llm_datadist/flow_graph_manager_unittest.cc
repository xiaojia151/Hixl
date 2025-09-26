/* Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This file is a part of the CANN Open Software.
 * Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 * ===================================================================================================================*/

#include <vector>
#include <fstream>
#include <gtest/gtest.h>
#include "ge/ge_api_types.h"
#include "ge/ge_api.h"
#include "macro_utils/dt_public_scope.h"
#include "common/flow_graph_manager.h"
#include "inc/external/llm_datadist/llm_engine_types.h"
#include "llm_datadist/llm_error_codes.h"

using namespace ::testing;
using namespace llm;

namespace ge {
class FlowGraphManagerTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};
}  // namespace ge
