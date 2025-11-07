#ifndef AIDL_GENERATED_COM_EXAMPLE_BN_CALCULATOR_CALLBACK_H_
#define AIDL_GENERATED_COM_EXAMPLE_BN_CALCULATOR_CALLBACK_H_

#include <binder/IInterface.h>
#include <com/example/ICalculatorCallback.h>

namespace com {

namespace example {

class BnCalculatorCallback : public ::android::BnInterface<ICalculatorCallback> {
public:
  explicit BnCalculatorCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCalculatorCallback

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_BN_CALCULATOR_CALLBACK_H_
