# ops-dxl-dev

## 🔥Latest News

- [2025/10] ops-dxl-dev项目首次上线。

## 🚀概述
在大模型推理场景下，随着模型batch size的增大，Prefill阶段的性能会线性降低，Decode阶段会额外占用更多的内存。两阶段对资源的需求不同，部署在一起导致资源分配不均，成本居高不下。通过LLM-DataDist构建的大模型推理分离式框架有效地解决了该问题。在分离式框架中，将Prefill和Decode分别部署在不同规格和架构的集群中，提升了性能和资源利用效率，提升了大模型推理系统吞吐。

LLM-DataDist作为大模型分布式集群和数据管理组件，提供了高性能、零拷贝的点对点数据传输的能力，该能力通过简易的API开放给用户。LLM-DataDist利用昇腾集群多样化通信链路（RoCE/HCCS/UB），可实现跨实例和集群的高效KV Cache传输，支持与主流LLM推理框架vLLM等的集成，并可用于构筑分布式数据管理系统。LLM-DataDist功能主要包括：链路管理和缓存管理。

链路管理用于集群之间建链、断链，实现集群的动态扩缩的能力。
缓存管理用于管理KV Cache，提供PD之间点对点传输KV Cache的能力。

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
│  ├── adxl
│  └── llm_datadist
├── README.md
├── scripts                        # 脚本路径
│  └── package
├── src                            # 源码路径
│  ├── CMakeLists.txt
│  ├── llm_datadist
│  └── python
└── tests                          # 测试工程目录
```

## ⚡️快速入门

若您希望快速体验该组件的构建和样例执行，请访问如下文档获取简易教程。

- [构建](docs/build.md)：介绍组件的编译和安装，包括编译成功后利用tests进行本地验证。
- [样例执行](examples/README.md)：介绍如何端到端执行样例代码，包括C++和Python样例。

## 📖学习教程

若您希望深入了解组件的各个接口并修改源码，请访问如下文档获取详细教程。
- [C++接口](docs/cpp/README.md)：C++接口介绍。

- [Python接口](docs/python/README.md)：Python接口介绍。


## 📝相关信息

- [贡献指南](CONTRIBUTING.md)
- [安全声明](SECURITY.md)
- [许可证](LICENSE)