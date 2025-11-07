#include <com/example/ICalculatorCallback.h>
#include <com/example/BpCalculatorCallback.h>

namespace com {

namespace example {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(CalculatorCallback, "com.example.ICalculatorCallback")

}  // namespace example

}  // namespace com
#include <com/example/BpCalculatorCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace com {

namespace example {

BpCalculatorCallback::BpCalculatorCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICalculatorCallback>(_aidl_impl){
}

::android::binder::Status BpCalculatorCallback::onResult(int32_t result) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(result);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onResult */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICalculatorCallback::getDefaultImpl())) {
     return ICalculatorCallback::getDefaultImpl()->onResult(result);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpCalculatorCallback::onError(const ::android::String16& errorMsg) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeString16(errorMsg);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* onError */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICalculatorCallback::getDefaultImpl())) {
     return ICalculatorCallback::getDefaultImpl()->onError(errorMsg);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace example

}  // namespace com
#include <com/example/BnCalculatorCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace com {

namespace example {

BnCalculatorCallback::BnCalculatorCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnCalculatorCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onResult */:
  {
    int32_t in_result;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_result);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onResult(in_result));
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* onError */:
  {
    ::android::String16 in_errorMsg;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readString16(&in_errorMsg);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onError(in_errorMsg));
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace example

}  // namespace com
