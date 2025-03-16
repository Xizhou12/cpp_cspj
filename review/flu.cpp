#include<bits/stdc++.h>

using namespace std;
int counter = 100;
/*
  static 属于某一个函数、
  并且只要程序在运行 一旦被定义它是不会消失的
*/

int compare(int x, int y){
  /*
    true  x 应该在 y前面
    false y 应该在 x前面
  */
  
  return x > y;
}


int main(){
  int x[] = {3,1,4,2,5};
  /*
    地址
    取地址 &
    x 1.数组名 2.数组的地址 3.数组第一个数的地址

  int * p;
  short *p;
  默认从小到大
  */
  int v= 10, m = 100;
  sort(x, x+5, [](int a, int b){
    return a > b;
  });
  for(int i = 0; i < 5; i++){
    cout << x[i] << endl;
  }
  // reverse(x, x+5);
  // for(int i = 0; i < 5; i++){
  //   cout << x[i] << endl;
  // }
  /*
    无名函数
    lambda 函数
  */
  
}