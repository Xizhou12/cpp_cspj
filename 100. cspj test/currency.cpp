#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int currency_type[n];
    long long dp[m+1] = {0};
    for(int i = 0; i < n; i++){
        cin >> currency_type[i];
    }
    sort(currency_type, currency_type + n);
    for(int i = 0; i < n; i++){
        dp[currency_type[i]] += 1;
        for(int j = currency_type[i]; j <= m; j++){
            dp[j] = dp[j] + dp[j - currency_type[i]];
        }
    }
    // for(int i = 1; i <= m; i++){
    //     cout << dp[i] << " ";
    // }
    cout << dp[m] << endl;

}