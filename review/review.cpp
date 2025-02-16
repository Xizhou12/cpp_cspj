#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// 全局变量 global
int y = 100;
int add(int a, int b){
    // 值传递
    a = 3;
    b = 4;
   return a+b;
}
int add2(int& a, int& b){
    // 引用传递
    a = 3;
    b = 4;
   return a+b;
}

int add3(int* a, int* b){
    // 指针传递
    *a = 100;
    *b = 200;
    return *a + *b;
}

int fibonacci(int n){
    /*
        在函数内部引用自己的函数就叫递归函数
        1. 初始条件
        2. 自己调用自己
    */
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
// 函数重载

int add(int a, int b, int c){
    return a + b + c;
}
float add(float a, float b){
    return a + b;
}

// 函数模板
template <typename P> // P 任何类型
P add(P a, P b){
    return a + b;
}




int main() { // 主函数
    // add(1,2);
    /*
        如果说我有一个全局变量也有一个局部变量且同名的时候，那么在函数里会把他当作局部变量来看待
    */
    int x = 5;
    int y = 10;
    int s = add3(&x,&y);

    cout << s << endl;
    cout << x << " " << y << endl;
    double a = 1.0;
    double b = 2.0;
    cout << add(1024.7, 512.3) << endl;
    return 0;

}

/*
    built-in functions 内置函数
    自定义函数
*/
/*
    返回值(数据类型) int, bool, string, void
    函数名就相当于一个随便取的名字，和变量名是一样的
    参数
    函数体用来计算一些东西
    返回值
    
*/




