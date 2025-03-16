#include <bits/stdc++.h>
using namespace std;
int unhappy[8];
int main(){
  int unhappy_day = 0;
  int max_hours = 0; // 最不高兴的值（上课的天数）
  for(int i = 1; i <= 7; i++){
    int school, mama;
    cin >> school >> mama;
    int total = school + mama;
    if (total <= 8){
      continue;
    }
    if (total > max_hours){
      max_hours = total;
      unhappy_day = i;
    }
  }
  cout << unhappy_day << endl;
}