/*
 * This file is auto-generated.  DO NOT MODIFY.
 */
package com.example;
// 计算器接口定义

public interface ICalculator extends android.os.IInterface
{
  /** Default implementation for ICalculator. */
  public static class Default implements com.example.ICalculator
  {
    // 加法

    @Override public int add(int a, int b) throws android.os.RemoteException
    {
      return 0;
    }
    // 减法

    @Override public int subtract(int a, int b) throws android.os.RemoteException
    {
      return 0;
    }
    // 乘法

    @Override public int multiply(int a, int b) throws android.os.RemoteException
    {
      return 0;
    }
    // 除法

    @Override public int divide(int a, int b) throws android.os.RemoteException
    {
      return 0;
    }
    // 获取服务信息

    @Override public java.lang.String getServiceInfo() throws android.os.RemoteException
    {
      return null;
    }
    @Override
    public android.os.IBinder asBinder() {
      return null;
    }
  }
  /** Local-side IPC implementation stub class. */
  public static abstract class Stub extends android.os.Binder implements com.example.ICalculator
  {
    private static final java.lang.String DESCRIPTOR = "com$example$ICalculator".replace('$', '.');
    /** Construct the stub at attach it to the interface. */
    public Stub()
    {
      this.attachInterface(this, DESCRIPTOR);
    }
    /**
     * Cast an IBinder object into an com.example.ICalculator interface,
     * generating a proxy if needed.
     */
    public static com.example.ICalculator asInterface(android.os.IBinder obj)
    {
      if ((obj==null)) {
        return null;
      }
      android.os.IInterface iin = obj.queryLocalInterface(DESCRIPTOR);
      if (((iin!=null)&&(iin instanceof com.example.ICalculator))) {
        return ((com.example.ICalculator)iin);
      }
      return new com.example.ICalculator.Stub.Proxy(obj);
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
        case TRANSACTION_add:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _result = this.add(_arg0, _arg1);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_subtract:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _result = this.subtract(_arg0, _arg1);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_multiply:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _result = this.multiply(_arg0, _arg1);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_divide:
        {
          data.enforceInterface(descriptor);
          int _arg0;
          _arg0 = data.readInt();
          int _arg1;
          _arg1 = data.readInt();
          int _result = this.divide(_arg0, _arg1);
          reply.writeNoException();
          reply.writeInt(_result);
          return true;
        }
        case TRANSACTION_getServiceInfo:
        {
          data.enforceInterface(descriptor);
          java.lang.String _result = this.getServiceInfo();
          reply.writeNoException();
          reply.writeString(_result);
          return true;
        }
        default:
        {
          return super.onTransact(code, data, reply, flags);
        }
      }
    }
    private static class Proxy implements com.example.ICalculator
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
      // 加法

      @Override public int add(int a, int b) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(a);
          _data.writeInt(b);
          boolean _status = mRemote.transact(Stub.TRANSACTION_add, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().add(a, b);
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      // 减法

      @Override public int subtract(int a, int b) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(a);
          _data.writeInt(b);
          boolean _status = mRemote.transact(Stub.TRANSACTION_subtract, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().subtract(a, b);
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      // 乘法

      @Override public int multiply(int a, int b) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(a);
          _data.writeInt(b);
          boolean _status = mRemote.transact(Stub.TRANSACTION_multiply, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().multiply(a, b);
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      // 除法

      @Override public int divide(int a, int b) throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        int _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          _data.writeInt(a);
          _data.writeInt(b);
          boolean _status = mRemote.transact(Stub.TRANSACTION_divide, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().divide(a, b);
          }
          _reply.readException();
          _result = _reply.readInt();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      // 获取服务信息

      @Override public java.lang.String getServiceInfo() throws android.os.RemoteException
      {
        android.os.Parcel _data = android.os.Parcel.obtain();
        android.os.Parcel _reply = android.os.Parcel.obtain();
        java.lang.String _result;
        try {
          _data.writeInterfaceToken(DESCRIPTOR);
          boolean _status = mRemote.transact(Stub.TRANSACTION_getServiceInfo, _data, _reply, 0);
          if (!_status && getDefaultImpl() != null) {
            return getDefaultImpl().getServiceInfo();
          }
          _reply.readException();
          _result = _reply.readString();
        }
        finally {
          _reply.recycle();
          _data.recycle();
        }
        return _result;
      }
      public static com.example.ICalculator sDefaultImpl;
    }
    static final int TRANSACTION_add = (android.os.IBinder.FIRST_CALL_TRANSACTION + 0);
    static final int TRANSACTION_subtract = (android.os.IBinder.FIRST_CALL_TRANSACTION + 1);
    static final int TRANSACTION_multiply = (android.os.IBinder.FIRST_CALL_TRANSACTION + 2);
    static final int TRANSACTION_divide = (android.os.IBinder.FIRST_CALL_TRANSACTION + 3);
    static final int TRANSACTION_getServiceInfo = (android.os.IBinder.FIRST_CALL_TRANSACTION + 4);
    public static boolean setDefaultImpl(com.example.ICalculator impl) {
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
    public static com.example.ICalculator getDefaultImpl() {
      return Stub.Proxy.sDefaultImpl;
    }
  }
  // 加法

  public int add(int a, int b) throws android.os.RemoteException;
  // 减法

  public int subtract(int a, int b) throws android.os.RemoteException;
  // 乘法

  public int multiply(int a, int b) throws android.os.RemoteException;
  // 除法

  public int divide(int a, int b) throws android.os.RemoteException;
  // 获取服务信息

  public java.lang.String getServiceInfo() throws android.os.RemoteException;
}
