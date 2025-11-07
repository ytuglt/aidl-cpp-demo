#ifndef AIDL_GENERATED_COM_EXAMPLE_BN_CALCULATOR_H_
#define AIDL_GENERATED_COM_EXAMPLE_BN_CALCULATOR_H_

#include <binder/IInterface.h>
#include <com/example/ICalculator.h>

namespace com {

namespace example {

class BnCalculator : public ::android::BnInterface<ICalculator> {
public:
  explicit BnCalculator();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCalculator

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_BN_CALCULATOR_H_
