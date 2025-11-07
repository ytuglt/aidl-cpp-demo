package com.example;

// 计算器接口定义
interface ICalculator {
    // 加法
    int add(int a, int b);
    
    // 减法
    int subtract(int a, int b);
    
    // 乘法
    int multiply(int a, int b);
    
    // 除法
    int divide(int a, int b);
    
    // 获取服务信息
    String getServiceInfo();
}
