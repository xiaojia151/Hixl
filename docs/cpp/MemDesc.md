# MemDesc<a name="ZH-CN_TOPIC_0000002446623669"></a>

内存的描述信息

```
struct MemDesc {
  uintptr_t addr;
  size_t len;
  uint8_t reserved[128] = {};
}
```

