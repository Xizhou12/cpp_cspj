#include<bits/stdc++.h>
using namespace std;

const int size_stack = 100; // const 常量
int A[size_stack];
int top = -1;

void push(int x){
  // 添加一个数据进栈
  A[++top] = x;
}

void pop(){
  // 删除一个数据
  top --;
}

bool is_empty(){
  // 判断栈是否为空
  return top == -1;
}

bool is_full(){
  // 判断栈是否为满
  return top == size_stack-1;
}

void read(){
  for(int i = 0; i <= top; i++){
    cout << A[i] << endl;
  }
}

int main(){
  // // 让1，2，3按顺序进栈
  // push(1);
  // push(2);
  // push(3);
  // pop();
  
  // push(4);
  // push(5);
  // pop();

  stack<int> B = stack<int>();
  B.push(100);
  B.push(200);
  B.push(300);
  B.pop();
  cout << B.top() << endl;
  



  read();
}