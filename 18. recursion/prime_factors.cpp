#include <bits/stdc++.h>
using namespace std;
// 1210�����ӷֽ� http://ybt.ssoier.cn:8088/problem_show.php?pid=1210

/*
    �ݹ�ⷨ
    1. ����n��ǰ������ m��ǰ���ӣ� ������ӷֽ��� ���ַ�����
*/
string dp(int n, int m){
    if(n == m){
        // ���n == m �������һ�ηֽ� ��������n�Լ����ַ�����ʽ
        // to_string(n) �ǰ�int n ת����string���� ������Ҫc++11��֧��
        // ���ｲһ��DEV C++�ı�����֧��c++11�ķ���
        // 1. ��Dev C++ 
        // 2. ���� -> ����ѡ�� -> ������ -> ѡ��ʱ����һ������ ��д -std=c++11
        return to_string(n);
    }
    if(n % m != 0){
        // ��������� �ݹ���һ������
        return dp(n,m+1);
    }
    int cnt = 0; // cnt ��¼��ǰ����m���Ա�n�����Ĵ���
    while(true){
        if(n % m != 0){
            break;
        }
        n /= m; // 24��������˼���m ���Ǿ����Ӽ���cnt
        cnt ++;
    }
    if(cnt == 1){
        return to_string(m) + "*" + dp(n,m+1); // ���cnt == 1 ����Ҫ����Ҫд^1
    }else{
        if (n == 1){
            //����n���һֱ���Ա�m����ֱ��1 ˵���Ѿ��ֽ�����Ҳ����Ҫ�����ݹ���
            return to_string(m) + "^" + to_string(cnt);
        }
        return to_string(m)+"^"+to_string(cnt)+"*"+dp(n,m+1);
    }
}

string prime_factors(int x){
    int cnt;
    string s= "";
    for(int i = 2; i <= x; i++){
        cnt = 0;// ���㵱ǰ������i���Ա�x�����Ĵ��� count
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
        s+= to_string(i); // ��int i ��� string ��i��
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
    //����1 �ݹ�
    cout << dp(x,2) << endl;
    //����2 ѭ��
    cout << prime_factors(x) << endl;
    return 0;
}

