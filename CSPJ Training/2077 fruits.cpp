#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* prev;
    Node* next;
    int num_fruits;
    int fruit_type; // 0 apple 1 orange
    int start;
    int offset;
    Node(int num_fruits, int fruit_type, int offset): prev(NULL), next(NULL), num_fruits(num_fruits), fruit_type(fruit_type), start(1), offset(offset){}
};// 这是果篮里的一个块

int main(){
    int total_fruits;
    scanf("%d", &total_fruits);
    int prev_fruit = 1;
    int cur_node_size = 0;
    Node head = {0, 0, 0}; // create an empty node as head
    Node *cur = &head;
    int i;
    for(i = 0; i < total_fruits; i++){
        int fruit_type;
        scanf("%d", &fruit_type);
        if(fruit_type != prev_fruit && cur_node_size != 0){
            Node *n = new Node(cur_node_size, prev_fruit, i);
            cur_node_size = 0;
            cur->next = n;
            n->prev = cur;
            cur = n;
        }
        prev_fruit = fruit_type;
        cur_node_size++;
    }
    Node *n = new Node(cur_node_size, prev_fruit,i);
    cur->next = n;
    n->prev = cur;
    
    
    while(head.next->num_fruits>0){
        cur = head.next;
        int offsets = head.offset;
        while(cur){
            printf("%d ",offsets + cur->start);
            offsets = cur->offset;
            cur->num_fruits -=1;
            cur->start ++;
            if(cur->num_fruits == 0){
                Node* prev = cur->prev; //prev should never be NULL due to head is not NULL
                Node* next = cur->next;
                if(prev->num_fruits == 0 && prev != &head) continue;
                if(next){
                    prev->next = next->next;
                    if(next->next){
                        next->next->prev = prev;
                    }
                    if(prev != &head){
                        prev->num_fruits += next->num_fruits - 1;
                    }
                    prev->offset = next->offset;
                }else{
                    prev->next = NULL;
                }
            }
            
            cur = cur->next;
        }
        printf("\n");
        cur = head.next;
        while(cur){
            printf("%d-%d ", cur->num_fruits, cur->offset);
            cur = cur->next;
        }
        printf("\n");
    }
    return 0;
}