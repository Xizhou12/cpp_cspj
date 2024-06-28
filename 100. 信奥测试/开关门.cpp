#include <cstdio>
#include <iostream>

using namespace std;
int open_rooms(){
  // 做个2-3道题
  // 要自己整理笔记
  // 1. 自己把这节课的知识点 整理出来
  // 2. 每次做题的你都应该学到的新的东西 你要整理出来
  /*        房间编号: 1   2   3   4   5
  第一个服务员结束了: [1] [1] [1] [1] [1] 
  第二个服务员结束了: [1] [0] [1] [0] [1]  // 1 -> 0, 0 -> 1
  第三个服务员结束了: [1] [0] [0] [0] [1]
  第四个服务员结束了: [1] [0] [0] [1] [1]
  第五个服务员结束了: [1] [0] [0] [1] [0] // 存的是房间的状态 开：1 关：0
  1 4
  房间数 = 服务员数量

  有几个 1个
  什么类型 int
  输入的含义是什么 n = 房间数 = 服务员数量
  */
  int n;
  scanf("%d", &n);
  int rooms[n+1]; // 0..n 
  for (int i = 1; i <= n; i++){
    rooms[i] = 0; // 1..n 所有门关闭
  }


  for(int i = 1; i <= n; i++){   // i代表服务员序号
    for(int j = 1; j <= n; j++){ // j代表房间序号
      if(j % i == 0){ // 判断当前房间序号j是不是服务员序号的倍数
        rooms[j] = 1 - rooms[j]; // 0 -> 1, 1 -> 0 这是我们的相反处理
        // rooms[j] = !rooms[j];
      }
    }
  }

  for(int i = 1; i <= n; i++){
    if(rooms[i] == 1){
      cout << i << " ";
    }
  }

  return 0;
}










int open_rooms2(){

  int n;
  scanf("%d", &n);

  int rooms[n]; // 存门开关的状态 0..n-1
  for(int i =0; i < n; i++){
    // 每扇门存开的状态进去
    rooms[i] = 1;
  }
  // 第一个服务员结束

  // 第2-n个服务员的开关门
  
  for(int i = 2; i <= n; i++){
    // i 是第几个服务员
    for(int j= 0; j < n; j++){
      // j 是第几扇门 - 数组里rooms的位置
      // j+1 是门的编号
      if ((j+1) % i == 0){
        rooms[j] = 1 - rooms[j]; // 0 -> 1, 1 -> 0 我在做相反处理
      }
    }
  }
  for(int j= 0; j < n; j++){
    // j 是第几扇门 - 数组里rooms的位置
      // j+1 是门的编号
    if (rooms[j] == 1){
      printf("%d ", j+1);
    }
  }
  return 0;
}

int main(){
  open_rooms();
} 


