#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;
const int MAX = 10000;
int main(){
  int N, M; // N是人数 M是报数个数
  cin >> N >> M;
  /* 模拟报数的过程 假设7个人报数3
  p是下标， i是当前报数，q是报过数的人数
  p: 0 1 2 3 4 5 6 0 1 2 3 始终 +1 但是当>=人数时需要回到0
  i: 1 2 3 1 2 3 1 2 3     每报到3的时候要输出当前的p+1，并把当前这个人改为已报数，q++
  当q和M相同时结束循环
  */
  int p=0, q=0, i=0; 
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