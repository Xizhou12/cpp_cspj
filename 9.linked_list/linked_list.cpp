#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct student {
  string name;
};
struct classroom { // 节点
  int room_number; // 数据
  student s1;
  student s2;
  student s[100];
  classroom* next;
};

struct Node{
  int data;
  Node *next;
};


int main(){
  // 1. 通过数组 创建一个链表
  int nums[] = {10,23,13,-4,57};
  Node* head = new Node; //第一个节点
  Node* cur_node = head; // 当前的节点
  for(int i = 0; i < 5; i++){
    cur_node -> data = nums[i];
    cur_node -> next = new Node;
    cur_node = cur_node -> next;
  }

  cur_node = head;
  for(int i = 0; i < 5; i++){
    cout << cur_node -> data << endl;
    cur_node = cur_node -> next;
  }
}