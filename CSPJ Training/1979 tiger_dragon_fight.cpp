#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int total_encampments, neutral_camp, p1, s1, s2; // 总的营地数
    cin >> total_encampments;
    int military_power[total_encampments+1]; // 每个营地的军事力量
    for (int camp = 1; camp <= total_encampments; camp++){
        cin >> military_power[camp];
    }
    cin >> neutral_camp >> p1 >> s1 >> s2; // 中立营地的位置，p1 s1 s2
    military_power[p1] += s1;
    ll mili_tiger =0, mili_dragon = 0;
    for(int i = 1; i <= total_encampments; i++){
        if(i < neutral_camp){
            mili_tiger += (ll) military_power[i]*(neutral_camp-i); // 这里需要转化成ll
        }else if(i > neutral_camp){
            mili_dragon += (ll) military_power[i]*(i-neutral_camp);
        }
    }
    int res;
    ll mili_diff = mili_tiger - mili_dragon;
    if (mili_diff % s2  == 0.5 * s2){
        res = mili_diff / s2 + neutral_camp;
    }else{
        res = round( (double) (mili_diff) / s2) + neutral_camp;
    }
    res = max(res,1);
    res = min(res, total_encampments);
    cout << res << endl;
    
}