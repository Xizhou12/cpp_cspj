#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main(){
  char c = 0; //只要不为 \n都可以
  bool prev_space = false;
  while(c != '\n'){
    c = getchar();
    if (c!=' '){ // 非空格字符输出 并且告诉下一次循环上一次不是空格
      cout << c;
      prev_space = false;
    }else{
      if (! prev_space){ // 之前一个字符不是空格 现在是空格输出
        cout << c;
        prev_space = true;
      }
      // 否则之前一个字符是空格现在也是空格不输出
    }
  }
}



