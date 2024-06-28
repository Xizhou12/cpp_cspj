#include <cstdio>
#include <iostream>

int main(){
  int a,b;
  scanf("%d %d", &a, &b);
  long long x = (long long) a * b; // 代表先把 a转换成 long long 类型
  printf("%lld", x);
  return 0;
}