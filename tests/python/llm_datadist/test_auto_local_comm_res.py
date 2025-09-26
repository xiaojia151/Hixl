#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# -------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This file is a part of the CANN Open Software.
# Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ======================================================================================================================

import unittest
import time
from llm_datadist import *

class LlmAutoLocalCommResSt(unittest.TestCase):

    def setUp(self) -> None:
        print(f"Begin {self.__class__.__name__}.{self._testMethodName}")
        config = LlmConfig()
        config.device_id = 0
        config.rdma_service_level = 100
        config.rdma_traffic_class = 100
        config.listen_ip_info = "127.0.0.1:26008"
        config.local_comm_res = ''
        engine_options = config.generate_options()
        self.llm_datadist = LLMDataDist(LLMRole.PROMPT, 1)
        self.llm_datadist.init(engine_options)
        time.sleep(1) # wait listen
        self.has_exception = False

    def tearDown(self) -> None:
        print(f"End {self.__class__.__name__}.{self._testMethodName}")
        self.llm_datadist.finalize()

    def create_link_cluster(self):
        cluster = LLMClusterInfo()
        cluster.remote_cluster_id = 1
        cluster.append_local_ip_info("127.0.0.1", 26008)
        cluster.append_remote_ip_info("127.0.0.1", 26008)
        ret, rets = self.llm_datadist.link_clusters([cluster], 5000)
        self.assertEqual(ret, LLMStatusCode.LLM_SUCCESS)

    def test_unlink_cluster(self):
        self.create_link_cluster()
        cluster = LLMClusterInfo()
        cluster.remote_cluster_id = 1
        cluster.append_local_ip_info("127.0.0.1", 26008)
        cluster.append_remote_ip_info("127.0.0.1", 26008)
        ret, rets = self.llm_datadist.unlink_clusters([cluster], 5000)
        self.assertEqual(ret, LLMStatusCode.LLM_SUCCESS)
