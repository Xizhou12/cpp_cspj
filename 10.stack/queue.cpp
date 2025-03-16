#include<bits/stdc++.h>
using namespace std;

const int size_queue = 100; // const 常量
int A[size_queue];
int head = 0;
int tail = 0;
int cnt = 0; // 计量queue里有多少个数据

void enqueue(int x){
  // 进入队列 先进先出
  tail = (tail+1) % 100; // ->0 
  A[tail] = x;
  cnt ++;
}

void dequeue(){
  // 出队列  先进先出
  head = (tail+1) % 100;
  cnt --;
}

bool is_full(){
  //
  return cnt > 100;
}

bool is_empty(){
  return cnt == 0;
}

int main(){
  queue<int> B = queue<int>();
  B.push(100);
  B.push(200);
  B.pop();
  B.push(300);
  B.push(400);
  cout << B.front() << B.back() << endl;
}