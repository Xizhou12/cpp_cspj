#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;
/*
break continue
1. 他们一定出现循环里
2. break 一但看见这个关键词 程序会自动跳出(结束)当前整个的循环
3. continue 一但看见这个关键词 程序会自动跳过当前的这一次循环
*/

int loop_continue(){
  int i, sum = 0;
  // 我想要1..100的和 但是不要加5的倍数 (5, 10, 15...) 不加进去
  for(int i = 0; i < 100; i++){
    if (i % 5 == 0){
      continue;
    }
    // i = 5,10,15... 的时候 sum += i不会执行
    sum += i;
  }
  return 0;
}

int loop_break(){
  int i, sum = 0;
  // 我想要从1加到无限大，但是我的和一旦超过100就停止
  for(i = 1; i < 1000000; i++){ // sum > 100
    sum += i;
    if (sum > 100){
      break;
    }
  }
  printf("%d", sum);

  // 同样的方法用while循环
  sum = 0;
  while(true){
    sum += i;
    if (sum > 100){
      break;
    }
    i++;
  }
  return 0;
}

int array_loop(){
  // int x;     // 申明了一个变量x 可以存1个整形
  int x[10]; // 申明了一个数组 x 可以存10个整形
  // x[0] .. x[9]
  // 存10个数字 每次循环我存一个数字
  // 我想要把 1,2,3,.. 10 放到x[10]里面 如何用循环放置
  for(int i = 0; i <= 9; i++){
    // 数组的位置(下标)是从0开始的
    x[i] = i+1;
    printf("%d ", x[i]);
  }
  return 0;
}

int main(){ // 函数
  array_loop();
  return 0;
}

