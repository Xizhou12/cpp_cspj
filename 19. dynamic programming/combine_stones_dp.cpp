
/*
1274：【例9.18】合并石子

时间限制: 1000 ms         内存限制: 65536 KB
提交数:18745    通过数: 12511
【题目描述】
在一个操场上一排地摆放着Ｎ堆石子。现要将石子有次序地合并成一堆。规定每次只能选相邻的２堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的得分。

计算出将Ｎ堆石子合并成一堆的最小得分。

【输入】
第一行为一个正整数N (2≤Ｎ≤100)；

以下Ｎ行,每行一个正整数，小于10000，分别表示第i堆石子的个数(1≤i≤N)。

【输出】
一个正整数，即最小得分。

【输入样例】
7
13
7
8
16
21
4
18
【输出样例】
239
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N];
int stones[N];
int prefix_sum[N]; // 前缀和

int main(){
  int n;
  cin >> n; //有n堆石头吧
  int sum = 0; // 当前总和
  for(int i = 1; i <= n; i++){
    cin >> stones[i];
    sum += stones[i];
    prefix_sum[i] = sum;
  }
  for(int i = 0; i <= n+1; i++){
    dp[i][i] = 0; // 从第i堆合并到第i堆事不需要合并的
  } 

  for(int i = n; i >= 1; i--){
    for(int j = i+1; j <= n; j++){
      dp[i][j] = 10000000; //
      for(int k = i; k < j; k++){
        // 这个是当前k值的最优解
        int cur_perfect_score = dp[i][k] + dp[k+1][j] + prefix_sum[j] - prefix_sum[i-1];
        dp[i][j] = min(dp[i][j], cur_perfect_score);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for (int j = 1; j <=n ; j++){
      printf("%3d ", dp[i][j]);
    }
    cout << endl;
  }
  cout << dp[1][n];
}