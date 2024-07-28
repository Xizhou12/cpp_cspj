/*
【题目描述】
假设一个表达式有英文字母（小写）、运算符（+，—，∗，/）和左右小（圆）括号构成，以“@”作为表达式的结束符。
请编写一个程序检查表达式中的左右圆括号是否匹配，若匹配，则返回“YES”；否则返回“NO”。表达式长度小于255，左圆括号少于20个。

【输入】
一行数据，即表达式。

【输出】
一行，即“YES” 或“NO”。

【输入样例】
2*(x+y)/(1-x)@
【输出样例】
YES
【提示】
【样例输入2】
(25+x)*(a*(a+b+b)@
【样例输出2】
NO
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            // （))）
            if (st.empty()) {
                // 没有可以对应的左括号
                cout << "NO" << endl;
                return 0;
            }
            st.pop();
        }
    }
    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}