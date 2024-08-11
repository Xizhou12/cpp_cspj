#include <bits/stdc++.h>

using namespace std;

int x[] = {0,1};
/*
  low high 是位置下标索引
  low = 0, high = 9
*/
int bs(int low, int high, int target, int x[]){
  // 在这个函数里
  while(low <= high){ 
    // int mid = (low + high) / 2; // 
    int mid = low + (high - low) / 2; // 更优
    if(target == x[mid]){
      return mid; //
    }else if(target > x[mid]){
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  return -1; //
}

int bs_2(int low, int high, int target, int x[]){
  /*
    假设我有一个长度为10的数组 他的下标为0-9
    low 包含在查找的范围, high 不在包含的范围了
    low = 0, high=10, high-1
  */
  while(low < high){
    int mid = low + (high -low) / 2;
    if ( x[mid] == target){
      return mid;
    }else if (x[mid] > target){
      high = mid;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}

int bs_3(int low, int high, int target, int x[]){
  // low high 都包含
  while(low+1 < high){ // 
    int mid = low + (high -low) / 2;
    if ( x[mid] == target){
      return mid;
    }else if (x[mid] > target){
      high = mid;
    }else{
      low = mid;
    }
  }
  if(x[low] == target) return low;
  if(x[high] == target) return high;
  return -1;
}


int main(){
  int x1[] = {1, 3, 5,6,8 ,10, 13, 15, 19, 31}; // 建立一个有序数组
  cout << bs(0, 9, 15, x1) << endl;
}