#include <bits/stdc++.h>
using namespace std;
int compare(string a, string b){
  return a.size() > b.size();
}
int main(){
  string s[205]; // 字符串数组
  int i = 0;
  
  while(cin >> s[i]){
    s[i].erase(remove(s[i].begin(), s[i].end(), ','), s[i].end()); 
    i++;
  }
  stable_sort(s, s+i, compare);
  cout << s[0] << endl;
  cout << s[i-1] << endl;
  return 0;
}

