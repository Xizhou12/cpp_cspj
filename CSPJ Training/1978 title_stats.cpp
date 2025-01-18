#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    /*
        fgets 读取到包括最后一个换行符号
        getline 读取不包括最后一个换行符
    */
    char s[100];
    fgets(s, 100, stdin); // c++
    int res = 0;
    cout << strlen(s) << endl;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ' ' || s[i] =='\n' ){
            continue;
        }
        res ++;
    }
    cout << res;
}