/**
 * This program is free software, you can redistribute it and/or modify.
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This file is a part of the CANN Open Software.
 * Licensed under CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <vector>
#include <cstdlib>
#include <gtest/gtest.h>
#include "slog/toolchain/slog.h"
#include "common/mem_utils.h"
#include "ge/ge_api_types.h"
#include "ge/ge_api.h"
#include "macro_utils/dt_public_scope.h"
#include "common/llm_inner_types.h"
#include "common/llm_ge_api.h"
#include "llm_datadist/llm_engine_types.h"
#include "meta_flow_func_stub.h"
#include "meta_multi_flow_func_stub.h"
#include "macro_utils/dt_public_unscope.h"
#include "llm_test_helper.h"

using namespace std;
using namespace ::testing;
namespace FlowFunc {
namespace {
constexpr uint64_t kInvalidReqId = UINT64_MAX;
constexpr uint64_t kInvalidPrefixId = UINT64_MAX;
class GeApiStub : public llm::GeApi {
 public:
  ge::Status Initialize(const std::map<ge::AscendString, ge::AscendString> &options) override {
    LLMLOGI("Stub Initialize");
    return ge::SUCCESS;
  }
  ge::Status Finalize() override {
    LLMLOGI("Stub Finalize");
    return ge::SUCCESS;
  }
  ge::Status AddGraph(uint32_t graph_id, const ge::Graph &graph,
                      const std::map<ge::AscendString, ge::AscendString> &options) override {
    LLMLOGI("Stub AddGraph");
    return ge::SUCCESS;
  }
  ge::Status BuildGraph(uint32_t graph_id, const std::vector<ge::Tensor> &inputs) override {
    LLMLOGI("Stub FetchDataFlowGraph");
    return ge::SUCCESS;
  }
  ge::Status FeedDataFlowGraph(uint32_t graph_id, const std::vector<uint32_t> &indices,
                               const std::vector<ge::Tensor> &inputs, const ge::DataFlowInfo &info,
                               int32_t timeout) override {
    if (inputs.size() != indices.size()) {
      return ge::FAILED;
    }
    LLMLOGI("Stub FeedDataFlowGraph");
    return ge::SUCCESS;
  }
  ge::Status FetchDataFlowGraph(uint32_t graph_id, const std::vector<uint32_t> &indexes,
                                std::vector<ge::Tensor> &outputs, ge::DataFlowInfo &info, int32_t timeout) override {
    if (indexes[0] == UINT32_MAX) {
      return ge::FAILED;
    }
    LLMLOGI("Stub FetchDataFlowGraph");
    return ge::SUCCESS;
  }
};
}  // namespace

class LLMFlowFuncUTest : public ::testing::Test {
 protected:
  void SetUp() override {
    llm::GeApi::instance_.reset(new GeApiStub());
  }

  void TearDown() override {}
};

TEST_F(LLMFlowFuncUTest, HandleDecoderRecvFinishFuncTest) {
  auto func_ptr = FuncMap::GetInstance().GetFlowFunc("decoder_recv_finish_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<FlowFunc::MetaFlowFunc> obj_ptr = func_ptr();
  EXPECT_EQ(obj_ptr->Init(), FLOW_FUNC_SUCCESS);

  MetaContextChild meta_context;
  obj_ptr->context_ = &meta_context;
  std::vector<std::shared_ptr<FlowMsg>> inputMsgs{{nullptr}};
  int32_t ret = obj_ptr->Proc(inputMsgs);
  EXPECT_EQ(FLOW_FUNC_SUCCESS, ret);
}

TEST_F(LLMFlowFuncUTest, HandleDecoderFinishFuncTest) {
  auto func_ptr = FuncMap::GetInstance().GetFlowFunc("decoder_finish_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<FlowFunc::MetaFlowFunc> obj_ptr = func_ptr();
  EXPECT_EQ(obj_ptr->Init(), FLOW_FUNC_SUCCESS);

  MetaContextChild meta_context;
  obj_ptr->context_ = &meta_context;
  std::vector<std::shared_ptr<FlowMsg>> inputMsgs{{nullptr}};
  int32_t ret = obj_ptr->Proc(inputMsgs);
  EXPECT_EQ(FLOW_FUNC_SUCCESS, ret);
}

TEST_F(LLMFlowFuncUTest, handelDecoderOutTokenFuncTest) {
  auto func_ptr = FuncMap::GetInstance().GetFlowFunc("decoder_out_token_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<FlowFunc::MetaFlowFunc> obj_ptr = func_ptr();
  EXPECT_EQ(obj_ptr->Init(), FLOW_FUNC_SUCCESS);

  MetaContextChild meta_context;
  obj_ptr->context_ = &meta_context;
  std::vector<std::shared_ptr<FlowMsg>> inputMsgs{{nullptr}};
  int32_t ret = obj_ptr->Proc(inputMsgs);
  EXPECT_EQ(FLOW_FUNC_SUCCESS, ret);
}

TEST_F(LLMFlowFuncUTest, handelPromptTokenFuncTest) {
  auto func_ptr = FuncMap::GetInstance().GetFlowFunc("prompt_token_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<FlowFunc::MetaFlowFunc> obj_ptr = func_ptr();
  EXPECT_EQ(obj_ptr->Init(), FLOW_FUNC_SUCCESS);

  MetaContextChild meta_context;
  obj_ptr->context_ = &meta_context;
  std::vector<std::shared_ptr<FlowMsg>> inputMsgs{{nullptr}};
  int32_t ret = obj_ptr->Proc(inputMsgs);
  EXPECT_EQ(FLOW_FUNC_SUCCESS, ret);
}

TEST_F(LLMFlowFuncUTest, handelPromptNNFuncTest) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("_BuiltIn_prompt_execute_nn_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;
  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);

  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_prompt_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", true);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 2L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{16, 16});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{1L, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("cluster_ids", std::vector<int64_t>{1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("flow_send_out_idxs", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
  std::shared_ptr<MetaRunContextChild> meta_run_context = std::make_shared<MetaRunContextChild>();
  // test model execute func
  std::vector<std::shared_ptr<FlowMsg>> input_msgs;
  llm::LLMReqInfo req = {.req_id = 0, .prefix_id = kInvalidPrefixId};
  std::vector<int64_t> dims = {sizeof(req)/sizeof(uint8_t)};
  ge::TensorDesc req_tensor_desc(ge::Shape(dims), ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> req_tensor =
      std::make_shared<MockTensor>(req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor, 0);
  input_msgs.push_back(mock_flow_msg);
  input_msgs.push_back(mock_flow_msg);
  auto _BuiltIn_prompt_execute_nn_func = proc_func_list.find(AscendString("_BuiltIn_prompt_execute_nn_func"));
  auto ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // create flow msg for sync kv
  llm::LLMReq sync_kv_req;
  sync_kv_req.SetReqId(req.req_id);
  sync_kv_req.SetPrefixId(req.prefix_id);
  sync_kv_req.SetPromptClusterId(0);
  sync_kv_req.SetDecoderClusterId(1);
  ge::TensorDesc sync_kv_req_tensor_desc(ge::Shape({4}), ge::FORMAT_ND, ge::DT_UINT64);
  std::shared_ptr<MockTensor> sync_kv_req_tensor =
      std::make_shared<MockTensor>(sync_kv_req_tensor_desc, std::vector<int64_t>{4}, TensorDataType::DT_UINT64,
                                   static_cast<uint8_t *>(static_cast<void *>(&sync_kv_req)), sizeof(llm::LLMReq));
  std::shared_ptr<MockFlowMsg> sync_kv_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, sync_kv_req_tensor, 0);
  // test sync kv func
  auto _BuiltIn_prompt_kv_data_sync_func = proc_func_list.find(AscendString("_BuiltIn_prompt_kv_data_sync_func"));
  std::vector<std::shared_ptr<FlowMsg>> empty_input_msgs;
  ret = _BuiltIn_prompt_kv_data_sync_func->second(meta_run_context, empty_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_ERR_PARAM_INVALID);
  std::vector<std::shared_ptr<FlowMsg>> sync_kv_input_msgs;
  sync_kv_input_msgs.push_back(sync_kv_flow_msg);
  ret = _BuiltIn_prompt_kv_data_sync_func->second(meta_run_context, sync_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // test clean kv func
  auto _BuiltIn_prompt_kv_data_clean_func = proc_func_list.find(AscendString("_BuiltIn_prompt_kv_data_clean_func"));
  ret = _BuiltIn_prompt_kv_data_clean_func->second(meta_run_context, empty_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_ERR_PARAM_INVALID);
  std::vector<std::shared_ptr<FlowMsg>> clean_kv_input_msgs;
  clean_kv_input_msgs.push_back(mock_flow_msg);
  ret = _BuiltIn_prompt_kv_data_clean_func->second(meta_run_context, clean_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // test not find kv
  ret = _BuiltIn_prompt_kv_data_sync_func->second(meta_run_context, sync_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
}

TEST_F(LLMFlowFuncUTest, AllocateKvCacheFailedTest) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("prompt_execute_nn_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;
  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);

  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_prompt_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", true);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 2L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{-1, 16});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{1L, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("cluster_ids", std::vector<int64_t>{1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("flow_send_out_idxs", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
  std::shared_ptr<MetaRunContextChild> meta_run_context = std::make_shared<MetaRunContextChild>();
  // test model execute func
  std::vector<std::shared_ptr<FlowMsg>> input_msgs;
  llm::LLMReqInfo req = {.req_id = 0, .prefix_id = kInvalidPrefixId};
  std::vector<int64_t> dims = {sizeof(req) / sizeof(uint8_t)};
  ge::TensorDesc req_tensor_desc(ge::Shape(dims), ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> req_tensor =
      std::make_shared<MockTensor>(req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor, 0);
  input_msgs.push_back(mock_flow_msg);
  input_msgs.push_back(mock_flow_msg);
  auto prompt_execute_nn_func = proc_func_list.find(AscendString("prompt_execute_nn_func"));
  auto ret = prompt_execute_nn_func->second(meta_run_context, input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
}

TEST_F(LLMFlowFuncUTest, handelPromptNNFuncFailedTest) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("prompt_execute_nn_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;
  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);

  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_prompt_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", true);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 2L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{16, 16});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{1L, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("cluster_ids", std::vector<int64_t>{1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("flow_send_out_idxs", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
  std::shared_ptr<FailedMetaRunContextChild> meta_run_context = std::make_shared<FailedMetaRunContextChild>();
  // test model execute func
  std::vector<std::shared_ptr<FlowMsg>> input_msgs;
  llm::LLMReqInfo req = {.req_id = kInvalidReqId, .prefix_id = 0};
  std::vector<int64_t> dims = {sizeof(req)/sizeof(uint8_t)};
  ge::TensorDesc req_tensor_desc(ge::Shape(dims), ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> req_tensor =
      std::make_shared<MockTensor>(req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor, 0);
  input_msgs.push_back(mock_flow_msg);
  input_msgs.push_back(mock_flow_msg);
  auto prompt_execute_nn_func = proc_func_list.find(AscendString("prompt_execute_nn_func"));
  auto ret = prompt_execute_nn_func->second(meta_run_context, input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
}

TEST_F(LLMFlowFuncUTest, handelDecoderNNFuncTest) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("_BuiltIn_execute_flow_model_proc");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;

  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);
  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_decoder_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", true);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 1L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{32, 32});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{1L, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);

  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
  std::shared_ptr<MetaRunContextChild> meta_run_context = std::make_shared<MetaRunContextChild>();
  std::vector<std::shared_ptr<FlowMsg>> input_msgs;
  llm::LLMReq req;
  req.SetReqId(1);
  req.SetPromptClusterId(0);
  req.SetDecoderClusterId(1);
  ge::TensorDesc req_tensor_desc(ge::Shape({4}), ge::FORMAT_ND, ge::DT_UINT64);
  std::shared_ptr<MockTensor> req_tensor =
      std::make_shared<MockTensor>(req_tensor_desc, std::vector<int64_t>{4}, TensorDataType::DT_UINT64,
                                   static_cast<uint8_t *>(static_cast<void *>(&req)), sizeof(llm::LLMReq));
  std::shared_ptr<MockFlowMsg> mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor, 0);

  std::vector<std::shared_ptr<FlowMsg>> empty_input_msgs;
  auto recv_kv_proc_func = proc_func_list.find(AscendString("_BuiltIn_sync_kv_cache_proc"));
  std::vector<std::shared_ptr<FlowMsg>> kv_input_msgs;
  kv_input_msgs.push_back(mock_flow_msg);
  auto ret = recv_kv_proc_func->second(meta_run_context, empty_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_ERR_PARAM_INVALID);
  ret = recv_kv_proc_func->second(meta_run_context, kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  ret = recv_kv_proc_func->second(meta_run_context, kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  LLMLOGD("before _BuiltIn_merge_kv_cache_proc");
  auto synchronize_kv_proc_func = proc_func_list.find(AscendString("_BuiltIn_merge_kv_cache_proc"));
  ret = synchronize_kv_proc_func->second(meta_run_context, empty_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_ERR_PARAM_INVALID);
  ret = synchronize_kv_proc_func->second(meta_run_context, kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);

  // test recv tensor null
  std::shared_ptr<MockFlowMsg> tmp_flow_msg = nullptr;
  std::vector<std::shared_ptr<FlowMsg>> null_kv_input_msgs;
  null_kv_input_msgs.push_back(tmp_flow_msg);
  ret = recv_kv_proc_func->second(meta_run_context, null_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);

  // test rtmemcpy failed
  ret = recv_kv_proc_func->second(meta_run_context, kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  ret = recv_kv_proc_func->second(meta_run_context, kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  setenv("CONSTANT_FOLDING_PASS", "mock_fail", 1);
  ret = synchronize_kv_proc_func->second(meta_run_context, kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
  unsetenv("CONSTANT_FOLDING_PASS");

  input_msgs.push_back(mock_flow_msg);
  input_msgs.push_back(mock_flow_msg);
  auto execute_flow_model_proc_func = proc_func_list.find(AscendString("_BuiltIn_execute_flow_model_proc"));
  ret = execute_flow_model_proc_func->second(meta_run_context, input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);

  // test recv tensor null
  std::shared_ptr<MockTensor> req_tensor1 = nullptr;
  std::shared_ptr<MockFlowMsg> mock_null_tensor_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor1, 0);
  std::vector<std::shared_ptr<FlowMsg>> kv_null_tensor_input_msgs;
  kv_null_tensor_input_msgs.push_back(mock_null_tensor_flow_msg);
  ret = recv_kv_proc_func->second(meta_run_context, kv_null_tensor_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);

  // test kv not exist
  req.SetReqId(0);
  std::shared_ptr<MockTensor> req_tensor2 =
      std::make_shared<MockTensor>(req_tensor_desc, std::vector<int64_t>{4}, TensorDataType::DT_UINT64,
                                   static_cast<uint8_t *>(static_cast<void *>(&req)), sizeof(llm::LLMReq));
  std::shared_ptr<MockFlowMsg> mock_flow_msg1 =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor2, 0);
  std::vector<std::shared_ptr<FlowMsg>> kv_input_msgs1;
  kv_input_msgs1.push_back(mock_flow_msg1);
  ret = recv_kv_proc_func->second(meta_run_context, kv_input_msgs1);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
}

TEST_F(LLMFlowFuncUTest, handelPromptNNFuncTest_PromptPrefix) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("_BuiltIn_prompt_execute_nn_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;
  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);

  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_prompt_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", true);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 2L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{16, 16});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{1L, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("cluster_ids", std::vector<int64_t>{1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("flow_send_out_idxs", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
  std::shared_ptr<MetaRunContextChild> meta_run_context = std::make_shared<MetaRunContextChild>();
  // 1. test prefix inference
  std::vector<std::shared_ptr<FlowMsg>> prefix_input_msgs;
  llm::LLMReqInfo prefix_req = {.req_id = kInvalidReqId, .prefix_id = 0};
  std::vector<int64_t> dims = {sizeof(prefix_req)/sizeof(uint8_t)};
  ge::TensorDesc prefix_req_tensor_desc(ge::Shape(dims), ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> prefix_req_tensor =
      std::make_shared<MockTensor>(prefix_req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&prefix_req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> prefix_mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, prefix_req_tensor, 0);
  prefix_input_msgs.push_back(prefix_mock_flow_msg);
  prefix_input_msgs.push_back(prefix_mock_flow_msg);
  auto _BuiltIn_prompt_execute_nn_func = proc_func_list.find(AscendString("_BuiltIn_prompt_execute_nn_func"));
  auto ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prefix_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // 2. test prefix inferece with repetitive prefix
  ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prefix_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
  // 3. test prompt inference with prefix
  std::vector<std::shared_ptr<FlowMsg>> prompt_input_msgs;
  llm::LLMReqInfo prompt_req = {.req_id = 1, .prefix_id = 0};
  ge::TensorDesc prompt_req_tensor_desc(ge::Shape({sizeof(prompt_req)/sizeof(uint8_t)}), ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> prompt_req_tensor =
      std::make_shared<MockTensor>(prompt_req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&prompt_req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> prompt_mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, prompt_req_tensor, 0);
  prompt_input_msgs.push_back(prompt_mock_flow_msg);
  prompt_input_msgs.push_back(prompt_mock_flow_msg);
  ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prompt_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // 4. test prompt inference with repetitive req
  ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prompt_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
  // 5. test prompt inference with not-exist prefix
  prompt_input_msgs.clear();
  llm::LLMReqInfo invalid_prefix_req = {.req_id = 2, .prefix_id = 2};
  ge::TensorDesc invalid_prefix_req_tensor_desc(ge::Shape({sizeof(invalid_prefix_req)/sizeof(uint8_t)}),
                                                ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> invalid_prefix_req_tensor =
      std::make_shared<MockTensor>(invalid_prefix_req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&invalid_prefix_req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> invalid_prefix_mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, invalid_prefix_req_tensor, 0);
  prompt_input_msgs.push_back(invalid_prefix_mock_flow_msg);
  prompt_input_msgs.push_back(invalid_prefix_mock_flow_msg);
  ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prompt_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
  // 6. test inference with invalid req id and invalid prefix id
  prompt_input_msgs.clear();
  llm::LLMReqInfo invalid_prompt_req = {.req_id = kInvalidReqId, .prefix_id = kInvalidPrefixId};
  ge::TensorDesc invalid_prompt_req_tensor_desc(ge::Shape({sizeof(invalid_prompt_req)/sizeof(uint8_t)}),
                                                ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> invalid_prompt_req_tensor =
      std::make_shared<MockTensor>(invalid_prefix_req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&invalid_prompt_req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> invalid_prompt_mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, invalid_prompt_req_tensor, 0);
  prompt_input_msgs.push_back(invalid_prompt_mock_flow_msg);
  prompt_input_msgs.push_back(invalid_prompt_mock_flow_msg);
  ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prompt_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
  // 7. test clean kv func for prefix
  auto _BuiltIn_prompt_kv_data_clean_func = proc_func_list.find(AscendString("_BuiltIn_prompt_kv_data_clean_func"));
  std::vector<std::shared_ptr<FlowMsg>> clean_kv_input_msgs;
  clean_kv_input_msgs.push_back(prefix_mock_flow_msg);
  ret = _BuiltIn_prompt_kv_data_clean_func->second(meta_run_context, clean_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // 8. test clean kv func with invalid req
  clean_kv_input_msgs.clear();
  clean_kv_input_msgs.push_back(invalid_prompt_mock_flow_msg);
  ret = _BuiltIn_prompt_kv_data_clean_func->second(meta_run_context, clean_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
}

TEST_F(LLMFlowFuncUTest, handelPromptNNFuncTest_PromptPrefix_NotNeedSetOutput) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("_BuiltIn_prompt_execute_nn_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;
  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);

  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_prompt_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", false);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 2L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{16, 16});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{1L, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("cluster_ids", std::vector<int64_t>{1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("flow_send_out_idxs", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
  std::shared_ptr<MetaRunContextChild> meta_run_context = std::make_shared<MetaRunContextChild>();
  // 1. test prefix inference with need_set_output = false
  std::vector<std::shared_ptr<FlowMsg>> prefix_input_msgs;
  llm::LLMReqInfo prefix_req = {.req_id = kInvalidReqId, .prefix_id = 0};
  std::vector<int64_t> dims = {sizeof(prefix_req)/sizeof(uint8_t)};
  ge::TensorDesc prefix_req_tensor_desc(ge::Shape(dims), ge::FORMAT_ND, ge::DT_UINT8);
  std::shared_ptr<MockTensor> prefix_req_tensor =
      std::make_shared<MockTensor>(prefix_req_tensor_desc, dims, TensorDataType::DT_UINT8,
                                   static_cast<uint8_t *>(static_cast<void *>(&prefix_req)), sizeof(llm::LLMReqInfo));
  std::shared_ptr<MockFlowMsg> prefix_mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, prefix_req_tensor, 0);
  prefix_input_msgs.push_back(prefix_mock_flow_msg);
  prefix_input_msgs.push_back(prefix_mock_flow_msg);
  auto _BuiltIn_prompt_execute_nn_func = proc_func_list.find(AscendString("_BuiltIn_prompt_execute_nn_func"));
  auto ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, prefix_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
  // 2. test prefix inferece with invalid inputs
  std::vector<std::shared_ptr<FlowMsg>> invalid_input_msgs;
  invalid_input_msgs.push_back(prefix_mock_flow_msg);
  ret = _BuiltIn_prompt_execute_nn_func->second(meta_run_context, invalid_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_FAILED);
  // 3. test clean kv func for prefix
  auto _BuiltIn_prompt_kv_data_clean_func = proc_func_list.find(AscendString("_BuiltIn_prompt_kv_data_clean_func"));
  std::vector<std::shared_ptr<FlowMsg>> clean_kv_input_msgs;
  clean_kv_input_msgs.push_back(prefix_mock_flow_msg);
  ret = _BuiltIn_prompt_kv_data_clean_func->second(meta_run_context, clean_kv_input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
}

TEST_F(LLMFlowFuncUTest, handelPromptResultFuncTest_Success) {
  auto func_ptr = FuncMap::GetInstance().GetFlowFunc("handle_prompt_result_func");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<FlowFunc::MetaFlowFunc> obj_ptr = func_ptr();
  EXPECT_EQ(obj_ptr->Init(), FLOW_FUNC_SUCCESS);
  MetaContextChild meta_context;
  obj_ptr->context_ = &meta_context;
  std::vector<std::shared_ptr<FlowMsg>> inputMsgs{{nullptr}};
  int32_t ret = obj_ptr->Proc(inputMsgs);
  EXPECT_EQ(FLOW_FUNC_SUCCESS, ret);
}

TEST_F(LLMFlowFuncUTest, InitPostprocessModel_ParamCheckFailed) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("execute_flow_model_proc");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;

  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);
  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_decoder_modelpp_";
  params->SetInitParam("depend_key", depend_key);
  params->SetInitParam("need_set_output", true);
  params->SetInitParam("kv_size", 1L);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{32, 32});
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{7, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);

  params->SetInitParam("postprocess_external_in_num", int64_t{1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);

  params->SetInitParam("postprocess_depend_key", AscendString("invoke_postprocess_modelpp_0"));
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_PARAM_INVALID);

  params->SetInitParam("postprocess_output_indices", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);
}

TEST_F(LLMFlowFuncUTest, handelDecoderNNFuncTest_WithPostprocess) {
  auto func_ptr = FlowFuncManager::GetInstance().GetMultiFlowFunc("execute_flow_model_proc");
  EXPECT_NE(func_ptr, nullptr);
  std::shared_ptr<MetaMultiFunc> multi_func_object = std::make_shared<MetaMultiFunc>();
  std::map<AscendString, PROC_FUNC_WITH_CONTEXT> proc_func_list;

  EXPECT_EQ(func_ptr(multi_func_object, proc_func_list), FLOW_FUNC_SUCCESS);
  const std::shared_ptr<MetaParamsChild> params = std::make_shared<MetaParamsChild>();
  AscendString depend_key = "invoke_decoder_modelpp_";
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("depend_key", depend_key);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("need_set_output", true);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_size", 1L);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_shape", std::vector<int64_t>{32, 32});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("kv_in_data_type", ge::DataType::DT_FLOAT);
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_ERR_ATTR_NOT_EXITS);
  params->SetInitParam("nn_in_and_out_num", std::vector<int64_t>{7, 1});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);

  params->SetInitParam("postprocess_depend_key", AscendString("invoke_postprocess_modelpp_0"));
  params->SetInitParam("postprocess_external_in_num", int64_t{1});
  params->SetInitParam("postprocess_output_indices", std::vector<int64_t>{0});
  EXPECT_EQ(multi_func_object->Init(params), FLOW_FUNC_SUCCESS);

  std::shared_ptr<MetaRunContextChild> meta_run_context = std::make_shared<MetaRunContextChild>();

  llm::LLMReq req;
  req.SetReqId(1);
  req.SetPromptClusterId(0);
  req.SetDecoderClusterId(1);
  ge::TensorDesc req_tensor_desc(ge::Shape({4}), ge::FORMAT_ND, ge::DT_UINT64);
  std::shared_ptr<MockTensor> req_tensor =
      std::make_shared<MockTensor>(req_tensor_desc, std::vector<int64_t>{4}, TensorDataType::DT_UINT64,
                                   static_cast<uint8_t *>(static_cast<void *>(&req)), sizeof(llm::LLMReq));
  std::shared_ptr<MockFlowMsg> mock_flow_msg =
      std::make_shared<MockFlowMsg>(MsgType::MSG_TYPE_TENSOR_DATA, req_tensor, 0);
  std::vector<std::shared_ptr<FlowMsg>> input_msgs(7, mock_flow_msg);
  auto execute_flow_model_proc_func = proc_func_list.find(AscendString("execute_flow_model_proc"));
  auto ret = execute_flow_model_proc_func->second(meta_run_context, input_msgs);
  EXPECT_EQ(ret, FLOW_FUNC_SUCCESS);
}
}  // namespace FlowFunc
