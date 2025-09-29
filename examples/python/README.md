## 目录

- [样例介绍](#样例介绍)
- [目录结构](#目录结构)
- [环境准备](#环境准备)
- [样例运行](#样例运行)

## 样例介绍

功能：通过LLM-DataDist接口实现分离部署场景下KvCache的管理功能。

## 目录结构

```
├── python
|   ├── pull_blocks_sample.py
|   ├── pull_blocks_xpyd_sample.py
|   ├── pull_cache_sample.py
|   ├── pull_from_cache_to_blocks.py
|   ├── push_blocks_sample.py
|   ├── push_cache_sample.py
|   ├── switch_cache_sample.py
```

## 环境准备

代码中使用了torchair将kv_cache的tensor地址转为torch tensor并赋值，所以需要安装torch_npu相关包。

## 样例运行
以下所有用例运行均需正确设置Ascend环境变量，所有双机示例需尽量保证同步执行。

### 执行前准备
- 注：此步骤**并非对所有样例都是必须**，若非标注，则执行前无须做此准备
- 使用双机，在Prompt与Decoder的主机分别执行以下命令，查询该主机的device ip信息：
    ```
    for i in {0..7}; do hccn_tool -i $i -ip -g; done
    ```
    **注: 如果出现hccn_tool命令找不到的情况，可在CANN包安装目录下搜索hccn_tool，找到可执行文件执行。**
- 更改脚本中的device信息
    - 将PROMPT_IP_LIST中的device_ip修改为Prompt主机的各device_ip。
    - 将DECODER_IP_LIST中的device_ip修改为Decoder主机的各device_ip。
    - 两台机器脚本保持一致。

### 执行
- 执行pull cache样例程序，此样例程序展示了配置内存池场景下，使用allocate_cache，双向建链，并从远端pull_cache
    - 说明：
      本示例必须使用双机，参考[执行前准备](#执行前准备)

    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    python pull_cache_sample.py --device_id 0 --cluster_id 1
    # Decoder主机:
    python pull_cache_sample.py --device_id 0 --cluster_id 2
    ```
- 执行pull blocks样例程序，此样例程序使用torch自行申请内存，双向建链，并从远端pull_cache
    - 说明：
      本示例必须使用双机，参考[执行前准备](#执行前准备)

    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    python pull_blocks_sample.py --device_id 0 --cluster_id 1
    # Decoder主机:
    python pull_blocks_sample.py --device_id 0 --cluster_id 2
    ```
- 执行pull_from_cache_to_blocks样例程序：
    - 说明：
      本示例必须使用双机，参考[执行前准备](#执行前准备)
      
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    python pull_from_cache_to_blocks.py --device_id 0 --cluster_id 1
    # Decoder主机:
    python pull_from_cache_to_blocks.py --device_id 0 --cluster_id 2
    ```
- 执行push_blocks样例程序，此样例程序使用单侧建链方式，申请内存并注册blocks,  decoder发起建链并push blocks
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_blocks_sample.py --device_id 0 --role p --local_host_ip 10.170.10.0 --remote_host_ip 10.170.10.1
    # Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_blocks_sample.py --device_id 1 --role d --local_host_ip 10.170.10.1 --remote_host_ip 10.170.10.0
    ```
- 执行push_cache样例程序：此样例程序使用单侧建链方式，申请内存并注册cache,  decoder发起建链并push cache
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_cache_sample.py --device_id 0 --role p --local_host_ip 10.170.10.0 --remote_host_ip 10.170.10.1
    # Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python push_cache_sample.py --device_id 1 --role d --local_host_ip 10.170.10.1 --remote_host_ip 10.170.10.0
    ```
- 执行switch_role样例程序：此样例程序使用单侧建链方式，首先torch自行申请内存并注册blocks, decoder发起建链并pull blocks, 然后两侧切换角色, 并prompt发起建链， decoder进行push_blocks
    分别在Prompt主机与Decoder主机，执行样例程序：
    ```
    # Prompt主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python switch_role_sample.py --device_id 0 --role p --local_host_ip 10.170.10.0 --remote_host_ip 10.170.10.1
    # Decoder主机:
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python switch_role_sample.py --device_id 1 --role d --local_host_ip 10.170.10.1 --remote_host_ip 10.170.10.0
    ```
- 执行pull_blocks_xpyd样例程序：此样例程序支持xPyD测试场景，使用单侧建链方式，每个进程申请内存并注册blocks, 每个decoder和所有的prompt发起建链, 并pull blocks到本地，local_ip_port指定本地host ip和端口
  - 说明：
    此用例可在任意个主机上执行，无论prompt侧拉起多少个进程，decoder侧结尾的prompt_ip_list由prompt侧的所有{$local\_ip:port$}组成  
    prompt侧：   
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id 0 --role p --local_ip_port {$local\_ip_0:port_0$}  
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id 1 --role p --local_ip_port {$local\_ip_1:port_1$}  
    .  
    .  
    .  
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id n --role p --local_ip_port {$local\_ip_n:port_n$}  

    decoder侧：  
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id n + 1 --role d --local_ip_port {$local\_ip_{n+1}:port_{n+1}$} --remote_ip_port '{prompt_ip_list}'  
    GLOO_SOCKET_IFNAME=enp67s0f5 HCCL_INTRA_ROCE_ENABLE=1 python pull_blocks_xpyd_sample.py --device_id n + 2 --role d --local_ip_port {$local\_ip_{n+2}:port_{n+2}$} --remote_ip_port '{prompt_ip_list}'  
    .  
    .  
    .  
    其中 {prompt_ip_list}由 **所有prompt侧的{$local\_ip:port$}** 组成，之间用 **;** 连接  
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