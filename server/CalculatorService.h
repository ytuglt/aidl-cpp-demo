#pragma once

#include <binder/Status.h>
#include "com/example/BnCalculator.h"

namespace com {
namespace example {

class CalculatorService : public BnCalculator {
public:
    CalculatorService() = default;
    virtual ~CalculatorService() = default;

    // 实现ICalculator接口
    ::android::binder::Status add(int32_t a, int32_t b, int32_t* _aidl_return) override;
    ::android::binder::Status subtract(int32_t a, int32_t b, int32_t* _aidl_return) override;
    ::android::binder::Status multiply(int32_t a, int32_t b, int32_t* _aidl_return) override;
    ::android::binder::Status divide(int32_t a, int32_t b, int32_t* _aidl_return) override;
    ::android::binder::Status getServiceInfo(::android::String16* _aidl_return) override;
};

} // namespace example
} // namespace com
