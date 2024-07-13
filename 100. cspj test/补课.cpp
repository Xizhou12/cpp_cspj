#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  


  
 /* break continue 
  是在循环中使用的 switch case
  break 跳出当前的整个循环
  continue 跳过当前的这一次循环 e.g. i==5
*/

  // 这里才是循环外部


  
 /* bubble sort 对于的任何的数字数组
  3 1 2 4
=>1 2 3 4 [4]
=>1 2 3 4 [3,4]


  4 3 2 1 
  N = 4
  第一次小循环是3次
=>3 2 1 4 [4]      循环了3次
=>2 1 3 4 [3,4]    循环了2次
=>1 2 3 4 [2,3,4]  循环了1次 


=>1 2 3 4 [1,2,3,4]循环了3次 
  0 1
    1 2
      2 3
  0 1 2 3
 */
// 算法 不同的程序可以达到同一个目的
// 好的算法可以让计算机计算更少的次数的
  int arr[] = {3,2,1,4, 6, -1, 100, 18,-56};// N = 100000
  int temp, N = sizeof(arr)/sizeof(arr[0]);
  for(int i =0; i < N-1 ; i++){ // 循环了N-1次
  // 0.. N-2 (N-1次) ||  N .. 2 （N-1次）
    for(int j = 0; j < N-1; j++){ // j = 0,1,2
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  for(int i = 0; i < N; i++){
    cout << arr[i] << " ";
  }


 /* 一维二维数组的使用 */

 /* 开关门 */
  
 /* 约瑟夫问题 */
  return 0;
}

int calculate(){
  /*
    1. 运算符
    + - * / % 
    2. 关系运算符
    > < >= <= == !=
    3. 逻辑运算符
    && || !
    && 需要同时满足多个条件
    || 满足其中一个条件
  */  
  float x = 2;
  // x == 3 => true(1)
  // 条件 都会最后变成 true成立 / false不成立
  if (3 > x && x > 1 && x == 2){
    printf("yes");
  }
  return 0;
}

int conversion(){
   /* 强制转化 隐式转化 
 大多数隐式转化都是允许的 但是有些情况是需要注意的
 */
  int x = 2; // 2
  bool y = 2; // 值不为0 的数字都最后会变成true
  if ( x%3){

  }
  double b[] = {1.0, 2.0, '3'}; // 'A' -> 65 '3' -> 83 -> 83.0
  int z = 3;
  double t = (double)(z) / 2; // 3 / 2.0 -> 1.5 -> 1.0 
  printf("%lf\n", t);
  return 0;
}