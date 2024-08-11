#include <bits/stdc++.h>

using namespace std;



/*
    1207�������Լ�����⣺ http://ybt.ssoier.cn:8088/problem_show.php?pid=1207
    �ݹ�
    ���Լ�����ص�
    gcd = greatest common divisor ����������Լ��
    �����ݹ麯��
    gcd(a,b) ����a,b ���a,b�����Լ��

    ͬ�ඨ�� �������һ����Լ��c ʹ�� A%c == 0; B%c == 0 ��ô��A-B)%c == 0�� ��A-B-B)%c == 0����A%B��%c == 0 (A%B) ���Կ�����A����ȥ���B������
    ����A B �Ĺ�Լ��gcd(A,B) = gcd(B,A%B)
    �������ǳɹ���A B ת���һ����С���������� ���Կ����õ��ݹ�

    ��ʱ����ʲôʱ���˳��ݹ� �� ���� gcd(100, 10) һ�����պ�������һ�����ֵı���ʱ���Ƿ��� ��С�������Լ��������ǵ����Լ��
    ���� ��� ������һ�ν��еݹ�Ҳ�ǿ��Ե� �ᷢ�� gcd(100, 10) == gcd(10, 0)
    ���Ե��������Ϊ0ʱ�Ϳ����˳��ݹ鷵��ǰһ������
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