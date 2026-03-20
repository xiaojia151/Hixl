/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * This SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "engine_factory.h"

#include <set>
#include <string>

#include "nlohmann/json.hpp"
#include "acl/acl.h"
#include "hixl_engine.h"
#include "adxl/adxl_inner_engine.h"
#include "hixl/hixl_types.h"
#include "adxl/adxl_types.h"

namespace hixl {
namespace {
constexpr const char kConfigVersion[] = "1.3";
constexpr const char kSocA2[] = "Ascend910B1";

const static std::set<std::string> kV2Version = {
    "Ascend910_9391",
    "Ascend910_9381",
    "Ascend910_9392",
    "Ascend910_9382",
    "Ascend910_9372",
    "Ascend910_9362"
};

enum class LocalCommResConfigMode {
  kVersionOnly,
  kFullyConfigured,
  kInvalid
};

enum class SocType {
  kA2,
  kA3,
  kOther
};

Status ParseLocalCommResJson(const std::string &local_comm_res, nlohmann::json &j) {
  try {
    j = nlohmann::json::parse(local_comm_res);
    return SUCCESS;
  } catch (const nlohmann::json::exception &e) {
    HIXL_LOGE(PARAM_INVALID, "Parse local_comm_res failed, exception:%s", e.what());
    return PARAM_INVALID;
  }
}

Status GetVersionFromLocalCommRes(const std::string &local_comm_res, std::string &version) {
  nlohmann::json j;
  HIXL_CHK_STATUS_RET(ParseLocalCommResJson(local_comm_res, j), "ParseLocalCommResJson failed");
  if (!j.contains("version") || !j["version"].is_string()) {
    HIXL_LOGE(PARAM_INVALID, "local_comm_res missing valid version field");
    return PARAM_INVALID;
  }
  version = j["version"].get<std::string>();
  return SUCCESS;
}

LocalCommResConfigMode GetLocalCommResConfigMode(const std::string &local_comm_res) {
  nlohmann::json j;
  if (ParseLocalCommResJson(local_comm_res, j) != SUCCESS) {
    return LocalCommResConfigMode::kInvalid;
  }

  if (!j.contains("version")) {
    return LocalCommResConfigMode::kInvalid;
  }

  const bool has_net_instance_id = j.contains("net_instance_id") && j["net_instance_id"].is_string();
  const bool has_endpoint_list = j.contains("endpoint_list") &&
                                 j["endpoint_list"].is_array() &&
                                 !j["endpoint_list"].empty();

  if (j.size() == 1 && !has_net_instance_id && !has_endpoint_list) {
    return LocalCommResConfigMode::kVersionOnly;
  }

  if (has_net_instance_id && has_endpoint_list) {
    return LocalCommResConfigMode::kFullyConfigured;
  }

  return LocalCommResConfigMode::kInvalid;
}

SocType GetSocTypeByName(const std::string &soc_name) {
  if (soc_name == kSocA2) {
    return SocType::kA2;
  }

  if (kV2Version.find(soc_name) != kV2Version.end()) {
    return SocType::kA3;
  }

  return SocType::kOther;
}

Status GetSocType(SocType &soc_type) {
  const char *soc_name_cstr = aclrtGetSocName();
  HIXL_CHK_BOOL_RET_STATUS(soc_name_cstr != nullptr, FAILED, "aclrtGetSocName returned nullptr");
  std::string soc_name = soc_name_cstr;
  soc_type = GetSocTypeByName(soc_name);
  return SUCCESS;
}
}  // namespace

std::unique_ptr<Engine> EngineFactory::CreateEngine(const std::string local_engine,
                                                    const std::map<AscendString, AscendString> &options) {
  auto it = options.find(adxl::OPTION_LOCAL_COMM_RES);
  const char *local_comm_res_cstr = (it != options.end()) ? it->second.GetString() : nullptr;
  if (it == options.end() || local_comm_res_cstr == nullptr || local_comm_res_cstr[0] == '\0') {
    return std::make_unique<AdxlEngine>(AscendString(local_engine.c_str()));
  }

  const std::string local_comm_res = local_comm_res_cstr;
  std::string version;
  if (GetVersionFromLocalCommRes(local_comm_res, version) != SUCCESS) {
    HIXL_LOGW("Failed to parse version from local_comm_res, fallback to adxl");
    return std::make_unique<AdxlEngine>(AscendString(local_engine.c_str()));
  }

  const LocalCommResConfigMode mode = GetLocalCommResConfigMode(local_comm_res);
  SocType soc_type = SocType::kOther;
  if (GetSocType(soc_type) != SUCCESS) {
    HIXL_LOGW("GetSocType failed, fallback to adxl");
    return std::make_unique<AdxlEngine>(AscendString(local_engine.c_str()));
  }

  if (soc_type == SocType::kA2) {
    if (version == kConfigVersion) {
      return std::make_unique<HixlEngine>(AscendString(local_engine.c_str()));
    }
    return std::make_unique<AdxlEngine>(AscendString(local_engine.c_str()));
  }

  if (soc_type == SocType::kA3) {
    if (version == kConfigVersion) {
      return std::make_unique<HixlEngine>(AscendString(local_engine.c_str()));
    }
    return std::make_unique<AdxlEngine>(AscendString(local_engine.c_str()));
  }
  if (mode == LocalCommResConfigMode::kFullyConfigured && version == kConfigVersion) {
    return std::make_unique<HixlEngine>(AscendString(local_engine.c_str()));
  }

  HIXL_LOGW("Non-A2/A3 soc requires fully configured local_comm_res with version 1.3");
  return std::make_unique<AdxlEngine>(AscendString(local_engine.c_str()));
}
}  // namespace hixl