#include <bits/stdc++.h>

using namespace std;
int double_algo(int target, vector<int> v){
    int low = 0;
    int high = v.size();
    while(low + 1 < high){
        int mid = low + (high - low) / 2;
        if(v[mid] >= target){
            high = mid;
        }else{
            low = mid;
        }
    }
    return high;
}
int main(){
    vector<int> v;
    for(int i = 0; i < 1000000; i++){
        v.push_back(1);
    }
    for(int i = 2; i < 1000000; i++){
        v.push_back(i);
    }

    int target = 987654;// 我们想要找第一个大于等于987654的数
}

