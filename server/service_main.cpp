#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <android-base/logging.h>
#include "CalculatorService.h"

using namespace android;
using namespace com::example;

int main() {
    // 初始化日志
    android::base::InitLogging(nullptr, android::base::StderrLogger);
    
    LOG(INFO) << "Calculator Service starting...";
    
    // 初始化Binder进程状态
    sp<ProcessState> proc(ProcessState::self());
    
    // 创建服务实例
    sp<CalculatorService> service = new CalculatorService();
    
    // 获取ServiceManager
    sp<IServiceManager> sm = defaultServiceManager();
    
    // 注册服务
    status_t ret = sm->addService(String16("calculator"), service);
    if (ret != OK) {
        LOG(ERROR) << "Failed to add service: " << ret;
        return -1;
    }
    
    LOG(INFO) << "Calculator Service registered successfully";
    
    // 启动线程池处理Binder请求
    ProcessState::self()->startThreadPool();
    
    // 当前线程加入线程池
    IPCThreadState::self()->joinThreadPool();
    
    LOG(INFO) << "Calculator Service exiting...";
    return 0;
}
