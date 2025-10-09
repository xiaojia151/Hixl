# LLM-DataDist接口参考（C++）
## 简介
-   LLM-DataDist：大模型分布式集群和数据加速组件，提供了集群KV数据管理能力，以支持全量图和增量图分离部署。
    -   LLM-DataDist相关接口存放在："INSTALL\_DIR\/include/llm\_datadist/llm\_datadist.h"。INSTALL\_DIR请替换为CANN软件安装后文件存储路径。若安装的Ascend-cann-toolkit软件包，以root安装举例，则安装后文件存储路径为：/usr/local/Ascend/ascend-toolkit/latest。
    -   LLM-DataDist接口对应的库文件是：libllm\_datadist.so。

-   ADXL：Ascend Device Transfer Library，提供高性能、零拷贝的点对点数据传输的能力，并通过简易API开放给用户。
    -   ADXL相关接口存放在："INSTALL\_DIR/include/adxl/adxl\_engine.h"。INSTALL\_DIR请替换为CANN软件安装后文件存储路径。若安装的Ascend-cann-toolkit软件包，以root安装举例，则安装后文件存储路径为：/usr/local/Ascend/ascend-toolkit/latest。
    -   ADXL接口对应的库文件是：libllm\_datadist.so。

支持的产品形态如下：

-   Atlas 800I A2 推理产品/A200I A2 Box 异构组件
-   Atlas A3 训练系列产品/Atlas A3 推理系列产品，该场景下采用HCCS传输协议时，不支持Host内存作为远端Cache。
## 接口列表
接口列表如下。
-  [LLM-DataDist接口](LLM-DataDist接口.md)
-  [LLM-DataDist数据结构](LLM-DataDist数据结构.md)
-  [LLM-DataDist错误码](LLM-DataDist错误码.md)
-   [ADXL接口](ADXL接口.md)
-  [ADXL数据结构](ADXL数据结构.md)
-  [ADXL错误码](ADXL错误码.md)
-   [不支持的接口](不支持的接口.md)

