# 构建

## 编译

### 环境准备
本项目支持源码编译，在源码编译前，请根据如下步骤完成相关环境准备。

1. **安装依赖**

   以下所列为源码编译用到的依赖：  

   - GCC >= 7.5.0

   - Python3 >= 3.7.5

     如果需要本地查看tests覆盖率则需要额外安装coverage，并将Python3的bin路径添加到PATH环境变量中，命令示例如下：
     
     ```shell
     pip3 install coverage
     # 修改下面的PYTHON3_HOME为实际的PYTHON安装目录
     export PATH=$PATH:$PYTHON3_HOME/bin
     ```
     
   - CMake >= 3.14.0  (建议使用3.20.0版本)

     ```shell
     # Ubuntu/Debian操作系统安装命令示例如下，其他操作系统请自行安装
     sudo apt-get install cmake
     ```
   - ccache
     
     compile cache为编译器缓存优化工具，用于加快二次编译速度。
     
     ```shell
     # Ubuntu/Debian操作系统安装命令示例如下，其他操作系统请自行安装
     sudo apt-get install ccache
     ```

   - bash >= 5.1.16
     
     由于测试用例开启了地址消毒，代码中执行system函数会触发低版本的bash被地址消毒检查出内存泄露。
     
     ```shell
     # Ubuntu/Debian操作系统安装命令示例如下，其他操作系统请自行安装
     sudo apt-get install bash
     ```

2. **安装社区版CANN toolkit包**

    根据实际环境，下载对应`Ascend-cann-toolkit_${cann_version}_linux-${arch}.run`包，下载链接为[toolkit x86_64包](https://ascend-cann.obs.cn-north-4.myhuaweicloud.com/CANN/community/Ascend-cann-toolkit_8.3.RC1_linux-x86_64.run)、[toolkit aarch64包](https://ascend-cann.obs.cn-north-4.myhuaweicloud.com/CANN/community/Ascend-cann-toolkit_8.3.RC1_linux-aarch64.run)。
    
    ```bash
    # 确保安装包具有可执行权限
    chmod +x Ascend-cann-toolkit_${cann_version}_linux-${arch}.run
    # 安装命令
    ./Ascend-cann-toolkit_${cann_version}_linux-${arch}.run --full --force --install-path=${install_path}
    ```
    - \$\{cann\_version\}：表示CANN包版本号。
    - \$\{arch\}：表示CPU架构，如aarch64、x86_64。
    - \$\{install\_path\}：表示指定安装路径，默认安装在`/usr/local/Ascend`目录。
   

### 源码下载

开发者可通过如下命令下载本仓源码：
```bash
git clone https://gitcode.com/cann/ops-dxl-dev.git
```

### 配置环境变量
	
根据实际场景，选择合适的命令。

 ```bash
# 默认路径安装，以root用户为例（非root用户，将/usr/local替换为${HOME}）
source /usr/local/Ascend/ascend-toolkit/latest/set_env.sh
# 指定路径安装
# source ${install_path}/set_env.sh
 ```

### 编译执行

```bash
# 默认路径安装，root用户默认路径是/usr/local/Ascend/ascend-toolkit/latest，普通用户默认路径是${HOME}/Ascend/ascend-toolkit/latest
bash build.sh 
# 指定路径安装，安装路径是ascend_install_path
bash build.sh --ascend_install_path=${ascend_install_path}
```
成功编译后会在build_out目录下生成cann-ops-dxl\_${cann_version}_linux\_${arch}.run  
- ${cann_version}表示cann版本号。
- ${arch}表示表示CPU架构，如aarch64、x86_64。

## 本地验证(tests)
利用tests路径下的测试用例进行本地验证
```bash
# 默认路径安装，root用户默认路径是/usr/local/Ascend/ascend-toolkit/latest，普通用户默认路径是${HOME}/Ascend/ascend-toolkit/latest
bash tests/run_test.sh
# 指定路径安装，安装路径是ascend_install_path
bash tests/run_test.sh --ascend_install_path=${ascend_install_path}
```

## 安装

将[编译执行](#编译执行)环节生成的run包进行安装
```bash
# 如果需要指定安装路径则加上--install_path=${install_path}
./cann-ops-dxl_${cann_version}_linux_${arch}.run --full --quiet --pylocal
```
- --full 全量模式安装
- --quiet 静默安装，跳过人机交互环节
- --pylocal 安装python packages
- 更多安装选项请用--help选项查看

**安装完成后可参考[样例运行](../examples/README.md)尝试运行样例**