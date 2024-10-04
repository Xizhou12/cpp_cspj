
#include<bits/stdc++.h>

using namespace std;

bool check_ip(string addr){
    string temp = "";
    for(char c: addr){
        if(c == '.' || c == ':'){
            if (temp.size() > 1 || temp[0] == '0'){
                return 0;
            }
            int ip_grp = stoi(temp);
            if(ip_grp > 255 || ip_grp < 0){
                return 0;
            }
            temp = "";
        }
        else{
            temp += c;
        }
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
    unordered_map<string, int> server; // Valid Server with number of connecting clients
    cin >>  n;
    while(n--){
        cin >> op >>addr;
        // Check if ip is valid
        if(check_ip(addr) == 0){
            cout << "ERR" << endl;
            return 0;
        }
        if (op == "Server"){
            if(server.find(addr) == server.end()){
                server[addr] = 0;
                cout << "OK" << endl;
            }else{
                cout << "FAIL" << endl;
            }
        }else{      //Client
            if(server.find(addr) == server.end()){
                cout << "FAIL" << endl;

            }else{
                server[addr]++;
                cout << server[addr] << endl;
            }
        }
    }
    return 0;
}
