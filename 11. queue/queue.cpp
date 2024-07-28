#include <cstdio>
#include <iostream>
/*
    implment a queue using array
*/

const int MAX = 100;
struct Queue {
    int data[MAX];
    int head, tail;
    // 初始化一个队列
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

bool dequeue(Queue &q, int &x) {
    if (empty(q)) {
        return false;
    }
    x = q.data[q.head];
    q.head = (q.head + 1) % MAX;
    return true;
}