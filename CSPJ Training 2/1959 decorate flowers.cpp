#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1007;
long long dp[MAXN][MAXN];
int main(){
    int type, total;
    cin >> type >> total;

    // dp[i][j] is the number of ways to decorate a total of i flowers with j types of flowers
    
    int limits[type+1];
    for(int i = 1; i <= type; i++){
        cin >> limits[i];
    }
    for(int j = 1; j <= type; j++){
        // to decorate 0 flowers for j types of flowers, there is only 1 way
        dp[0][j] = 1;
    }

    // goal is to calculate dp[total][type]
    
    for(int j = 1; j <= type; j++){
        int limit = limits[j];
        for(int i = 1; i <= total; i ++){
            if(j - 1 == 0){
                if (limit >= i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }else{
                dp[i][j] = 0;
                for(int k = 0; k <= min(limit, i); k++){
                    dp[i][j] += dp[i-k][j-1];
                }
                dp[i][j] %= 1000007;
            }
        }
    }
    cout << dp[total][type] % 1000007;
}