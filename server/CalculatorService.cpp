#include "CalculatorService.h"
#include <android-base/logging.h>

namespace com {
namespace example {

::android::binder::Status CalculatorService::add(int32_t a, int32_t b, int32_t* _aidl_return) {
    LOG(INFO) << "CalculatorService::add(" << a << ", " << b << ")";
    *_aidl_return = a + b;
    return ::android::binder::Status::ok();
}

::android::binder::Status CalculatorService::subtract(int32_t a, int32_t b, int32_t* _aidl_return) {
    LOG(INFO) << "CalculatorService::subtract(" << a << ", " << b << ")";
    *_aidl_return = a - b;
    return ::android::binder::Status::ok();
}

::android::binder::Status CalculatorService::multiply(int32_t a, int32_t b, int32_t* _aidl_return) {
    LOG(INFO) << "CalculatorService::multiply(" << a << ", " << b << ")";
    *_aidl_return = a * b;
    return ::android::binder::Status::ok();
}

::android::binder::Status CalculatorService::divide(int32_t a, int32_t b, int32_t* _aidl_return) {
    LOG(INFO) << "CalculatorService::divide(" << a << ", " << b << ")";
    
    if (b == 0) {
        return ::android::binder::Status::fromExceptionCode(
            ::android::binder::Status::EX_ILLEGAL_ARGUMENT,
            ::android::String8("Division by zero"));
    }
    
    *_aidl_return = a / b;
    return ::android::binder::Status::ok();
}

::android::binder::Status CalculatorService::getServiceInfo(::android::String16* _aidl_return) {
    LOG(INFO) << "CalculatorService::getServiceInfo()";
    *_aidl_return = ::android::String16("Calculator Service v1.0 - AIDL C++ Demo");
    return ::android::binder::Status::ok();
}

} // namespace example
} // namespace com
