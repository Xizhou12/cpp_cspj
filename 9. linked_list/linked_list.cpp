#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int nums[100] = {0}; // 100 * 4 bytes = 400 bytes字节
int nums2[10000] = {0}; // 10000 * 4 bytes = 40000 bytes字节
/*
  电脑里面我们都知道有内存的概念 硬盘
    - heap 堆 stack 栈
    int a[100] = {0,1,2,4,5,6}

*/
int a[11] = {0,2,3,4,5,6,7,8,9};
int insert(int i){
  for(int j = 8; j >= i; j--){
    int temp = a[j];
    a[j+1] = temp;
  }
}
struct student {
  string name; // “abcde”
};
struct classroom { // 节点
  int room_number; // 数据
  student s1;
  student s2;
  student s[100];
  classroom* next;
};

struct Node{ //结构体
  int data; //数据
  Node* next; // 下一个节点的地址
};

/*
    Node *p = new Node{1, NULL}; // p是一个地址
    Node x = *p; // 通过地址获得原本数据类型是在前面加**/

int main(){
  Node n = {1, NULL}; // 1 -> NULL 空指针
  Node cur = n;

  for(int i = 2; i < 10; i++){
    Node nxt = {i, NULL}; // 下一个节点
    cur.next = &nxt; // 从原本数据类型获取地址是在前面加&
    cur = nxt;
  }
}