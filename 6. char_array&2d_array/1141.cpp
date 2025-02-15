#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if (s.substr(s.size()-2,2) == "er" or s.substr(s.size()-2,2) == "ly"){
        cout << s.substr(0, s.size() - 2) << endl;
    }else if( s.substr(s.size()-3,3) == "ing"){
        cout << s.substr(0, s.size() - 3) << endl;
    }

}