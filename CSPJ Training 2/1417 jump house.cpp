#include <bits/stdc++.h>
#include <map>
using namespace std;
const int minN = -1e9;
int main(){
    int n,d,k;
    cin >> n >> d >> k;
    int distance, score;
    map<int, int> scores;
    
    scores[0] = 0;
    for(int i=1; i <= n; i++){
        cin >> distance >> score;
        scores[distance] = score;
    }

    int res = 0, local_max;
    while(1){
        map<int, int> maxScores;
        maxScores[0] = 0;
        for (auto [distance, score] : scores){
            local_max = minN;
            for(int i = max(d-res,1); i <= d+res; i++){
                if(scores.count(distance-i) && maxScores.count(distance-i)){
                    local_max = max(local_max, maxScores[distance-i]);
                }
            }
            if (local_max != minN){
                maxScores[distance] = local_max + scores[distance];
                if (maxScores[distance] >= k){
                    cout << res;
                    return 0;
                }
            }
        }
        if (maxScores.size() == n+1){
            cout << -1;
            return 0;
        }
        res ++;
    }
}