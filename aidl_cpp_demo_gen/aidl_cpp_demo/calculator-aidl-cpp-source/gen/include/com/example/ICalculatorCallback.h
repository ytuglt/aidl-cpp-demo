#ifndef AIDL_GENERATED_COM_EXAMPLE_I_CALCULATOR_CALLBACK_H_
#define AIDL_GENERATED_COM_EXAMPLE_I_CALCULATOR_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace com {

namespace example {

class ICalculatorCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CalculatorCallback)
  virtual ::android::binder::Status onResult(int32_t result) = 0;
  virtual ::android::binder::Status onError(const ::android::String16& errorMsg) = 0;
};  // class ICalculatorCallback

class ICalculatorCallbackDefault : public ICalculatorCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onResult(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onError(const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICalculatorCallbackDefault

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_I_CALCULATOR_CALLBACK_H_
