
#include <bits/stdc++.h>
using namespace std;

bool check_ip(string addr){
    int dot_count=0, colon_count =0, ip_grp;
    string temp = "";
    for(char c: addr){
        if(c == '.'){
            dot_count++;
        }else if(c == ':'){
            if(dot_count < 3){
                return false;
            }
            colon_count++;
        }
        if(c == '.' || c == ':'){
            if (temp.size() > 1 && temp[0] == '0'){
                return 0;
            }
            if (temp.size() != 0 && temp.size() <= 5) 
                ip_grp = stoi(temp); //string -> int
            else{
                return 0;
            }
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
    if (temp.size() != 0 && temp.size() <= 5) 
        ip_grp = stoi(temp); //string -> int
    else{
        return 0;
    }
    if(ip_grp > 65535 || ip_grp < 0){
        return 0;
    }
    if(dot_count != 3 || colon_count != 1){
        return false;
    }
    return 1;
}
int main(){
    freopen("ip.in","r",stdin);//r=read
	freopen("ip.out","w",stdout);//w=write
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
    fclose(stdin);
	fclose(stdout);
    return 0;
}

