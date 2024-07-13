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

int main(){
    Stack s;
    s.data[++s.top] = 1;
    s.data[++s.top] = 2;
    s.data[++s.top] = 3;
    cout << s.data[s.top--] << endl;
    cout << s.data[s.top--] << endl;
    cout << s.data[s.top--] << endl;
    return 0;
}