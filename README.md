# hixl

## 🔥Latest News

- [2025/10] hixl项目首次上线。

## 🚀概述
HIXL（Huawei Xfer Library）是昇腾单边通信库，提供高性能、零拷贝的点对点数据传输能力，并通过简易API开放给用户。

<img src="docs/figures/hixl_architecture.png" alt="架构图">

在大模型推理场景下，随着模型batch size的增大，Prefill阶段的性能会线性降低，Decode阶段会额外占用更多的内存。两阶段对资源的需求不同，部署在一起导致资源分配不均，成本居高不下。大模型推理分离式框架有效地解决了该问题。在分离式框架中，将Prefill和Decode分别部署在不同规格和架构的集群中，提升了性能和资源利用效率，提升了大模型推理系统吞吐。同时也对KV Cache的高吞吐、低时延传输提出了挑战。

为了应对该挑战，HIXL应运而生，在提供高带宽、低时延的点对点通信的同时，也为上层推理框架提供支持。HIXL通过简易的API并利用昇腾集群多样化通信链路（RoCE/HCCS），可实现跨实例和集群的高效KV Cache传输，支持与主流LLM推理框架vLLM等的集成，并可用于构筑分布式数据管理系统。

主要功能包括：链路管理和缓存管理。
- 链路管理用于集群之间建链、断链，实现集群的动态扩缩的能力。
- 缓存管理用于内存的注册与传输， 内存类型可支持DDR和HBM。

## 🔍目录结构

```
├── build.sh                       # 项目工程编译脚本
├── cmake                          # 项目工程编译目录
├── CMakeLists.txt                 # 项目的CMakeList
├── docs                           # 项目文档介绍
│  ├── cpp                         # C++文档
│  └── python                      # Python文档
├── examples                       # 端到端样例开发和调用示例
│  ├── cpp                         # C++样例
│  ├── python                      # Python样例
├── include                        # 头文件
│  ├── hixl
│  └── llm_datadist
├── README.md
├── scripts                        # 脚本路径
│  └── package
├── src                            # 源码路径
│  ├── llm_datadist
│  └── python
└── tests                          # 测试工程目录
```

## ⚡️快速入门

若您希望快速体验该组件的构建和样例执行，请访问如下文档获取简易教程。

- [构建](docs/build.md)：介绍组件的编译和安装，包括编译成功后利用tests进行本地验证。
- [样例执行](examples/README.md)：介绍如何端到端执行样例代码，包括C++和Python样例。
- [开发指南](https://hiascend.com/document/redirect/CannCommunityLLMDatadistdev): 用于指导开发者如何使用HIXL接口实现集群间的数据传输，构筑大模型推理分离式框架。  

## 📖学习教程

若您希望深入了解组件的各个接口并修改源码，请访问如下文档获取详细教程。
- [C++接口](docs/cpp/README.md)：C++接口介绍。

- [Python接口](docs/python/README.md)：Python接口介绍。


## 📝相关信息

- [贡献指南](CONTRIBUTING.md)
- [安全声明](SECURITY.md)
- [许可证](LICENSE)