package com.example;

// 回调接口定义
interface ICalculatorCallback {
    // 计算结果回调
    oneway void onResult(int result);
    
    // 错误回调
    oneway void onError(String errorMsg);
}
