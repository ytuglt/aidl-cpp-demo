#ifndef AIDL_GENERATED_COM_EXAMPLE_BP_CALCULATOR_CALLBACK_H_
#define AIDL_GENERATED_COM_EXAMPLE_BP_CALCULATOR_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/example/ICalculatorCallback.h>

namespace com {

namespace example {

class BpCalculatorCallback : public ::android::BpInterface<ICalculatorCallback> {
public:
  explicit BpCalculatorCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCalculatorCallback() = default;
  ::android::binder::Status onResult(int32_t result) override;
  ::android::binder::Status onError(const ::android::String16& errorMsg) override;
};  // class BpCalculatorCallback

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_BP_CALCULATOR_CALLBACK_H_
