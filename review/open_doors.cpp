#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAX = 100000;
int main(){
  int N;
  cin >> N;
  int rooms[MAX] = {0}; // 0 打开 1 关闭
  for(int i = 2; i <= N; i++){ // 每个服务员
    for(int j = 1; j <= N; j++){
      if(j%i==0){
        // rooms[j] = !rooms[j];
        rooms[j] = 1 - rooms[j];
      }
    }
  }

  for(int i = 1; i <= N; i++){
    if(rooms[i] == 0){
      cout << i << " ";
    }
  }

}