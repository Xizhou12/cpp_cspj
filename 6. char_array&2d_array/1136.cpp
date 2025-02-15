#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    for ( char c: s){
        if(isalpha(c)){
            if(islower(c)){
                cout << char((c+1) > 'z' ? c-25 : c+1);
            }else{ // isupper
                cout << char((c+1) > 'Z' ? c-25 : c+1);
            }
            
        }else{
            cout << c;
        }
        
    }
    return 0;
}