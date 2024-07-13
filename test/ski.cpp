#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000;
struct CompareHeight {
    bool operator()(const pair<tuple<int, int>, int>& lhs, const pair<tuple<int, int>, int>& rhs) const {
        // Compare heights; for min heap, use less than
        return lhs.second > rhs.second;
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    int heights[n][m];
    int dp[n][m] = {0};
    bool visited[n][m] = {false};
    priority_queue<pair<tuple<int, int>, int>, vector<pair<tuple<int, int>, int>>, CompareHeight> pq;
    map<tuple<int,int>, int> pos_h;
    for( int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin >> heights[i][j];
        }
    }
    
    for(int j = 0; j < m; j++){
        int h = heights[0][j];
        dp[0][j] = 1;
        pair<tuple<int, int>, int> p = make_pair(make_tuple(0,j), h);
        pos_h.emplace(p);
        pq.push(p);
        visited[0][j] = true;
    }
    
    while(!pq.empty()){
        pair<tuple<int,int>, int> p = pq.top();
        int height = p.second;
        int i = get<0>(p.first);
        int j = get<1>(p.first);
        pq.pop();
        for( auto x : {make_tuple(0,1), make_tuple(0,-1), make_tuple(1,0), make_tuple(-1,0)}){
            int next_i = i + get<0>(x);
            int next_j = j + get<1>(x);
            int next_h = heights[next_i][next_j];
            if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && next_h < heights[i][j]){
                dp[next_i][next_j] += dp[i][j];
                pair<tuple<int, int>, int> p = make_pair(make_tuple(next_i, next_j), next_h);
                pos_h.emplace(p);
                if (next_i != 0 && !visited[next_i][next_j]){
                    pq.push(p);
                    visited[next_i][next_j] = true;
                }
            }
        }
    }
    int res = 0;
    for(int j = 0; j < m; j++){
        res += dp[n-1][j];
    }
    cout << res << endl;
}
