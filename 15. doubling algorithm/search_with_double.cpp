#include <bits/stdc++.h>

using namespace std;
int n = 1000000;
int a[1000000];//假设a是一个有序的数组

int build_randomized_no_repeat_ordered_a(){
    // 生成一个随机的有序数组
    srand(time(0));
    a[0] = rand() % 23;
    for(int i = 1; i < n; i++){
        a[i] = a[i-1] + rand() % 23 + 1;
    }
    return n;
}

int main(){
    build_randomized_no_repeat_ordered_a();
    
    int lo=0;
    int inc=1;
    int target = 975624; // 我们想要在数列a中找到第一个大于等于12的数
    while(lo + 1 < n)
    {   
        if(a[lo+inc]<target){
            inc<<=1;//成倍增长，相当于inc*=2
        }else{
            if(inc==1)break;//如果inc=1，说明已经找到了
            inc>>=1;//缩小范围
            lo += inc;
            inc = 1;
        }
    }
    
    cout << a[lo+inc] << ", 下标是" << lo+inc << endl;
    cout << endl; 
    // verify 验证
    cout << "验证" << endl;
    for(int i = 0; i < 100000; i++){
        if(a[i] >= target){
            cout << a[i] << ", 下标是" << i;
            break;
        }
    }
}

