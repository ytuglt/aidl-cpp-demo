#include <binder/IServiceManager.h>
#include <binder/ProcessState.h>
#include <android-base/logging.h>
#include "com/example/ICalculator.h"

using namespace android;
using namespace com::example;

int main() {
    // 初始化日志
    android::base::InitLogging(nullptr, android::base::StderrLogger);
    
    LOG(INFO) << "Calculator Client starting...";
    
    // 初始化Binder进程状态
    sp<ProcessState> proc(ProcessState::self());
    
    // 获取ServiceManager
    sp<IServiceManager> sm = defaultServiceManager();
    
    // 获取Calculator服务
    sp<IBinder> binder = sm->getService(String16("calculator"));
    if (binder == nullptr) {
        LOG(ERROR) << "Failed to get calculator service";
        return -1;
    }
    
    // 转换为ICalculator接口
    sp<ICalculator> calculator = interface_cast<ICalculator>(binder);
    if (calculator == nullptr) {
        LOG(ERROR) << "Failed to cast to ICalculator interface";
        return -1;
    }
    
    LOG(INFO) << "Successfully connected to Calculator service";
    
    // 获取服务信息
    String16 info;
    binder::Status status = calculator->getServiceInfo(&info);
    if (status.isOk()) {
        LOG(INFO) << "Service Info: " << String8(info).string();
    } else {
        LOG(ERROR) << "Failed to get service info: " << status.toString8().string();
    }
    
    // 测试加法
    int32_t result;
    status = calculator->add(10, 20, &result);
    if (status.isOk()) {
        LOG(INFO) << "10 + 20 = " << result;
    } else {
        LOG(ERROR) << "Add failed: " << status.toString8().string();
    }
    
    // 测试减法
    status = calculator->subtract(50, 15, &result);
    if (status.isOk()) {
        LOG(INFO) << "50 - 15 = " << result;
    } else {
        LOG(ERROR) << "Subtract failed: " << status.toString8().string();
    }
    
    // 测试乘法
    status = calculator->multiply(6, 7, &result);
    if (status.isOk()) {
        LOG(INFO) << "6 * 7 = " << result;
    } else {
        LOG(ERROR) << "Multiply failed: " << status.toString8().string();
    }
    
    // 测试除法
    status = calculator->divide(100, 4, &result);
    if (status.isOk()) {
        LOG(INFO) << "100 / 4 = " << result;
    } else {
        LOG(ERROR) << "Divide failed: " << status.toString8().string();
    }
    
    // 测试除以0的错误处理
    status = calculator->divide(10, 0, &result);
    if (status.isOk()) {
        LOG(INFO) << "10 / 0 = " << result;
    } else {
        LOG(INFO) << "Expected error for division by zero: " << status.toString8().string();
    }
    
    LOG(INFO) << "Calculator Client exiting...";
    return 0;
}
