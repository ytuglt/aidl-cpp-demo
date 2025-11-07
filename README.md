# AIDL C++ Demo - Calculator Service

这是一个完整的AIDL C++示例，展示如何使用AIDL在C++中实现跨进程通信的服务端和客户端。

## 项目概述

本项目实现了一个简单的计算器服务，通过Binder IPC机制提供加减乘除四则运算功能。

### 主要特性

- ✅ 使用AIDL定义接口
- ✅ C++服务端实现
- ✅ C++客户端调用
- ✅ 错误处理（如除以零）
- ✅ 完整的Android.bp编译配置

## 目录结构

```
aidl_cpp_demo/
├── aidl/                          # AIDL接口定义
│   └── com/example/
│       ├── ICalculator.aidl       # 主服务接口
│       └── ICalculatorCallback.aidl # 回调接口（可选）
├── server/                        # 服务端实现
│   ├── CalculatorService.h        # 服务实现头文件
│   ├── CalculatorService.cpp      # 服务实现
│   └── service_main.cpp           # 服务主程序
├── client/                        # 客户端实现
│   └── client_main.cpp            # 客户端主程序
├── Android.bp                     # 编译配置文件
└── README.md                      # 本文档
```

## AIDL接口定义

### ICalculator.aidl

```java
package com.example;

interface ICalculator {
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);
    String getServiceInfo();
}
```

## AIDL自动生成的代码

当使用`aidl_interface`编译AIDL文件时，系统会自动生成以下C++代码：

### 生成的文件结构

```
out/soong/.intermediates/frameworks/aidl_cpp_demo/calculator-aidl-cpp/
├── com/example/
│   ├── ICalculator.h              # 接口头文件
│   ├── BpCalculator.h             # Proxy类（客户端使用）
│   ├── BnCalculator.h             # Stub类（服务端继承）
│   └── BnCalculator.cpp           # Stub类实现
```

### 关键类说明

1. **ICalculator**: 纯虚接口类，定义所有方法
2. **BpCalculator**: Proxy类，客户端使用，负责序列化参数并通过Binder发送
3. **BnCalculator**: Stub类，服务端继承，负责接收请求、反序列化参数、调用实现并返回结果

## 编译方法

### 1. 在Android源码树中编译

```bash
# 进入项目目录
cd frameworks/aidl_cpp_demo

# 编译服务端
mm calculator_service

# 编译客户端
mm calculator_client

# 或一次性编译所有
mm
```

### 2. 编译产物位置

```
out/target/product/<device>/system/bin/calculator_service
out/target/product/<device>/system/bin/calculator_client
```

## 运行方法

### 方法一：通过adb运行

```bash
# 1. 启动服务端（在一个终端）
adb shell
calculator_service

# 2. 运行客户端（在另一个终端）
adb shell
calculator_client
```

### 方法二：作为系统服务运行

创建init.rc配置文件 `calculator_service.rc`：

```rc
service calculator /system/bin/calculator_service
    class main
    user system
    group system
```

然后：

```bash
# 推送到设备
adb push calculator_service.rc /system/etc/init/

# 启动服务
adb shell start calculator
```

## 预期输出

### 服务端输出

```
Calculator Service starting...
Calculator Service registered successfully
CalculatorService::getServiceInfo()
CalculatorService::add(10, 20)
CalculatorService::subtract(50, 15)
CalculatorService::multiply(6, 7)
CalculatorService::divide(100, 4)
CalculatorService::divide(10, 0)
```

### 客户端输出

```
Calculator Client starting...
Successfully connected to Calculator service
Service Info: Calculator Service v1.0 - AIDL C++ Demo
10 + 20 = 30
50 - 15 = 35
6 * 7 = 42
100 / 4 = 25
Expected error for division by zero: Status(-8, EX_ILLEGAL_ARGUMENT): 'Division by zero'
Calculator Client exiting...
```

## 关键代码解析

### 1. 服务端实现

```cpp
// CalculatorService.h
class CalculatorService : public BnCalculator {
    // 继承BnCalculator（Stub类）
    Status add(int32_t a, int32_t b, int32_t* result) override;
    // ... 实现其他方法
};
```

### 2. 服务注册

```cpp
// service_main.cpp
sp<CalculatorService> service = new CalculatorService();
sp<IServiceManager> sm = defaultServiceManager();
sm->addService(String16("calculator"), service);
```

### 3. 客户端调用

```cpp
// client_main.cpp
sp<IBinder> binder = sm->getService(String16("calculator"));
sp<ICalculator> calculator = interface_cast<ICalculator>(binder);
calculator->add(10, 20, &result);
```

## AIDL与手动Binder的对比

| 特性 | 手动Binder | AIDL |
|------|-----------|------|
| 接口定义 | 手动编写C++接口类 | .aidl文件定义 |
| Proxy/Stub实现 | 手动实现 | 自动生成 |
| 序列化/反序列化 | 手动编写 | 自动处理 |
| 维护成本 | 高 | 低 |
| 类型支持 | 需要手动处理 | 内置丰富类型 |

## 支持的AIDL数据类型

### 基本类型
- `int`, `long`, `boolean`, `float`, `double`, `byte`
- `String`, `CharSequence`

### 复合类型
- `List`, `Map`
- `Parcelable`对象
- 自定义`parcelable`类型

### 特殊类型
- `FileDescriptor`
- `IBinder`

## 常见问题

### 1. 编译错误：找不到AIDL生成的头文件

**原因**：需要先编译AIDL接口

**解决**：
```bash
# 先编译AIDL接口
mm calculator-aidl-cpp
# 再编译服务端/客户端
mm calculator_service calculator_client
```

### 2. 运行时错误：service not found

**原因**：服务端未启动或注册失败

**解决**：
- 确认服务端正在运行
- 检查服务名称是否匹配（"calculator"）
- 查看logcat日志

### 3. SELinux权限问题

**解决**：添加SELinux策略
```
# calculator_service.te
type calculator_service, domain;
type calculator_service_exec, exec_type, file_type;

init_daemon_domain(calculator_service)
binder_use(calculator_service)
binder_service(calculator_service)
```

## 扩展功能建议

1. **添加回调机制**：使用ICalculatorCallback进行异步通知
2. **添加复杂数据类型**：定义parcelable对象传递复杂数据
3. **添加权限控制**：使用permission保护敏感接口
4. **添加死亡通知**：监听服务端崩溃
5. **添加oneway调用**：支持异步调用

## 参考资料

- [Android AIDL官方文档](https://source.android.com/docs/core/architecture/aidl/aidl-backends)
- [Binder机制详解](https://source.android.com/docs/core/architecture/hidl)
- Android源码：`frameworks/native/libs/binder`

## 许可证

本示例代码遵循Apache 2.0许可证。
