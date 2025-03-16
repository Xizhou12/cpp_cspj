#include<bits/stdc++.h>
using namespace std;
int is_prime(int n){
  /* 要学会用比较有意义的名称作为函数名 并且要注意不要有重复
    这里is_prime 指是否是质数 prime质数
  */
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}
int main(){
  int n;
  cin >> n;
  bool has_primes = false;
  for (int i = 2; i+2 <= n; i++){
    // 这里设i为较小的数，由于比他较大的素数对也不能超过, 故i+2 <= n
    if(is_prime(i) && is_prime(i+2)){
      cout << i << " " << i+2 << endl;
      has_primes = true;
    }
  }
  if(!has_primes){
    cout << "empty" << endl;
  }
  
  return 0;
}