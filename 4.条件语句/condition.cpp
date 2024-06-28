#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int number_1(){
  /*
    输入一个数字 我想知道它是不是大于10的奇数
    1. 满足是奇数
    2. 满足要大于10
    并且 &&
    或者 ||
  */ 
  int x;
  // cin >> x;
  scanf("%d", &x);
  
  if (x > 10 && x % 2 == 1){
    printf("%d是大于10的奇数\n", x);
  }
  return 0;
}

int number_2(){
  // 输入一个数字 我想知道它是不是大于10 或者 || 是奇数
  int x;
  // cin >> x;
  scanf("%d", &x);
  
  if (x > 10 || x % 2 == 1){
    printf("%d是大于10或者奇数\n", x);
  }
  return 0;
}

int number_3(){
  // if,else if, else
  int x = 13;
  if(x > 10){
    printf("%d大于10\n", x);
  } else if(x < 0){
    printf("%d小于0\n", x);
  } else { // x <= 10 && x >= 0
    printf("%d不大于10且不小于0\n", x);
  }
  return 0;
}

int number_4(){
  // if, if, else
  int x = 13;
  if(x > 10){
    printf("%d大于10\n", x);
  } 
  if(x < 0){
    printf("%d小于0\n", x);
    //.. else if
  } else { // x >= 0
    printf("%d不大于10且不小于0\n", x);
  }
  return 0;
}

int main(){ // 函数
  number_1();
  return 0;
}



//信奥题库：http://ybt.ssoier.cn:8088
//打字：https://dazi.kukuw.com
//打字：https://www.typingclub.com/sportal/program-48.game