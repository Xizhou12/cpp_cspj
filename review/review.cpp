#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;
int compare(int x, int y){
    // return 0 / 1
    return x > y;
};

struct Person{
    int age;
    double score;
};
int main() {
    // int x[10];
    int x[10] = {2,1,3,4,6,7,8,9,10,5};
    // int x[] = {1,2,3,4,5,6,7,8,9,10};
    // int x[10] = {1,2,3};
    // int x[10] = {0};

    // 写入
    // for(int i =0; i < 10; i++){
    //     cin >> x[i];
    // }

    // for(int i =0; i < 10; i++){ // i 代表的是下标
    //     cout << x[i] << endl;
    // }

    // for(int i : x){ // i 代表的是x数组里的数字
    //     cout << i << endl;
    // }

    //sizeof
    cout << sizeof(x) << endl; // 40 = 4 * 10
    cout << sizeof(x) / sizeof(x[0]) << endl;
    cout << sizeof(x) / sizeof(int) << endl;

    cout << x << endl; // 0x30c6d6dd0
    cout << &x[0] << endl; // 数组的地址 = 数组里的第一个数字的地址

    /*
        变量变成地址 &
        地址变成变量 *
    */
   
    sort(x, x+10, compare);
    int * p;
    for( p=x; p < x+10; p++){
        cout << *p << endl;
    }

    // int x[3][3];
    // int x[3][3] = {1,2,3,4,5,6,7,8,9};
    // int x[3][3] = { {1,2,3}, {4,5,6}, {7,8,9}};
    int y[2][3] = {1,2,3,4,5,6};
    // for(int i = 0; i < 2; i ++){
    //     for(int j = 0; j < 3; j++){
    //         cout << y[i][j];
    //     }
    // }

    cout << y << endl;       //数组的地址
    cout << y[0] << endl;    //数组第1行的地址
    cout << &y[0][0] << endl;

    cout << y + 1 << endl;   // +3个数
    cout << y[0] + 1 << endl;




}
//dazikukuw.com