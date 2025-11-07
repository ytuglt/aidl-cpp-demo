# AIDL C++ Demo 编译指南

## 编译步骤

### 1. 清理之前的编译产物（如果有）

```bash
cd frameworks/aidl_cpp_demo
rm -rf out/soong/.intermediates/frameworks/aidl_cpp_demo/
```

### 2. 先编译AIDL接口

AIDL接口需要先编译，这样会生成C++头文件供服务端和客户端使用。

```bash
# 方法1：单独编译AIDL接口
mm calculator-aidl-cpp

# 方法2：或者直接编译整个项目（会自动先编译AIDL）
mm
```

### 3. 编译服务端和客户端

如果上一步成功，继续编译：

```bash
# 编译服务端
mm calculator_service

# 编译客户端
mm calculator_client
```

## 常见编译问题及解决方案

### 问题1：找不到生成的头文件

**错误信息：**
```
error: no such file or directory: 'out/soong/.intermediates/frameworks/aidl_cpp_demo/calculator-aidl-cpp-source/gen/aidl/com/example/ICalculator.cpp'
```

**解决方案：**
1. 确保先编译AIDL接口：`mm calculator-aidl-cpp`
2. 检查生成的文件是否存在：
   ```bash
   ls out/soong/.intermediates/frameworks/aidl_cpp_demo/calculator-aidl-cpp/
   ```

### 问题2：头文件包含路径错误

**错误信息：**
```
cannot open source file "com/example/BnCalculator.h"
```

**解决方案：**
生成的头文件路径应该是：
```
out/soong/.intermediates/frameworks/aidl_cpp_demo/calculator-aidl-cpp/android_arm64_armv8-a_static/gen/include/
```

编译系统会自动处理这个路径。如果仍然报错，尝试：
```bash
# 完全清理后重新编译
make clean
m calculator-aidl-cpp calculator_service calculator_client
```

### 问题3：编译警告导致失败

如果看到 `-Werror` 导致警告变成错误，Android.bp已经移除了该选项。

## AIDL生成的文件说明

编译AIDL后会生成以下文件：

```
out/soong/.intermediates/frameworks/aidl_cpp_demo/calculator-aidl-cpp/
├── android_arm64_armv8-a_static/
│   └── gen/
│       ├── include/
│       │   └── com/example/
│       │       ├── ICalculator.h           # 接口类
│       │       ├── BpCalculator.h          # Proxy类（客户端）
│       │       ├── BnCalculator.h          # Stub类（服务端）
│       │       ├── ICalculatorCallback.h
│       │       ├── BpCalculatorCallback.h
│       │       └── BnCalculatorCallback.h
│       └── source/
│           └── aidl/com/example/
│               ├── ICalculator.cpp
│               └── ICalculatorCallback.cpp
```

## 验证编译结果

### 1. 检查编译产物

```bash
# 检查服务端二进制文件
ls -lh out/target/product/*/system/bin/calculator_service

# 检查客户端二进制文件
ls -lh out/target/product/*/system/bin/calculator_client
```

### 2. 推送到设备

```bash
adb root
adb remount
adb push out/target/product/*/system/bin/calculator_service /system/bin/
adb push out/target/product/*/system/bin/calculator_client /system/bin/
adb shell chmod 755 /system/bin/calculator_service
adb shell chmod 755 /system/bin/calculator_client
```

### 3. 运行测试

```bash
# 终端1：启动服务
adb shell
calculator_service

# 终端2：运行客户端
adb shell
calculator_client
```

## 调试技巧

### 1. 查看AIDL编译日志

```bash
# 查看详细编译输出
mm calculator-aidl-cpp -v
```

### 2. 检查依赖关系

```bash
# 列出模块依赖
m calculator_service --info
```

### 3. 单步调试编译过程

```bash
# 只编译不链接
mm calculator_service NINJA_ARGS="-n"
```

## 完整的一键编译脚本

创建 `build.sh`:

```bash
#!/bin/bash

set -e  # 遇到错误立即退出

echo "=== 开始编译AIDL C++ Demo ==="

echo "1. 清理旧的编译产物..."
rm -rf out/soong/.intermediates/frameworks/aidl_cpp_demo/

echo "2. 编译AIDL接口..."
mm calculator-aidl-cpp

echo "3. 编译服务端..."
mm calculator_service

echo "4. 编译客户端..."
mm calculator_client

echo "5. 检查编译结果..."
ls -lh out/target/product/*/system/bin/calculator_service
ls -lh out/target/product/*/system/bin/calculator_client

echo "=== 编译完成 ==="
echo "运行 './deploy.sh' 部署到设备"
```

创建 `deploy.sh`:

```bash
#!/bin/bash

set -e

echo "=== 部署到设备 ==="

adb root
adb remount

PRODUCT=$(ls out/target/product/ | head -1)

echo "1. 推送服务端..."
adb push out/target/product/$PRODUCT/system/bin/calculator_service /system/bin/

echo "2. 推送客户端..."
adb push out/target/product/$PRODUCT/system/bin/calculator_client /system/bin/

echo "3. 设置权限..."
adb shell chmod 755 /system/bin/calculator_service
adb shell chmod 755 /system/bin/calculator_client

echo "=== 部署完成 ==="
echo "运行测试："
echo "  adb shell calculator_service  # 终端1"
echo "  adb shell calculator_client   # 终端2"
```

使脚本可执行：
```bash
chmod +x build.sh deploy.sh
```

## 常用编译命令总结

```bash
# 清理编译
make clean

# 编译单个模块
mm <module_name>

# 编译并查看详细输出
mm <module_name> -v

# 只检查编译不实际构建
mm <module_name> NINJA_ARGS="-n"

# 编译所有依赖
m <module_name>

# 并行编译（加快速度）
mm -j8
