#include <bits/stdc++.h>

using namespace std;



/*
    1207：求最大公约数问题： http://ybt.ssoier.cn:8088/problem_show.php?pid=1207
    递归
    最大公约数的特点
    gcd = greatest common divisor 翻译就是最大公约数
    构建递归函数
    gcd(a,b) 输入a,b 输出a,b的最大公约数

    同余定理 如果存在一个公约数c 使得 A%c == 0; B%c == 0 那么（A-B)%c == 0； （A-B-B)%c == 0；（A%B）%c == 0 (A%B) 可以看成是A被减去多个B的余数
    所以A B 的公约数gcd(A,B) = gcd(B,A%B)
    这样我们成功把A B 转变成一个更小的两个数字 所以可以用到递归

    这时候考虑什么时候退出递归 当 例如 gcd(100, 10) 一个数刚好是另外一个数字的倍数时我们发现 更小的数字自己就是他们的最大公约数
    但是 如果 我们再一次进行递归也是可以的 会发现 gcd(100, 10) == gcd(10, 0)
    所以当最后余数为0时就可以退出递归返回前一个数字
*/

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}
 int main(){
    int a,b;
    cin >> a >> b;
    return gcd(a,b);
 }