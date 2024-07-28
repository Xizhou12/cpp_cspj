/*
1358：中缀表达式值(expr)

时间限制: 1000 ms         内存限制: 65536 KB
提交数:13969    通过数: 4869
【题目描述】
输入一个中缀表达式（由0-9组成的运算数、加+减-乘*除/四种运算符、左右小括号组成。注意“-”也可作为负数的标志，表达式以“@”作为结束符），判断表达式是否合法，如果不合法，请输出“NO”；否则请把表达式转换成后缀形式，再求出后缀表达式的值并输出。

注意：必须用栈操作，不能直接输出表达式的值。

【输入】
一行为一个以@结束的字符串。

【输出】
如果表达式不合法，请输出“NO”，要求大写。
1. /0
2. 括号并不匹配 ）（
3. 1++3
4. +123+32*3
5 （1+）3
如果表达式合法，请输出计算结果。

【输入样例】
1+2*8*9-9@
【输出样例】
8

  
1+4*5-9@ expr = 0+expr
栈 存 push
栈 取 pop -> 进行计算 -> 放回去
栈1 存数字 【1   20】
栈2 存符号 【+ 】 //栈顶如果是+/- 不要直接计算 栈顶是乘除 -> 计算
int res= 0;
res = res -9;
res = res + 144;
res += 1;
cout << res << endl;

*/

#include <iostream>
#include <stack>
#include <string>
int i,j = 0;
#define ERROR 9999999

using namespace std;

int main2(){
//   1.没有括号 
//   2.没有负数
//   3.表达式一定合法
//   4.个位数
    string s;
    stack<char> stk_op; // operator 符号 n-1
    stack<int> stk_num; // number 数字 n
    cin >> s;
    int top_num, cur_num; // top 栈顶数字 cur当前字符串里出现数字
    for(int i =0; i < s.size(); i++){
        if(s[i] == '@'){
            break;
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            stk_op.push(s[i]);
        }else{
            // 当前一定是一个数字
            cur_num = int(s[i]) - 48; // 0 - ascii = 48 atoi // 5
            if (stk_op.top() == '*' ){
                top_num = stk_num.top(); // 4
                stk_num.pop();
                stk_num.push(top_num * cur_num);
                stk_op.pop();
            }else if(stk_op.top() == '/'){
                top_num = stk_num.top();
                stk_num.pop();
                stk_num.push(top_num / cur_num);
                stk_op.pop();
            } else{
                // + -
                stk_num.push(cur_num);
            }
        }
    }
    int res = 0; //最后的运算结果
    while(!stk_op.empty()){
        top_num = stk_num.top();
        if(stk_op.top() == '+'){
            res += top_num;
        }else{
            res -= top_num;
        }
        stk_num.pop();
        stk_op.pop();
    }
    cout << res + stk_num.top() << endl;
}


//  * 123 * 4
// *（1+2）


int recursion(string s){ //递归
    int cur_number, res = 0;
    bool prev_op = true;
    stack<char> stk_op;
    int nums[100];
    nums[0] = 0;
    // 1+3*2-8
    while(s[i] != ')' && s[i] != '@'){
        if (s[i] == '+' || (s[i] == '-' && prev_op == false) || s[i] == '*' || s[i] == '/'){
            if(prev_op == true){
                return ERROR;
            }
            stk_op.push(s[i]);
            prev_op = true;
        } else{
            if (s[i] == '-'){
                // we can not have two consecutive op this - mean negative
                cur_number = -1;
            }else if (s[i] == '(') {
                i++;
                cur_number = recursion(s);
                if(s[i] != ')'){
                    return ERROR;
                }
            }else{
                cur_number = int(s[i]) - 48;
                if(cur_number > 9 || cur_number < 0 || prev_op == false){
                    return ERROR;
                }
            }
            if (stk_op.empty()){
                nums[j] = cur_number;
            }else if (stk_op.top() == '*'){
                stk_op.pop();
                nums[j] = nums[j] * cur_number;
            }else if(stk_op.top() == '/'){
                if (cur_number == 0){
                    return ERROR;
                }
                stk_op.pop();
                nums[j] = nums[j] / cur_number;   
            }else{
                nums[++j] = cur_number;
            }
            prev_op = false;
            if(s[i] == '-'){
                stk_op.push('*');
                prev_op = true;
            }
        }
        i++;
    }
    while(!stk_op.empty()){
        char op = stk_op.top();
        stk_op.pop();
        if (op == '+'){
            res += nums[j--];
        }else{
            res -= nums[j--];
        }
    }
    return nums[j]+res;
}

int main(){
    string s;
    cin >> s;
    int res = recursion(s);
    if (res == ERROR || s[i] != '@'){
        cout << "NO";
        return 0;
    }
    cout << res << endl;
    return 0;
}