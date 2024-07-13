#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  const double discount = 0.8;
  int n,m;
  scanf("%d %d", &n, &m);
  printf("%.2f\n", n - m * discount);
}