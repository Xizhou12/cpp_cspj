#include <cstdio>
#include <iostream>
/*
    implment a queue using array
*/

const int MAX = 100;
struct Queue {
    int data[MAX];
    int head, tail; //头 尾
    // 初始化一个队列
    // 先进的 先出
    Queue() {
        head = 0;
        tail = 0;
    }
};

bool empty(Queue q) {
    return q.head == q.tail;
}

bool full(Queue q) {
    return (q.tail + 1) % MAX == q.head;
}

bool enqueue(Queue &q, int x) {
    if (full(q)) {
        return false;
    }
    q.data[q.tail] = x;
    q.tail = (q.tail + 1) % MAX;
    return true;
}

bool dequeue(Queue &q) {
    if (empty(q)) {
        return false;
    }
    q.head = (q.head + 1) % MAX;
    return true;
}