#include <bits/stdc++.h>

using namespace std;
// int n = 1000000;
// int a[1000000];//����a��һ�����������

// int build_randomized_no_repeat_ordered_a(){
//     // ����һ���������������
//     srand(time(0));
//     a[0] = rand() % 23;
//     for(int i = 1; i < n; i++){
//         a[i] = a[i-1] + rand() % 23 + 1;
//     }
//     return n;
// }
int x[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,31,32,34,37,100,102,145};
int double_algo(){
    int low = -1;
    int target = 99;
    int n = sizeof(x) / sizeof(x[0]);
    int p = 1; // �����ķ�Χ
    while(true){
        if(low + p < n && x[low+p] < target){
            p <<= 1; // p*=2, p = p*2;
        }else{
            // cout << low;
            if(p == 1) return low+p;
            p >>= 1;// p/=2
            low = low + p;
            p = 1;
        }
    }
}

int main(){
    cout << x[double_algo()] << endl;

    // build_randomized_no_repeat_ordered_a();
    
    // int lo=-1;
    // int inc=1;
    // int target = 975624; // ������Ҫ������a���ҵ���һ�����ڵ���target����
    // while(lo + 1 < n)
    // {   
    //     if(a[lo+inc]<target){
    //         inc<<=1;//�ɱ��������൱��inc*=2
    //     }else{
    //         if(inc==1)break;//���inc=1��˵���Ѿ��ҵ���
    //         inc>>=1;//��С��Χ
    //         lo += inc;
    //         inc = 1;
    //     }
    // }
    
    // cout << a[lo+inc] << ", �±���" << lo+inc << endl;
    // cout << endl; 
    // // verify ��֤
    // cout << "��֤" << endl;
    // for(int i = 0; i < 100000; i++){
    //     if(a[i] >= target){
    //         cout << a[i] << ", �±���" << i;
    //         break;
    //     }
    // }
}

