#include <bits/stdc++.h>
using namespace std;
/*
    返回值(数据类型) int, bool, string, void
    函数名就相当于一个随便取的名字，和变量名是一样的
    参数(类型 在函数内的名称)
    函数体：用来计算一些东西或进行一些操作
    返回值

    我们有两种函数
    built-in functions 内置函数 例如 strlen printf scanf 等是c++自带的函数
    自定义函数 - 我们自己定义的函数
*/


int add(int a, int b){
    /* 值传递
        不会改变在函数外被传入的变量的值
    */
    a = 3;
    b = 4;
   return a+b;
}

int add2(int& a, int& b){
    /* 引用传递
        会改变在函数外被传入的变量的值
    */ 
    a = 3;
    b = 4;
   return a+b;
}

int add3(int* a, int* b){
    // 指针传递 和引用传递类似
    *a = 100;
    *b = 200;
    return *a + *b;
}

int fibonacci(int n){
    /*  递归
        在函数内部引用自己的函数就叫递归函数
        1. 初始条件
        2. 自己调用自己
    */
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
/*
    函数重载
    cpp允许函数名相同，但是参数不同的函数
    参数类型或个数不同 都可以
*/ 
int add(int a, int b, int c){
    return a + b + c;
}
float add(float a, float b){
    return a + b;
}

// 函数模板
template <typename P> // P 任何类型
P add4(P a, P b){
    return a + b;
}

// 全局变量 global
int z = 100;
int main() { // 主函数
    // add(1,2);
    /*
        如果一个全局变量和某一个局部变量同名的时候，那么在函数里会优先把他当作局部变量来看待
    */
    int z = 15;
    cout << z << endl; // 15

    int x = 10, y = 20;
    cout << add(x, y) << endl; // 7
    cout << x << " " << y << endl; // 10 20 值传递不改变外面变量的值

    cout << add2(x, y) << endl; // 7
    cout << x << " " << y << endl; // 3 4 引用传递改变外面变量的值

    cout << add3(&x, &y) << endl; // 300
    cout << x << " " << y << endl; // 100 200 指针传递改变外面变量的值
    
    /*
        使用模板以后 add4 可以接受任何类型的参数
    */
    cout << add4(1, 2) << endl;
    cout << add4(1024.7, 512.3) << endl;
    return 0;

}







