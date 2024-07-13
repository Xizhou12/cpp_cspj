#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
// bubble sort 冒泡排序
int main(){
  int arr[] = { 6,4,5,2,1,3,8,7};
  int temp, n = 8;
  for (int i = 0; i < n; i++){
    // 外面的循环 循环7次
    // 如果数列长度为8 那外面循环8次 里面循环7次
    for (int j =0; j < n-i-1; j++) { 
      // 互相交换的数是哪两个数字
      // 6,4,5,2,1,3,8,7
      // j 和 j+1位置的数字交换的过程 6 和 7 换
      // 第一次比较 7 次 
      // 第二次比较 6 次
      if (arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp; 
      }
    }
  }
  for(int i = 0; i < 8; i ++){
    cout << arr[i] << " ";
  }
  return 0;
}