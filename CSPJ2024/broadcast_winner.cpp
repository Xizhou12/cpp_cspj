#include<bits/stdc++.h>

using namespace std;

const int TOTAL = 601;
int count_bucket[TOTAL];

int main(){
    int n,w;
    int score;
    int ppl = 0;
    int win_count;
    int cur_win_cnt;
    cin >> n >>w;
    for(int i = 0; i < n; i++){
        scanf("%d", &score);
        count_bucket[score] ++;
        ppl++;
        win_count = max(1, ppl*w / 100);
        cur_win_cnt = 0;
        int cur_score = TOTAL;
        while(cur_win_cnt < win_count){
            cur_score--;
            cur_win_cnt += count_bucket[cur_score];

        }
        printf("%d ", cur_score);

    }
    return 0;
}
