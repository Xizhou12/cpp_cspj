#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
  string line;
  while(getline(cin, line)){
    if (line == ""){
      break;
    }
    const char *s = line.c_str();

    int n1 = atoi(&s[0]);
    int n2 = atoi(&s[2]);
    cout << n1 << ' ' << n2;
    int x = 0;
  }
}