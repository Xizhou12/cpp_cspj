#include <bits/stdc++.h>

using namespace std;
int backtrack(int n, unordered_set<int> primes, vector<int> ring, vector<int> &used){
    if(ring.size() == n){
        if(primes.find(ring[0] + ring[n-1]) != primes.end()){
            for(int i = 0; i < n; i++){
                cout << ring[i] << " ";
            }
            cout << endl;
            exit(0);
        } 
    }
    for(int i = 1; i <= n; i++){
        if(ring.empty() || (primes.find(i + ring[ring.size()-1]) != primes.end() && used[i] == 0)){
            ring.push_back(i);
            used[i] = 1;
            backtrack(n, primes, ring, used);
            used[i] = 0;
            ring.pop_back();
        }
    }
    return -1;
}

int main(){
    unordered_set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,43,47,53,59,61,67,71,73,79,83,89,97};
    int n;
    cin >> n;
    vector<int> ring;
    vector<int> used = vector<int>(n+1, 0);
    backtrack(n, primes, ring, used);
    cout << "cannot form a prime ring";
}