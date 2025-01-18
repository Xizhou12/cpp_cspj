#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;
const int MAX = 10000;
int main(){
  int N, M; // N是人数 M是报数个数
  cin >> N >> M;
  int p=0, q=0, i=0; // p是下标 ++， i是报数，q是报数到的人数
  int a[MAX] = {0};
  while(q < N){
    if(a[p] == 0){
      i++;
    }
    if(i == M){
      cout << p+1 << " ";
      a[p] = 1;
      q++;
    }
    i %= M;

    p = (p+1)% N;
  }

}