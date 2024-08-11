#include <bits/stdc++.h>
using namespace std;

int names[10]; // 全局变量

/*
    访问读取
    修改
*/
int abc(int a, int b, string s, vector<int> &v, int c[10] ){ // 函数的定义 返回值 参数
    cout << "我是abc函数" << endl;
    cout << v[0] << endl;
    cout << names[0] << endl;
    return 0;
}
/*
    递归是需要自己调用的自己
*/
/*
    当我们在一个文件里有多个函数的时候 我们想要让他们用同一个数据有两种方法做到

*/
int main(){
    vector<int> v; // 动态数组 可以是一维的 也可以是二维
    vector<int, int> v2; // 一维数组 长度为2 
    vector<vector<int>> v3; // 二维数组 {}
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            v3[i][j] = i+j;
        }
    }
    int c[10]  = {0}; // 局部变量
    int i;
    for(i = 0; i < 10; i++){
        int x = 10;
        names[i] = i;
        v.push_back(i);
        c[i] = i;
    }
    cout << i << endl;
    abc(1,2,"string", v, c); // 函数的调用
    return 0;
}