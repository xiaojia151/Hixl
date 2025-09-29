# LLM-DataDist接口列表<a name="ZH-CN_TOPIC_0000002407891585"></a>

LLM-DataDist：大模型分布式集群和数据加速组件，提供了集群KV数据管理能力，以支持全量图和增量图分离部署。

-   支持的产品形态如下：
    -   Atlas 800I A2 推理产品/A200I A2 Box 异构组件。
    -   Atlas A3 训练系列产品/Atlas A3 推理系列产品，该场景下采用HCCS传输协议时，不支持Host内存作为远端Cache。

-   当前仅支持Python3.9与Python3.11。安装方法请参考Python官网[https://www.python.org/](https://www.python.org/)。
-   最大注册50GB的Device内存，20GB的Host内存。注册内存越大，占用的OS内存越多。

LLM-DataDist接口列表如下。

## LLM-DataDist<a name="section1983152244318"></a>

**表 1**  LLM-DataDist接口

<a name="table52841713164813"></a>
<table><thead align="left"><tr id="row1728513134484"><th class="cellrowborder" valign="top" width="37.519999999999996%" id="mcps1.2.3.1.1"><p id="p228561310481"><a name="p228561310481"></a><a name="p228561310481"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.480000000000004%" id="mcps1.2.3.1.2"><p id="p1428514137484"><a name="p1428514137484"></a><a name="p1428514137484"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row142855132487"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p16149739131210"><a name="p16149739131210"></a><a name="p16149739131210"></a><a href="LLMDataDist构造函数.md">LLMDataDist构造函数</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p class="msonormal" id="zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"><a name="zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"></a><a name="zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"></a>构造LLMDataDist。</p>
</td>
</tr>
<tr id="row15244124619485"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p16148123971210"><a name="p16148123971210"></a><a name="p16148123971210"></a><a href="init.md">init</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p id="p14609010148"><a name="p14609010148"></a><a name="p14609010148"></a>初始化LLMDataDist。</p>
</td>
</tr>
<tr id="row552416440482"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p8708193711219"><a name="p8708193711219"></a><a name="p8708193711219"></a><a href="finalize.md">finalize</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p class="msonormal" id="p638310518145"><a name="p638310518145"></a><a name="p638310518145"></a>释放LLMDataDist。</p>
</td>
</tr>
<tr id="row189281911134910"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p470612376125"><a name="p470612376125"></a><a name="p470612376125"></a><a href="link_clusters.md">link_clusters</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p class="msonormal" id="zh-cn_topic_0000001893731858_zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"><a name="zh-cn_topic_0000001893731858_zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"></a><a name="zh-cn_topic_0000001893731858_zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"></a>单边建链，由Client单侧发起建链。是Client还是Server与角色prompt或者decoder无关。设置listen_ip_info标识端口监听，即为Server端。</p>
</td>
</tr>
<tr id="row175770137493"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p870510375121"><a name="p870510375121"></a><a name="p870510375121"></a><a href="unlink_clusters.md">unlink_clusters</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p class="msonormal" id="zh-cn_topic_0000001893731798_zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"><a name="zh-cn_topic_0000001893731798_zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"></a><a name="zh-cn_topic_0000001893731798_zh-cn_topic_0000001481404214_zh-cn_topic_0000001488949573_zh-cn_topic_0000001357384997_zh-cn_topic_0000001312399929_p45666040"></a>单边断链，可以由Client单侧发起，通知Server进行断链；也可以Client和Server均发起强制断链，只清理本地链路。</p>
</td>
</tr>
<tr id="row1168518252918"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p18686825192"><a name="p18686825192"></a><a name="p18686825192"></a><a href="switch_role.md">switch_role</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p class="msonormal" id="p56863255916"><a name="p56863255916"></a><a name="p56863255916"></a>切换当前LLMDataDist的角色，同时可通过配置switch_options切换Client或者Server。</p>
</td>
</tr>
<tr id="row01701344112715"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p18170844112715"><a name="p18170844112715"></a><a name="p18170844112715"></a><a href="link.md">link</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p id="p12972184118283"><a name="p12972184118283"></a><a name="p12972184118283"></a>双边建链场景下，调用此接口通过建立通信域方式建链。</p>
</td>
</tr>
<tr id="row92684814274"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p32614818278"><a name="p32614818278"></a><a name="p32614818278"></a><a href="unlink.md">unlink</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p id="p1772585112814"><a name="p1772585112814"></a><a name="p1772585112814"></a>双边建链场景下，调用此接口进行断链。</p>
</td>
</tr>
<tr id="row584335052715"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p1184316503278"><a name="p1184316503278"></a><a name="p1184316503278"></a><a href="query_register_mem_status.md">query_register_mem_status</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p id="p1122025913283"><a name="p1122025913283"></a><a name="p1122025913283"></a>双边建链场景下，调用此接口查询注册内存状态。</p>
</td>
</tr>
<tr id="row8247946192718"><td class="cellrowborder" valign="top" width="37.519999999999996%" headers="mcps1.2.3.1.1 "><p id="p11247114612277"><a name="p11247114612277"></a><a name="p11247114612277"></a><a href="cache_manager.md">cache_manager</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.480000000000004%" headers="mcps1.2.3.1.2 "><p id="p14236116162918"><a name="p14236116162918"></a><a name="p14236116162918"></a>获取CacheManager实例。</p>
</td>
</tr>
</tbody>
</table>

## LLMConfig<a name="section15510113219494"></a>

**表 2**  LLMConfig接口

<a name="table3510133218492"></a>
<table><thead align="left"><tr id="row7511183218498"><th class="cellrowborder" valign="top" width="37.56%" id="mcps1.2.3.1.1"><p id="p11511123214497"><a name="p11511123214497"></a><a name="p11511123214497"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.44%" id="mcps1.2.3.1.2"><p id="p55111032104911"><a name="p55111032104911"></a><a name="p55111032104911"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row12511113213492"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p131119437493"><a name="p131119437493"></a><a name="p131119437493"></a><a href="LLMConfig构造函数.md">LLMConfig构造函数</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p6117437495"><a name="p6117437495"></a><a name="p6117437495"></a>构造LLMConfig。</p>
</td>
</tr>
<tr id="row165111332194912"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p7101443124910"><a name="p7101443124910"></a><a name="p7101443124910"></a><a href="generate_options.md">generate_options</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p8398131155119"><a name="p8398131155119"></a><a name="p8398131155119"></a>生成配置项字典。</p>
</td>
</tr>
<tr id="row1371712198222"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p179134318494"><a name="p179134318494"></a><a name="p179134318494"></a><a href="device_id.md">device_id</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p1456101135113"><a name="p1456101135113"></a><a name="p1456101135113"></a>设置当前进程Device ID，对应底层ge.exec.deviceId配置项。</p>
</td>
</tr>
<tr id="row5808121192220"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p781643154914"><a name="p781643154914"></a><a name="p781643154914"></a><a href="sync_kv_timeout.md">sync_kv_timeout</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p131692172510"><a name="p131692172510"></a><a name="p131692172510"></a>配置拉取kv等接口超时时间，对应底层llm.SyncKvCacheWaitTime配置项。</p>
</td>
</tr>
<tr id="row7126161417224"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p17711436494"><a name="p17711436494"></a><a name="p17711436494"></a><a href="ge_options.md">ge_options</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p11889721165117"><a name="p11889721165117"></a><a name="p11889721165117"></a>配置额外的GE配置项。</p>
</td>
</tr>
<tr id="row1951118326492"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p141034334910"><a name="p141034334910"></a><a name="p141034334910"></a><a href="listen_ip_info.md">listen_ip_info</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p162501367510"><a name="p162501367510"></a><a name="p162501367510"></a>PROMPT侧设置集群侦听信息，对应底层llm.listenIpInfo配置项。</p>
</td>
</tr>
<tr id="row487271218234"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p14872312132312"><a name="p14872312132312"></a><a name="p14872312132312"></a><a href="enable_cache_manager.md">enable_cache_manager</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p489814611249"><a name="p489814611249"></a><a name="p489814611249"></a>配置是否开启CacheManager模式，对应底层llm.EnableCacheManager配置项。需配置为True。</p>
</td>
</tr>
<tr id="row1447977182318"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p114801718234"><a name="p114801718234"></a><a name="p114801718234"></a><a href="mem_pool_cfg.md">mem_pool_cfg</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p59729882411"><a name="p59729882411"></a><a name="p59729882411"></a>在开启CacheManager场景下，配置内存池相关配置项。</p>
</td>
</tr>
<tr id="row131772198295"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p4177131919295"><a name="p4177131919295"></a><a name="p4177131919295"></a><a href="host_mem_pool_cfg.md">host_mem_pool_cfg</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p335102723512"><a name="p335102723512"></a><a name="p335102723512"></a>在开启CacheManager场景下，配置Host内存池相关配置项。</p>
</td>
</tr>
<tr id="row1673510168295"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p47366167293"><a name="p47366167293"></a><a name="p47366167293"></a><a href="enable_remote_cache_accessible.md">enable_remote_cache_accessible</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p13491717133019"><a name="p13491717133019"></a><a name="p13491717133019"></a>在开启CacheManager场景下，配置是否开启远端Cache可直接访问功能。</p>
</td>
</tr>
<tr id="row537254691617"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p36721540169"><a name="p36721540169"></a><a name="p36721540169"></a><a href="rdma_traffic_class.md">rdma_traffic_class</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p964412568159"><a name="p964412568159"></a><a name="p964412568159"></a>在开启CacheManager场景下，用于配置RDMA网卡的traffic class。</p>
</td>
</tr>
<tr id="row651104816169"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p0672135471616"><a name="p0672135471616"></a><a name="p0672135471616"></a><a href="rdma_service_level.md">rdma_service_level</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p189581212167"><a name="p189581212167"></a><a name="p189581212167"></a>在开启CacheManager场景下，用于配置RDMA网卡的service level。</p>
</td>
</tr>
<tr id="row163291402213"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p13292418224"><a name="p13292418224"></a><a name="p13292418224"></a><a href="local_comm_res.md">local_comm_res</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p3411482579"><a name="p3411482579"></a><a name="p3411482579"></a>在开启CacheManager场景下，用于配置本地通信资源。</p>
</td>
</tr>
<tr id="row12317204381412"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p9396175012146"><a name="p9396175012146"></a><a name="p9396175012146"></a><a href="link_total_time.md">link_total_time</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p9727142091013"><a name="p9727142091013"></a><a name="p9727142091013"></a>用于配置HCCL建链失败的总超时时间。</p>
</td>
</tr>
<tr id="row734534112148"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p13395950191420"><a name="p13395950191420"></a><a name="p13395950191420"></a><a href="link_retry_count.md">link_retry_count</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p85621531131018"><a name="p85621531131018"></a><a name="p85621531131018"></a>用于配置HCCL建链失败的重试次数。</p>
</td>
</tr>
</tbody>
</table>

## CacheManager<a name="section376649103417"></a>

**表 3**  CacheManager接口

<a name="table18761649123418"></a>
<table><thead align="left"><tr id="row17614499342"><th class="cellrowborder" valign="top" width="37.56%" id="mcps1.2.3.1.1"><p id="p87624920349"><a name="p87624920349"></a><a name="p87624920349"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.44%" id="mcps1.2.3.1.2"><p id="p19763499349"><a name="p19763499349"></a><a name="p19763499349"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row2216132105520"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1221672165510"><a name="p1221672165510"></a><a name="p1221672165510"></a><a href="CacheManager构造函数.md">CacheManager构造函数</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p1321762175513"><a name="p1321762175513"></a><a name="p1321762175513"></a>介绍CacheManager的构造函数。</p>
</td>
</tr>
<tr id="row6771249193419"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p114087919357"><a name="p114087919357"></a><a name="p114087919357"></a><a href="allocate_cache.md">allocate_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p13368186151011"><a name="p13368186151011"></a><a name="p13368186151011"></a>分配Cache，Cache分配成功后，会同时被cache_id与cache_keys引用，只有当这些引用都解除后，cache所占用的资源才会实际释放。</p>
</td>
</tr>
<tr id="row3771949163419"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p9406129173519"><a name="p9406129173519"></a><a name="p9406129173519"></a><a href="deallocate_cache.md">deallocate_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p8777591382"><a name="p8777591382"></a><a name="p8777591382"></a>释放Cache。</p>
<p id="p14335130135911"><a name="p14335130135911"></a><a name="p14335130135911"></a>如果该Cache在Allocate时关联了CacheKey，则实际的释放会延后到所有的CacheKey被拉取或执行了<a href="remove_cache_key.md">remove_cache_key</a>。</p>
</td>
</tr>
<tr id="row677134910344"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p17405129123512"><a name="p17405129123512"></a><a name="p17405129123512"></a><a href="remove_cache_key.md">remove_cache_key</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p14228121911388"><a name="p14228121911388"></a><a name="p14228121911388"></a>移除CacheKey。</p>
<p id="p192291419163817"><a name="p192291419163817"></a><a name="p192291419163817"></a>移除CacheKey后，该Cache将无法再被pull_cache拉取。</p>
</td>
</tr>
<tr id="row977144923416"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p840411910355"><a name="p840411910355"></a><a name="p840411910355"></a><a href="pull_cache.md">pull_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p9323153014382"><a name="p9323153014382"></a><a name="p9323153014382"></a>根据CacheKey，从对应的对端节点拉取到本地Cache。</p>
</td>
</tr>
<tr id="row17771549103412"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p9403697356"><a name="p9403697356"></a><a name="p9403697356"></a><a href="copy_cache.md">copy_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p21981251121018"><a name="p21981251121018"></a><a name="p21981251121018"></a>拷贝Cache。</p>
</td>
</tr>
<tr id="row7771149173420"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p24026973517"><a name="p24026973517"></a><a name="p24026973517"></a><a href="allocate_blocks_cache.md">allocate_blocks_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p152661574225"><a name="p152661574225"></a><a name="p152661574225"></a>PagedAttention场景下，分配多个blocks的Cache，Cache分配成功后，可通过<a href="deallocate_blocks_cache.md">deallocate_blocks_cache</a>释放内存。</p>
</td>
</tr>
<tr id="row137784963420"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p4401697355"><a name="p4401697355"></a><a name="p4401697355"></a><a href="deallocate_blocks_cache.md">deallocate_blocks_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p185591413121118"><a name="p185591413121118"></a><a name="p185591413121118"></a>PagedAttention场景下，释放<a href="allocate_blocks_cache.md">allocate_blocks_cache</a>申请的Cache。</p>
</td>
</tr>
<tr id="row1777149173420"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1140014912359"><a name="p1140014912359"></a><a name="p1140014912359"></a><a href="pull_blocks.md">pull_blocks</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p18766622111114"><a name="p18766622111114"></a><a name="p18766622111114"></a>PagedAttention场景下，根据BlocksCacheKey，通过block列表的方式从对端节点拉取Cache到本地Cache。</p>
</td>
</tr>
<tr id="row6774498348"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p2398109173517"><a name="p2398109173517"></a><a name="p2398109173517"></a><a href="copy_blocks.md">copy_blocks</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p1150173016113"><a name="p1150173016113"></a><a name="p1150173016113"></a>PagedAttention场景下，拷贝block。</p>
</td>
</tr>
<tr id="row7781549133416"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1539779183515"><a name="p1539779183515"></a><a name="p1539779183515"></a><a href="swap_blocks.md">swap_blocks</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p111461151171113"><a name="p111461151171113"></a><a name="p111461151171113"></a>对cpu_cache和npu_cache进行换入换出。</p>
</td>
</tr>
<tr id="row1462011102368"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p10620171013363"><a name="p10620171013363"></a><a name="p10620171013363"></a><a href="register_cache.md">register_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p12803163115111"><a name="p12803163115111"></a><a name="p12803163115111"></a>注册一个自行申请的内存。</p>
</td>
</tr>
<tr id="row592314142361"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p119233148369"><a name="p119233148369"></a><a name="p119233148369"></a><a href="register_blocks_cache.md">register_blocks_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p14747342192010"><a name="p14747342192010"></a><a name="p14747342192010"></a>PagedAttention场景下，调用此接口注册一个自行申请的内存。</p>
</td>
</tr>
<tr id="row151802916447"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p718010984412"><a name="p718010984412"></a><a name="p718010984412"></a><a href="transfer_cache_async.md">transfer_cache_async</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p027481610337"><a name="p027481610337"></a><a name="p027481610337"></a>异步分层传输Cache。</p>
</td>
</tr>
<tr id="row858015015502"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1458025018505"><a name="p1458025018505"></a><a name="p1458025018505"></a><a href="push_blocks.md">push_blocks</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p10237123865116"><a name="p10237123865116"></a><a name="p10237123865116"></a>PagedAttention场景下，根据BlocksCacheKey，通过block列表的方式从本地节点推送Cache到远端Cache。</p>
</td>
</tr>
<tr id="row8219165225010"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p921975275011"><a name="p921975275011"></a><a name="p921975275011"></a><a href="push_cache.md">push_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p74469115146"><a name="p74469115146"></a><a name="p74469115146"></a>根据CacheKey，从本地节点推送Cache到远端Cache。</p>
</td>
</tr>
<tr id="row1215015913919"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1015049133920"><a name="p1015049133920"></a><a name="p1015049133920"></a><a href="remap_registered_memory.md">remap_registered_memory</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p25691840403"><a name="p25691840403"></a><a name="p25691840403"></a>大模型推理过程中，如果发生内存UCE故障，即返回错误码ACL_ERROR_RT_DEVICE_MEM_ERROR，上层框架需要先判断发生该故障的内存是否为KV Cache内存，如果不是，请参考<span id="ph963712461518"><a name="ph963712461518"></a><a name="ph963712461518"></a>《Ascend Extension for PyTorch 自定义API参考》</span>中的torch_npu.npu.restart_device接口的说明获取并修复内存UCE的错误虚拟地址。如果是KV Cache内存，还需要再调用该接口修复注册给网卡的KV Cache内存。</p>
<p id="p118857544017"><a name="p118857544017"></a><a name="p118857544017"></a>本接口为预留接口，暂不支持。</p>
</td>
</tr>
<tr id="row194191425235"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p541972152310"><a name="p541972152310"></a><a name="p541972152310"></a><a href="unregister_cache.md">unregister_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p16212425235"><a name="p16212425235"></a><a name="p16212425235"></a>解除注册一个自行申请的内存。</p>
</td>
</tr>
</tbody>
</table>

## Cache<a name="section1458165610195"></a>

**表 4**  Cache接口

<a name="table19458125615194"></a>
<table><thead align="left"><tr id="row64591456191910"><th class="cellrowborder" valign="top" width="37.56%" id="mcps1.2.3.1.1"><p id="p345975651914"><a name="p345975651914"></a><a name="p345975651914"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.44%" id="mcps1.2.3.1.2"><p id="p16459145601915"><a name="p16459145601915"></a><a name="p16459145601915"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row1459115620194"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1840562602019"><a name="p1840562602019"></a><a name="p1840562602019"></a><a href="Cache构造函数.md">Cache构造函数</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p171041555192119"><a name="p171041555192119"></a><a name="p171041555192119"></a>构造Cache。</p>
</td>
</tr>
<tr id="row829171245617"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p132912128569"><a name="p132912128569"></a><a name="p132912128569"></a><a href="cache_id.md">cache_id</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p122912012125611"><a name="p122912012125611"></a><a name="p122912012125611"></a>获取Cache的id。</p>
</td>
</tr>
<tr id="row768411206569"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1368412016564"><a name="p1368412016564"></a><a name="p1368412016564"></a><a href="cache_desc.md">cache_desc</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p14655145705613"><a name="p14655145705613"></a><a name="p14655145705613"></a>获取Cache描述。</p>
</td>
</tr>
<tr id="row111306182565"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1813031813567"><a name="p1813031813567"></a><a name="p1813031813567"></a><a href="tensor_addrs.md">tensor_addrs</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p7447172125714"><a name="p7447172125714"></a><a name="p7447172125714"></a>获取Cache的地址。</p>
</td>
</tr>
<tr id="row94591456171912"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p5404142612205"><a name="p5404142612205"></a><a name="p5404142612205"></a><a href="create_cpu_cache.md">create_cpu_cache</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p142983510223"><a name="p142983510223"></a><a name="p142983510223"></a>创建cpu cache。</p>
</td>
</tr>
</tbody>
</table>

## LLMClusterInfo<a name="section112159586521"></a>

**表 5**  LLMClusterInfo接口

<a name="table132152058155219"></a>
<table><thead align="left"><tr id="row1021525815520"><th class="cellrowborder" valign="top" width="37.56%" id="mcps1.2.3.1.1"><p id="p122151558155216"><a name="p122151558155216"></a><a name="p122151558155216"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.44%" id="mcps1.2.3.1.2"><p id="p172151658145219"><a name="p172151658145219"></a><a name="p172151658145219"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row1721525865218"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p7275121210531"><a name="p7275121210531"></a><a name="p7275121210531"></a><a href="LLMClusterInfo构造函数.md">LLMClusterInfo构造函数</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p295595545314"><a name="p295595545314"></a><a name="p295595545314"></a>构造LLMClusterInfo。</p>
</td>
</tr>
<tr id="row14216135815218"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p11274012105318"><a name="p11274012105318"></a><a name="p11274012105318"></a><a href="remote_cluster_id.md">remote_cluster_id</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p183511110542"><a name="p183511110542"></a><a name="p183511110542"></a>设置对端集群ID。</p>
</td>
</tr>
<tr id="row102166588529"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p4273161218530"><a name="p4273161218530"></a><a name="p4273161218530"></a><a href="append_local_ip_info.md">append_local_ip_info</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p91221778548"><a name="p91221778548"></a><a name="p91221778548"></a>添加本地集群IP信息。</p>
</td>
</tr>
<tr id="row32164588527"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p192727126533"><a name="p192727126533"></a><a name="p192727126533"></a><a href="append_remote_ip_info.md">append_remote_ip_info</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p1392251175420"><a name="p1392251175420"></a><a name="p1392251175420"></a>添加远端集群IP信息。</p>
</td>
</tr>
</tbody>
</table>

## CacheTask<a name="section417392252418"></a>

**表 6**  CacheTask

<a name="table1602121318331"></a>
<table><thead align="left"><tr id="row2602141310336"><th class="cellrowborder" valign="top" width="37.56%" id="mcps1.2.3.1.1"><p id="p146029134339"><a name="p146029134339"></a><a name="p146029134339"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.44%" id="mcps1.2.3.1.2"><p id="p160211319337"><a name="p160211319337"></a><a name="p160211319337"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row1604191318338"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1560481316335"><a name="p1560481316335"></a><a name="p1560481316335"></a><a href="CacheTask构造函数.md">CacheTask构造函数</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p16043134331"><a name="p16043134331"></a><a name="p16043134331"></a>构造CacheTask。</p>
</td>
</tr>
<tr id="row26042137339"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1604171393310"><a name="p1604171393310"></a><a name="p1604171393310"></a><a href="synchronize.md">synchronize</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p56042133330"><a name="p56042133330"></a><a name="p56042133330"></a>等待所有层传输完成，并获取整体执行结果。</p>
</td>
</tr>
<tr id="row196042135334"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p17604171314337"><a name="p17604171314337"></a><a name="p17604171314337"></a><a href="get_results.md">get_results</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p4604111319338"><a name="p4604111319338"></a><a name="p4604111319338"></a>等待所有层传输完成，并获取每个TransferConfig对应执行结果。</p>
</td>
</tr>
</tbody>
</table>

## 其他<a name="section75364163542"></a>

**表 7**  其他

<a name="table0536101618549"></a>
<table><thead align="left"><tr id="row155361716195412"><th class="cellrowborder" valign="top" width="37.56%" id="mcps1.2.3.1.1"><p id="p13536141675418"><a name="p13536141675418"></a><a name="p13536141675418"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="62.44%" id="mcps1.2.3.1.2"><p id="p16537201616541"><a name="p16537201616541"></a><a name="p16537201616541"></a>简介</p>
</th>
</tr>
</thead>
<tbody><tr id="row6155326133814"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p14123162743820"><a name="p14123162743820"></a><a name="p14123162743820"></a><a href="LLMRole.md">LLMRole</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p91234274380"><a name="p91234274380"></a><a name="p91234274380"></a>LLMRole的枚举值。</p>
</td>
</tr>
<tr id="row731214613816"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p122623382262"><a name="p122623382262"></a><a name="p122623382262"></a><a href="RegisterMemStatus.md">RegisterMemStatus</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p182626380262"><a name="p182626380262"></a><a name="p182626380262"></a>RegisterMemStatus的枚举值。</p>
</td>
</tr>
<tr id="row114683443817"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p5391131082513"><a name="p5391131082513"></a><a name="p5391131082513"></a><a href="Placement.md">Placement</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p1049717237256"><a name="p1049717237256"></a><a name="p1049717237256"></a>CacheDesc的字段，表示cache所在的设备类型。</p>
</td>
</tr>
<tr id="row4537216135414"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1697012416548"><a name="p1697012416548"></a><a name="p1697012416548"></a><a href="CacheDesc.md">CacheDesc</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p56031913185513"><a name="p56031913185513"></a><a name="p56031913185513"></a>构造CacheDesc。</p>
</td>
</tr>
<tr id="row1031735614013"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p143171556114011"><a name="p143171556114011"></a><a name="p143171556114011"></a><a href="MemType.md">MemType</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p154024210161"><a name="p154024210161"></a><a name="p154024210161"></a>表示地址所在位置，通常作为<a href="MemInfo.md">MemInfo</a>的mem_type参数的类型。</p>
</td>
</tr>
<tr id="row1213945815405"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p513985814016"><a name="p513985814016"></a><a name="p513985814016"></a><a href="MemInfo.md">MemInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p45755372431"><a name="p45755372431"></a><a name="p45755372431"></a>构造MemInfo，通常在CacheManager的<a href="remap_registered_memory.md">remap_registered_memory</a>接口中作为参数类型使用。</p>
</td>
</tr>
<tr id="row953712164547"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p189693246542"><a name="p189693246542"></a><a name="p189693246542"></a><a href="CacheKey.md">CacheKey</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p3351142095517"><a name="p3351142095517"></a><a name="p3351142095517"></a>构造CacheKey。</p>
</td>
</tr>
<tr id="row199547341279"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p19955133417276"><a name="p19955133417276"></a><a name="p19955133417276"></a><a href="CacheKeyByIdAndIndex.md">CacheKeyByIdAndIndex</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p class="msonormal" id="p11989636101712"><a name="p11989636101712"></a><a name="p11989636101712"></a>构造CacheKeyByIdAndIndex，通常在CacheManager的<a href="pull_cache.md">pull_cache</a>、<a href="push_cache.md">push_cache</a>接口中作为参数类型使用。</p>
</td>
</tr>
<tr id="row16537171695410"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p15968182465415"><a name="p15968182465415"></a><a name="p15968182465415"></a><a href="BlocksCacheKey.md">BlocksCacheKey</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p628413251557"><a name="p628413251557"></a><a name="p628413251557"></a>PagedAttention场景下，构造BlocksCacheKey。</p>
</td>
</tr>
<tr id="row1128012419269"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p10112101875716"><a name="p10112101875716"></a><a name="p10112101875716"></a><a href="LayerSynchronizer.md">LayerSynchronizer</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p68621658593"><a name="p68621658593"></a><a name="p68621658593"></a>等待模型指定层执行完成，用户需要继承LayerSynchronizer并实现该接口。</p>
<p id="p20862205155919"><a name="p20862205155919"></a><a name="p20862205155919"></a>该接口会在执行<a href="transfer_cache_async.md">transfer_cache_async</a>时被调用，当该接口返回成功，则开始当前层cache的传输。</p>
</td>
</tr>
<tr id="row19832854399"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p2373521205718"><a name="p2373521205718"></a><a name="p2373521205718"></a><a href="TransferConfig.md">TransferConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p740441385918"><a name="p740441385918"></a><a name="p740441385918"></a>构造TransferConfig。</p>
</td>
</tr>
<tr id="row117001932114119"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p107001632174113"><a name="p107001632174113"></a><a name="p107001632174113"></a><a href="TransferWithCacheKeyConfig.md">TransferWithCacheKeyConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p17376205519434"><a name="p17376205519434"></a><a name="p17376205519434"></a>构造TransferWithCacheKeyConfig。</p>
</td>
</tr>
<tr id="row479991033917"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p52621214143917"><a name="p52621214143917"></a><a name="p52621214143917"></a><a href="LLMException.md">LLMException</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p1626317140398"><a name="p1626317140398"></a><a name="p1626317140398"></a>获取异常的错误码。错误码列表详见<a href="LLMStatusCode.md">LLMStatusCode</a>。</p>
</td>
</tr>
<tr id="row12637230102613"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p1563713011261"><a name="p1563713011261"></a><a name="p1563713011261"></a><a href="LLMStatusCode.md">LLMStatusCode</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p963743013268"><a name="p963743013268"></a><a name="p963743013268"></a>LLMStatusCode的枚举值。</p>
</td>
</tr>
<tr id="row181251356185720"><td class="cellrowborder" valign="top" width="37.56%" headers="mcps1.2.3.1.1 "><p id="p191251656105713"><a name="p191251656105713"></a><a name="p191251656105713"></a><a href="DataType.md">DataType</a></p>
</td>
<td class="cellrowborder" valign="top" width="62.44%" headers="mcps1.2.3.1.2 "><p id="p9125205635715"><a name="p9125205635715"></a><a name="p9125205635715"></a>DataType的枚举类。</p>
</td>
</tr>
</tbody>
</table>

