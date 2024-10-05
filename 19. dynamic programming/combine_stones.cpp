
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
int stones[105] = {0};
int min_combine[105] = {0};
int prefix_sum[105] = {0};
int combine(int low, int hi){
    if (low  == hi){
        return 0;
    }
    int min = 100 * 10000;
    int score = 0;
    for (int i = low; i < hi; i++){
        score += stones[i];
        int temp = combine(low, i) + combine(i+1, hi);
        if (temp < min){
            min = temp;
        }
    }
    return min+score+stones[hi];
}

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> stones[i];
        prefix_sum[i] = sum+stones[i];
        sum+=stones[i];
    }
    cout << combine() << endl;
} 

