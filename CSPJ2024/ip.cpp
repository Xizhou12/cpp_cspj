
#include <bits/stdc++.h>
using namespace std;

bool check_ip(string addr){
    int dot_count=0;
    string temp = "";
    for(char c: addr){
        if(c == '.'){
            dot_count++;
            if(dot_count > 3){
                return false;
            }
        }else if(c == ':'){
            if(dot_count < 3){
                return false;
            }
        }
        if(c == '.' || c == ':'){
            if (temp.size() > 1 && temp[0] == '0'){
                return 0;
            }
            int ip_grp = stoi(temp); //string -> int
            if(ip_grp > 255 || ip_grp < 0){
                return 0;
            }
            temp = "";
        }
        else{
            temp += c;
        }
    }
    if (temp.size() > 1 && temp[0] == '0'){
        return 0;
    }
    int ip_grp = stoi(temp);
    if(ip_grp > 65535 || ip_grp < 0){
        return 0;
    }
    
    return 1;
}
int main(){
    int n;
    string op, addr;
    map<string, int> server; // Valid Server with number of connecting clients
    cin >>  n;
    int total = n;
    while(n--){
        cin >> op >>addr;
        // Check if ip is valid
        if(check_ip(addr) == 0){
            cout << "ERR" << endl;
            continue;
        }
        if (op == "Server"){
            if(!server.count(addr)){
                // 这个代表没有在map找到当前addr
                server[addr] = total-n;
                cout << "OK" << endl;
            }else{
                cout << "FAIL" << endl;
            }
        }else{      //Client
            if(!server.count(addr)){
                // 这个代表没有在map找到当前addr
                cout << "FAIL" << endl;

            }else{
                cout << server[addr] << endl;
            }
        }
    }
    return 0;
}

