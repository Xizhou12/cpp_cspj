#include <bits/stdc++.h>
using namespace std;
// 1210：因子分解 http://ybt.ssoier.cn:8088/problem_show.php?pid=1210

/*
    递归解法
    1. 输入n当前被除数 m当前因子， 输出因子分解结果 （字符串）
*/
string dp(int n, int m){
    if(n == m){
        // 如果n == m 进行最后一次分解 返回数字n自己的字符串形式
        // to_string(n) 是把int n 转换成string类型 这里需要c++11的支持
        // 这里讲一下DEV C++的编译器支持c++11的方法
        // 1. 打开Dev C++ 
        // 2. 工具 -> 编译选项 -> 编译器 -> 选择时加入一下命令 填写 -std=c++11
        return to_string(n);
    }
    if(n % m != 0){
        // 如果除不尽 递归下一个因子
        return dp(n,m+1);
    }
    int cnt = 0; // cnt 记录当前因子m可以被n整除的次数
    while(true){
        if(n % m != 0){
            break;
        }
        n /= m; // 24行这里除了几次m 我们就增加几次cnt
        cnt ++;
    }
    if(cnt == 1){
        return to_string(m) + "*" + dp(n,m+1); // 如果cnt == 1 按照要求不需要写^1
    }else{
        if (n == 1){
            //这里n如果一直可以被m整除直到1 说明已经分解完了也不需要继续递归了
            return to_string(m) + "^" + to_string(cnt);
        }
        return to_string(m)+"^"+to_string(cnt)+"*"+dp(n,m+1);
    }
}

string prime_factors(int x){
    int cnt;
    string s= "";
    for(int i = 2; i <= x; i++){
        cnt = 0;// 计算当前被除数i可以被x整除的次数 count
        while(true){
            if(x % i != 0){
                break;
            }
            x = x / i;
            cnt++;
        }
        if(cnt == 0){
            continue;
        }
        s+= to_string(i); // 把int i 编程 string “i”
        if(cnt > 1){
            s+="^"+to_string(cnt);
        }
        s+="*";
    }
    return s.substr(0, s.size()-1);
}

int main(){
    int x;
    cin >> x;
    //方法1 递归
    cout << dp(x,2) << endl;
    //方法2 循环
    cout << prime_factors(x) << endl;
    return 0;
}

