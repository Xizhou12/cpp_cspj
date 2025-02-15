#include <bits/stdc++.h>
using namespace std;
int N, C; // 3
int arr[100005]; // 1 2 4 8 9
int check(int x){
  // 检查最小距离是x的情况下 我们的arr能放的小N头牛
  int cnt = 1; //可以放几头牛
  int last = arr[1]; //第一头牛放在arr[1]
  for(int i = 2; i <= N; i++){
    if(arr[i] - last >= x){
      cnt++;
      last = arr[i];
    }
  }
  return cnt >= C;
}

int main(){
  cin >> N >> C;
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }
  int low = 1, high = arr[N] - arr[1];
  sort(arr + 1, arr + N + 1);

  while(low < high){
    int mid = (low + high + 1) / 2;
    if(check(mid)){
      low = mid;
    }else{
      high = mid - 1;
    }
  }
  cout << low;
  return 0;
}