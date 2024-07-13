#include <cstdio>
#include <iostream>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int left_ppl = N;
  int circle[N];
  for(int i = 0; i < N; i++){
    circle[i] = i + 1;
  }
  int next, cur_pos = 0;
  while(left_ppl > 0){
    for(int i = 0; i < M; i++){
      next = (cur_pos + i) % N;
      if ( circle[next] == 0){
        cur_pos +=1;
        i-=1;
      }
    }
    cur_pos = next;
    circle[next] = 0;
    left_ppl --;
    printf("%d", next+1);
    if (left_ppl > 0)
      printf(" ");
  }
} 