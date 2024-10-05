#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int res = 0;
    for(char c : s){
        if(c == ' ' || c =='\t' ){
            continue;
        }
        res ++;
    }
    cout << res;
}