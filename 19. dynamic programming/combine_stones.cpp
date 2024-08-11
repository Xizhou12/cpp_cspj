#include <bits/stdc++.h>
using namespace std;
int stones[105] = {0};
int min_combine[105] = {0};
int prefix_sum[105] = {0};
/*
    1 1 3 3
    2 3 3     2
    5 3       7
    8        15
*/
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

int combine2(int hi){
    if (hi == 0){
        min_combine[0] = 0;
    }else if (hi == 1){
        min_combine[1] = stones[0] + stones[1];
    }else{
        if (min_combine[hi] != 0){
            return min_combine[hi];
        }
        min_combine[hi] = 100 * 10000;
        for (int i = hi-1; i >= 0; i--){
            min_combine[hi] = min(min_combine[hi], combine2(i) + combine(i+1, hi) + prefix_sum[hi]);
        }
    }
    return min_combine[hi];
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
    cout << combine2(n-1) << endl;
} 

