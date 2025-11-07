#ifndef AIDL_GENERATED_COM_EXAMPLE_I_CALCULATOR_H_
#define AIDL_GENERATED_COM_EXAMPLE_I_CALCULATOR_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace com {

namespace example {

class ICalculator : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Calculator)
  virtual ::android::binder::Status add(int32_t a, int32_t b, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status subtract(int32_t a, int32_t b, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status multiply(int32_t a, int32_t b, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status divide(int32_t a, int32_t b, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getServiceInfo(::android::String16* _aidl_return) = 0;
};  // class ICalculator

class ICalculatorDefault : public ICalculator {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status add(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status subtract(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status multiply(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status divide(int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getServiceInfo(::android::String16*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICalculatorDefault

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_I_CALCULATOR_H_
