#include <cstdio>
#include <iostream>

using namespace std;
const int MAX = 100;
struct Stack {
    int data[MAX];
    int top;
    // 初始化一个栈
    Stack() {
        top = -1;
    }
};

bool empty(Stack s) {
    cout << "栈空" << endl;
    return s.top == -1;
}

bool full(Stack s) {
    cout << "栈满" << endl;
    return s.top == MAX - 1;
}

bool push(Stack &s, int x) {
    if (full(s)) {
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool pop(Stack &s, int &x) {
    if (empty(s)) {
        return false;
    }
    x = s.data[s.top--];
    return true;
}

int get_top(Stack s) {
    if (empty(s)) {
        return -1;
    }
    return s.data[s.top];
}

int main(){
    Stack s; // 已经初始化了一个栈
    s.data[++s.top] = 1;
    s.data[++s.top] = 2;
    s.data[++s.top] = 3;
    cout << s.data[s.top--] << endl;
    cout << s.data[s.top--] << endl;
    cout << s.data[s.top--] << endl;
    return 0;
}

