#include <bits/stdc++.h>

using namespace std;
int n = 1000000;
int a[1000000];//����a��һ�����������

int build_randomized_no_repeat_ordered_a(){
    // ����һ���������������
    // ����Ȥ���Կ�һ�� ���Ǽ򵥽����� ��a������и��� ����һ�����������
    srand(time(0));
    a[0] = rand() % 23;
    for(int i = 1; i < n; i++){
        a[i] = a[i-1] + rand() % 23 + 1;
    }
    return n;
}

int main(){
    build_randomized_no_repeat_ordered_a();
    
    int lo=-1;
    int inc=1;
    int target = 975624; // ������Ҫ������a���ҵ���һ�����ڵ���target����
    while(true)
    {   
        if(lo+inc < n && a[lo+inc]<target){
            // ���lo+inc��Խ���鳤�Ȼ����Խ����� ������Ҫ����ǰ�������
            inc<<=1;//�ɱ��������൱��inc*=2
        }else{
            if(inc==1)break;//���inc=1��˵���Ѿ��ҵ���
            inc>>=1;//��С��Χ
            lo += inc; //����lo = inc��������Ϊ ����lo��� lo������0���λ��
            inc = 1;
        }
    }
    cout << a[lo+inc] << ", �±���" << lo+inc << endl;
    cout << endl; 
    
    // verify ����ͨѭ����֤
    cout << "��֤" << endl;
    for(int i = 0; i < 100000; i++){
        if(a[i] >= target){
            cout << a[i] << ", �±���" << i;
            break;
        }
    }
}

