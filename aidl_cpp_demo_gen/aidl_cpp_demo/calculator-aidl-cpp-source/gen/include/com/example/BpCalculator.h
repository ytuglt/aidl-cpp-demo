#ifndef AIDL_GENERATED_COM_EXAMPLE_BP_CALCULATOR_H_
#define AIDL_GENERATED_COM_EXAMPLE_BP_CALCULATOR_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <com/example/ICalculator.h>

namespace com {

namespace example {

class BpCalculator : public ::android::BpInterface<ICalculator> {
public:
  explicit BpCalculator(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCalculator() = default;
  ::android::binder::Status add(int32_t a, int32_t b, int32_t* _aidl_return) override;
  ::android::binder::Status subtract(int32_t a, int32_t b, int32_t* _aidl_return) override;
  ::android::binder::Status multiply(int32_t a, int32_t b, int32_t* _aidl_return) override;
  ::android::binder::Status divide(int32_t a, int32_t b, int32_t* _aidl_return) override;
  ::android::binder::Status getServiceInfo(::android::String16* _aidl_return) override;
};  // class BpCalculator

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_BP_CALCULATOR_H_
