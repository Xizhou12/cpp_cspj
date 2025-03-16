#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  getline(cin, s); // s = "You want someone to help you"
  string A, B;
  cin >> A >> B;
  while(1){
    int pos = s.find(A);
    if(pos == string::npos) // 没有在s当中找到A
      break;
    s.replace(pos, A.size(), B);
  }
  cout << s << endl;



  
  // string s = "helloworldasdgsfworld";
  // // hellobigasdgsfbig
  // while(1){
  //   int pos = s.find("world");
  //   if(pos == string::npos) // -1 string::npos
  //     break;
  //   s.replace(pos, 5, "big");
  // }
  // // int pos = s.find("world");
  // // cout << pos << endl;
  // cout << s << endl;

}