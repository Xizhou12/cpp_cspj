#include<bits/stdc++.h>
using namespace std;
const int N = 500;
int compare(string a, string b){
    return a.size() > b.size();
}
int main(){
    string s[N];
    int i = 0;
    while(1){
        cin >> s[i];
        if(s[i][s[i].size()-1] == '.'){
            s[i] = s[i].substr(0, s[i].size()-1);
            break;
        }
        i++;
    }
    stable_sort(s, s+i+1, compare);
    cout << s[0] << endl;
    return 0;
}