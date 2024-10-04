#include <bits/stdc++.h>

using namespace std;
unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int> ring;
bool is_prime(int i){
    return (primes.find(i) != primes.end());
}
int backtrack(int n, vector<int> &used){ // ����
    if(ring.size() == n){ //���Ĵ�С��n��ʱ��
        if(is_prime(ring[0] + ring[n-1])){ // ͷβ���������
            for(int i = 0; i < n; i++){
                cout << ring[i] << " ";
            }
            cout << endl;
            exit(0); // ֱ���˳�����
        } 
    }
    for(int i = 1; i <= n; i++){
        if(ring.empty() || ( is_prime(i+ring[ring.size()-1]) && used[i] == 0)){
            ring.push_back(i);
            used[i] = 1;
            backtrack(n, used);
            used[i] = 0;
            ring.pop_back();
        }
    }
    return -1;
};


int main(){
    
    int n;
    cin >> n;
    vector<int> used = vector<int>(n+1, 0);
    backtrack(n, used);
    cout << "cannot form a prime ring";
}