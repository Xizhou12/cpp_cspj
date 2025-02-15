#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int max_size = 0;
    string max_length_string;
    while(1){
        cin >> s;
        if(s[s.size()-1] == '.'){
            s = s.substr(0, s.size()-1);
            if(s.size() > max_size){
                max_size = s.size();
                max_length_string = s;
            }
            break;
        }
        if(s.size() > max_size){
            max_size = s.size();
            max_length_string = s;
        }
    }
    cout << max_length_string << endl;
    return 0;
}