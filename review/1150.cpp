#include <bits/stdc++.h>

using namespace std;

int is_prime(int n){ // prime素数
  // 判断n是否是素数， 是的话返回1，不是的话返回0
  /*
    2 3 5 7 11 13
    2-12  
  */
  for(int i = 2; i*i <= n; i++){ // 因子的范围
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int n;
  cin >> n;
  int count = 0;
  for(int i = 2; i <= n; i++){
    if(is_prime(i)){ //
      count ++;
    }
  }
  cout << count << endl;
}