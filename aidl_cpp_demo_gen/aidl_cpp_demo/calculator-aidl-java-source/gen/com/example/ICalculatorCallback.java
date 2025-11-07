/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package com.example;
// 回调接口定义

public interface ICalculatorCallback extends android.os.IInterface
{
  /** Default implementation for ICalculatorCallback. */
  public static class Default implements com.example.ICalculatorCallback
  {
    // 计算结果回调

    @Override public void onResult(int result) throws android.os.RemoteException
    {
    }
    // 错误回调

    @Override public void onError(java.lang.String errorMsg) throws android.os.RemoteException
    {
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements com.example.ICalculatorCallback
  {
    private static final java.lang.String DESCRIPTOR = "com$example$ICalculatorCallback".replace('$', '.');
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an com.example.ICalculatorCallback interface,
     * generating a proxy if needed.
     */
    public static com.example.ICalculatorCallback asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof com.example.ICalculatorCallback))) {
        return ((com.example.ICalculatorCallback)iin);
      }
      return new com.example.ICalculatorCallback.Stub.Proxy(obj);
    }
    @Override public android.os.IBinder asBinder()
    {
      return this;
    }
    @Override public boolean onTransact(int code, android.os.Parcel data, android.os.Parcel reply, int flags) throws android.os.RemoteException
    {
      java.lang.String descriptor = DESCRIPTOR;
      switch (code)
      {
        case INTERFACE_TRANSACTION:
        {
          reply.writeString(descriptor);
          return true;
        }
        case TRANSACTION_onResult:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          this.onResult(_arg0);
          return true;
        }
        case TRANSACTION_onError:
        {
          data.enforceInterface(descriptor);
          java.lang.String _arg0;
          _arg0 = data.readString();
          this.onError(_arg0);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements com.example.ICalculatorCallback
    {
      private android.os.IBinder mRemote;
      Proxy(android.os.IBinder remote)
      {
        mRemote = remote;
      }
      @Override public android.os.IBinder asBinder()
      {
        return mRemote;
      }
      public java.lang.String getInterfaceDescriptor()
      {
        return DESCRIPTOR;
      }
      // 计算结果回调

      @Override public void onResult(int result) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(result);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onResult, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onResult(result);
            return;
          }
        }
        finally {
          _data.recycle();
        }
      }
      // 错误回调

      @Override public void onError(java.lang.String errorMsg) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeString(errorMsg);
          boolean _status = mRemote.transact(Stub.TRANSACTION_onError, _data, null, android.os.IBinder.FLAG_ONEWAY);
          if (!_status && getDefaultImpl() != null) {
            getDefaultImpl().onError(errorMsg);
            return;
          }
        }
        finally {
          _data.recycle();
        }
      }
      public static com.example.ICalculatorCallback sDefaultImpl;
    }
    static final int TRANSACTION_onResult = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_onError = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    public static boolean setDefaultImpl(com.example.ICalculatorCallback impl) {
      // Only one user of this interface can use this function
      // at a time. This is a heuristic to detect if two different
      // users in the same process use this function.
      if (Stub.Proxy.sDefaultImpl != null) {
        throw new IllegalStateException("setDefaultImpl() called twice");
      }
      if (impl != null) {
        Stub.Proxy.sDefaultImpl = impl;
        return true;
      }
      return false;
    }
    public static com.example.ICalculatorCallback getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  // 计算结果回调

  public void onResult(int result) throws android.os.RemoteException;
  // 错误回调

  public void onError(java.lang.String errorMsg) throws android.os.RemoteException;
}
