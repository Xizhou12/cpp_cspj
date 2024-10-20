#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+7;
int N, C;
int fences[MAXN];
int check(int mid){
    // check if separating cows with distance mid is possible
    int count = 1;
    int last = fences[1];
    for(int i = 2; i <= N; i++){
        if(fences[i] - last >= mid){
            count ++;
            last = fences[i];
        }
    }
    cout << mid << " " << count << endl;
    return count >=C;
}
int main(){
    cin >> N >> C;
    for(int i = 1; i <= N; i++){
        cin >> fences[i];
    }
    sort(fences+1, fences+N+1);
    int l = 1, r = fences[N] - fences[1]; // l is the min distance to separate cows, r is the max distance to separate cows(exclusive)
    while(l < r){
        int mid = (l+r+1) >> 1;
        if(check(mid)){
            // different is that here we cannot determine mid while mid can still be the answer 
            l = mid;
        }else{
            r = mid-1;
        }
    }
    cout << l;
}