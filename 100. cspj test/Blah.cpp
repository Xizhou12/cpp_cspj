#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <stdlib.h>

using namespace std;
struct Compare{
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    int cur, element, pos, j=0;
    int ans[100];
    set<int> s;
    priority_queue<int, vector<int>, Compare> pq, empty_pq;
    while(cin >> element >> pos){
        pq.push(element);
        for(int i = 0; i < pos; i ++){
            cur = pq.top();
            pq.pop();
            int num1 = 2*cur+1;
            int num2 = 3*cur+1;
            if(!s.count(num1)){ 
                pq.push(num1);
                s.insert(num1);
            }
            if(!s.count(num2)){
                pq.push(num2);
                s.insert(num2);
            }
        }
        ans[j++] = cur;
        s.clear();
        pq.swap(empty_pq); // clear
        
    }
    for(int i = 0; i < j; i++){
        cout << ans[i] << endl;
    }
}  