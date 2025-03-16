#include <bits/stdc++.h>

using namespace std;

int x[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
/*
  low high 是位置下标索引
  low = 0, high = 9
*/
int binary_search(int low, int high, int target){
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

int binary_search_2(int low, int high, int target){
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

int binary_search_3(int low, int high, int target){
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
  // 对数组x的0-9下标位置进行二分查找，查找目标15
  cout << binary_search(0, 9, 15) << endl;
}