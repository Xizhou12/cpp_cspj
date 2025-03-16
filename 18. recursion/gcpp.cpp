#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  // 求a 和 b之间的最大公约数
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}
int a[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int binary_search(int target, int low, int high){
    // low 和 high 是数组所需要排序的部分的范围 [low, high]
    /*
      如果找到target，返回target在数组中的下标
      如果没找到,返回-1
    */
    while(low <= high){
      int mid = (low + high) / 2;
      // int mid = low + (high - low) / 2;
      if(a[mid] == target){
        //找到了
        return mid;
      }else if(a[mid] > target){
        // 重新分割我的查找范围
        high = mid - 1;
      }else{
        low = mid + 1;
      }
    }
    // 没有找到
    return -1;
}
int main(){
  cout << binary_search(11, 0, 9) << endl;
}

