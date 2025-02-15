#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(isdigit(s[0])){
        cout << "no" << endl;
        return 0;
    }
    for (char c: s){
        if(isalnum(c) or c == '_'){
            continue;
        }
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;
    return 0;
}