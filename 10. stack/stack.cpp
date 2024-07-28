#include <cstdio>
#include <iostream>

using namespace std; // 命名空间

const int MAX = 100;
struct Stack { // 类型
    int data[MAX];
    int top; //栈顶
    // 初始化一个栈
    Stack() { //函数
        top = -1;
    }
};

bool empty(Stack s) { // 确认什么时候为空
    cout << "栈空" << endl;
    return s.top == -1;
}

bool full(Stack s) { // 确认什么时候是满的
    cout << "栈满" << endl;
    return s.top == MAX - 1;
}

bool push(Stack &s, int x) {// 栈里加东西
    if (full(s)) {
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool pop(Stack &s, int &x) { // 删栈顶的东西
    if (empty(s)) {
        return false;
    }
    x = s.data[s.top--];
    return true;
}

int get_top(Stack s) {
    if (empty(s)) {
        cout << "空的走开";
        return -1;
    }
    // s.data[]
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

