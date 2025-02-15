#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
long long dp[N][N];
int main(){
  int n, m; // n是花的总数， m是花的种类
  cin >> m >> n;
  int limits[n];
  for(int j = 1; j<=m; j++){
    cin >> limits[j];
  }
  for(int j = 1; j<=m; j++){
    dp[0][j] = 1;
  }
  for(int j = 1; j<=m; j++ ){
    for(int i = 1; i <= n; i++){
      if(j == 1){
        if(i <= limits[j]){
          dp[i][j] = 1;
        }else {
          dp[i][j] = 0;
        }
      }else{
        for(int k = 0; k <= limits[j] && i - k >= 0; k++){
          dp[i][j] += dp[i-k][j-1];
        }
        dp[i][j] %= 1000007;
      }
    }
  }
  cout << dp[n][m];

  return 0;
}