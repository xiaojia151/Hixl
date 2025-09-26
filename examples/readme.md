# C++用例

## 目录

- [样例介绍](#C++用例-样例介绍)
- [目录结构](#C++用例-目录结构)
- [环境要求](#C++用例-环境要求)
- [程序编译](#C++用例-程序编译)
- [样例运行](#C++用例-样例运行)

<a id="C++用例-样例介绍"></a>

## 样例介绍

功能：通过LLM-DataDist接口实现分离部署场景下KvCache管理功能。

<a id="C++用例-目录结构"></a>

## 目录结构

```
├── prompt_sample1.cpp               // sample1的prompt样例main函数
├── decoder_sample1.cpp              // sample1的decoder样例main函数
├── prompt_sample2.cpp               // sample2的prompt样例main函数
├── decoder_sample2.cpp              // sample2的decoder样例main函数
├── prompt_sample3.cpp               // sample3的prompt样例main函数
├── decoder_sample3.cpp              // sample3的decoder样例main函数
├── adxl_engine_sample1.cpp          // adxl_engine的sample1样例
├── adxl_engine_sample2.cpp         // adxl_engine的sample2样例
├── CMakeLists.txt                   // 编译脚本
```

<a id="C++用例-环境要求"></a>

## 环境要求

-   操作系统及架构：Euleros x86系统、Euleros aarch64系统
-   编译器：g++
-   芯片：Atlas 训练系列产品、Atlas 推理系列产品（配置Ascend 310P AI处理器）
-   python及依赖的库：python3.7.5
-   已完成昇腾AI软件栈在运行环境上的部署

<a id="C++用例-程序编译"></a>

## 程序编译

1. 修改CMakeLists.txt文件中的安装包路径

2. 执行如下命令进行编译。

   依次执行:

   ```
   mkdir build && cd build
   cmake .. && make
   ```

3. 编译结束后，在**build**目录下生成可执行文件**prompt_sample**, **decoder_sample**和**adxl_engine_sample**。

<a id="C++用例-样例运行"></a>

## 样例运行

### 1. prompt/decoder样例

 - 执行前准备：

    - 在Prompt与Decoder的主机分别执行以下命令，查询该主机的device ip信息
        ```
        for i in {0..7}; do hccn_tool -i $i -ip -g; done
        ```
        **注: 如果出现hccn_tool命令找不到的情况，可在CANN包安装目录下搜索hccn_tool，找到可执行文件执行**
 - 配置环境变量
    - 若运行环境上安装的“Ascend-cann-toolkit”包，环境变量设置如下：

        ```
        . ${HOME}/Ascend/ascend-toolkit/set_env.sh
        ```

        “$HOME/Ascend”请替换相关软件包的实际安装路径。

    - 若运行环境上安装的“CANN-XXX.run”包，环境变量设置如下：

        ```
        source ${HOME}/Ascend/latest/bin/setenv.bash
        ```

        “$HOME/Ascend”请替换相关软件包的实际安装路径。

 - 在运行环境执行可执行文件。


    (1) 执行sample1

    此样例介绍了libllm_datadist.so的decoder向prompt进行pull cache和pull blocks流程，其中link和pull的方向与角色无关，可以根据需求更改

    - 执行prompt_sample1, 参数为device_id、local_host_ip和remote_host_ip, 其中device_id为prompt要使用的device_id, local_host_ip为prompt所在host的ip, remote_host_ip为decoder所在host的ip，如:
        ```
        ./prompt_sample1 0 10.10.170.1
        ```

    - 执行decoder_sample1, 参数为device_id、local_host_ip和remote_host_ip, 其中device_id为decoder要使用的device_id, local_host_ip为decoder所在host的ip，remote_host_ip为prompt所在host的ip，如:
        ```
        ./decoder_sample1 2 10.170.10.2 10.170.10.1
        ```

    (2) 执行sample2

    此样例介绍了libllm_datadist.so的prompt向decoder进行push cache和push blocks流程，其中link和push的方向与角色无关，可以根据需求更改

    - 执行prompt_sample2, 参数为device_id与local_ip, 其中device_id为prompt要使用的device_id, local_ip为prompt所在host的ip，如:
        ```
        ./prompt_sample2 0 10.10.10.1 10.10.10.5
        ```

    - 执行decoder_sample2, 参数为device_id、local_ip与remote_ip, 其中device_id为decoder要使用的device_id, local_ip为decoder所在host的ip，remote_ip为prompt所在host的ip，如:
        ```
        ./decoder_sample2 4 10.10.10.5
        ```

    (3) 执行sample3

    此样例介绍了libllm_datadist.so的角色切换，并结合pull以及push使用流程

    - 执行prompt_sample3, 参数为device_id、local_host_ip和remote_host_ip, 其中device_id为prompt要使用的device_id, local_host_ip为prompt所在host的ip, remote_host_ip为decoder所在host的ip，如:
        ```
        ./prompt_sample3 0 10.10.170.1 10.170.10.2
        ```

    - 执行decoder_sample3, 参数为device_id、local_host_ip和remote_host_ip, 其中device_id为decoder要使用的device_id, local_host_ip为decoder所在host的ip，remote_host_ip为prompt所在host的ip，如:
        ```
        ./decoder_sample3 2 10.170.10.2 10.170.10.1

### 2. adxl_engine样例

  - 配置环境变量
    - 若运行环境上安装的“Ascend-cann-toolkit”包，环境变量设置如下：

        ```
        . ${HOME}/Ascend/ascend-toolkit/set_env.sh
        ```

        “$HOME/Ascend”请替换相关软件包的实际安装路径。

    - 若运行环境上安装的“CANN-XXX.run”包，环境变量设置如下：

        ```
        source ${HOME}/Ascend/latest/bin/setenv.bash
        ```

        “$HOME/Ascend”请替换相关软件包的实际安装路径。

  - 在运行环境执行可执行文件。

    (1) 执行sample1, client-server模式，h2d场景

    - 执行client adxl_engine_sample1, 参数为device_id、local engine和remote engine, 其中device_id为client要使用的device_id，如:
        ```
        HCCL_INTRA_ROCE_ENABLE=1 ./adxl_engine_sample1 0 10.10.10.0 10.10.10.1:16000
        ```

    - 执行server adxl_engine_sample1, 参数为device_id、local engine, 其中device_id为server要使用的device_id, 如:
        ```
        HCCL_INTRA_ROCE_ENABLE=1 ./adxl_engine_sample1 1 10.10.10.1:16000
        ```

    (2) 执行sample2, 均作为server，d2d场景

    - 执行server1 adxl_engine_sample2, 参数为device_id、local engine和remote engine, 其中device_id为当前engine要使用的device_id，如:
        ```
        HCCL_INTRA_ROCE_ENABLE=1 ./adxl_engine_sample2 0 10.10.10.0:16000 10.10.10.1:16001
        ```

    - 执行server2 adxl_engine_sample2, 参数为device_id、local engine和remote engine, 其中device_id为当前engine要使用的device_id, 如:
        ```
        HCCL_INTRA_ROCE_ENABLE=1 ./adxl_engine_sample2 1 10.10.10.1:16001 10.10.10.0:16000
        ```
    **注**：HCCL_INTRA_ROCE_ENABLE=1表示使用RDMA进行传输



# Python用例

## 目录

- [样例介绍](#Python用例-样例介绍)
- [目录结构](#Python用例-目录结构)
- [环境准备](#Python用例-环境准备)
- [样例运行](#Python用例-样例运行)

<a id="Python用例-样例介绍"></a>

## 样例介绍

功能：通过LLM-DataDist接口实现分离部署场景下KvCache的管理功能。

<a id="Python用例-目录结构"></a>

## 目录结构

```
├── pull_blocks_sample.py
├── pull_blocks_xpyd_sample.py
├── pull_cache_sample.py
├── pull_from_cache_to_blocks.py
├── push_blocks_sample.py
├── push_cache_sample.py
├── switch_cache_sample.py
```

<a id="Python用例-环境准备"></a>

## 环境准备

代码中使用了torchair将kv_cache的tensor地址转为torch tensor并赋值，所以需要安装torch_npu相关包。

<a id="Python用例-样例运行"></a>

## 样例运行
以下所有用例运行均需正确设置Ascend环境变量，所有双机示例需尽量保证同步执行。

- 执行前准备：
    - 本示例需要使用双机，在Prompt与Decoder的主机分别执行以下命令，查询该主机的device ip信息：
        ```
        for i in {0..7}; do hccn_tool -i $i -ip -g; done
        ```
        **注: 如果出现hccn_tool命令找不到的情况，可在CANN包安装目录下搜索hccn_tool，找到可执行文件执行。**
    - 更改脚本中的device信息
        - 将PROMPT_IP_LIST中的device_ip修改为Prompt主机的各device_ip。
        - 将DECODER_IP_LIST中的device_ip修改为Decoder主机的各device_ip。
        - 两台机器脚本保持一致。
- 执行pull cache样例程序，此样例程序展示了配置内存池场景下，使用allocate_cache，双向建链，并从远端pull_cache：
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    python pull_cache_sample.py --device_id 0 --cluster_id 1
    # Decoder主机:
    python pull_cache_sample.py --device_id 0 --cluster_id 2
    ```
- 执行pull blocks样例程序，此样例程序使用torch自行申请内存，双向建链，并从远端pull_cache：
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    python pull_blocks_sample.py --device_id 0 --cluster_id 1
    # Decoder主机:
    python pull_blocks_sample.py --device_id 0 --cluster_id 2
    ```
- 执行连续往非连续发送的样例程序：
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    python pull_from_cache_to_blocks.py --device_id 0 --cluster_id 1
    # Decoder主机:
    python pull_from_cache_to_blocks.py --device_id 0 --cluster_id 2
    ```
- push_blocks_sample.py：此样例程序使用单侧建链方式，申请内存并注册blocks,  decoder发起建链并push blocks
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_blocks_sample.py --device_id 0 --role p --local_host_ip 10.170.10.0 --remote_host_ip 10.170.10.1
    # Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_blocks_sample.py --device_id 1 --role d --local_host_ip 10.170.10.1 --remote_host_ip 10.170.10.0
    ```
- push_cache_sample.py：此样例程序使用单侧建链方式，申请内存并注册cache,  decoder发起建链并push cache
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_cache_sample.py --device_id 0 --role p --local_host_ip 10.170.10.0 --remote_host_ip 10.170.10.1
    # Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_cache_sample.py --device_id 1 --role d --local_host_ip 10.170.10.1 --remote_host_ip 10.170.10.0
    ```
- switch_role_sample.py：执行switch role样例程序，此样例程序使用单侧建链方式，首先torch自行申请内存并注册blocks,
    decoder发起建链并pull blocks, 然后两侧切换角色, 并prompt发起建链， decoder进行push_blocks，执行方式如下：
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python switch_role_sample.py --device_id 0 --role p --local_host_ip 10.170.10.0 --remote_host_ip 10.170.10.1
    # Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python switch_role_sample.py --device_id 1 --role d --local_host_ip 10.170.10.1 --remote_host_ip 10.170.10.0
    ```
- pull_blocks_xpyd_sample.py：此样例程序支持xPyD测试场景，使用单侧建链方式，每个进程申请内存并注册blocks, 每个decoder和所有的prompt发起建链, 并pull blocks到本地，local_ip_port指定本地host ip和端口，
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # 任意个Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id 0 --role p --local_ip_port 10.170.10.0:26000
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id 1 --role p --local_ip_port 10.170.10.0:26001
    # 任意个Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id 2 --role d --local_ip_port 10.170.10.0:26002 --remote_ip_port '10.170.10.0:26000;10.170.10.0:26001'
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id 3 --role d --local_ip_port 10.170.10.0:26003 --remote_ip_port '10.170.10.0:26000;10.170.10.0:26001'
    ```
**注**：**GLOO_SOCKET_IFNAME**为本地网卡名，可通过ifconfig查询；**HCCL_INTRA_ROCE_ENABLE=1**代表使用roce方式进行通信；