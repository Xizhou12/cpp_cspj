
#include <bits/stdc++.h>

using namespace std;

int bs_1(int low, int high, int arr[], int target){
    /*
        �� arr����� low��high֮��Ѱ��target
        ������ҵ�����target��λ�� ���򷵻�-1
        �汾1���� low ~ high����������Ҫ��Ѱ�ҵķ�Χ
    */
    while(low <= high){ // ������ﲻ�� <= ��ôhigh�п���û�б���ѯ��
        // ����cpp ����������ȡ�� ���Ե�low < high����ͬʱ mid��Զ�������high(high�������ǲ�ѯ�ķ�Χ) -> ����������ѭ��������������Ҫ��low==high��ʱ��Ҳ�ܹ����в�ѯ
        int mid = low + (high - low) / 2; 
        if (target == arr[mid]){
            return mid;
        }else if(target < arr[mid]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int bs_2(int low, int high, int arr[], int target){
    /*
        �汾2 low ~ high - 1������������Ҫ��Ѱ�ҵķ�Χ
        ע��high���������ǲ�ѯ�ķ�Χ ����ͨ��high����Ϊ�Ѿ�����ѯ���±������Ϊ����ĳ���size��size-1 �������һ��Ԫ�ص��±꣩
    */
   int n = high; // �ʼ��ʱ�� high������ĳ���
    while ( low < high){
        int mid = low + (high - low) / 2;
        if (target == arr[mid]){
            return mid;
        }else if(target < arr[mid]){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int bs_3(int low, int high, int arr[], int target){
    /*
        �汾3 low ~ high ����������Ҫ��Ѱ�ҵķ�Χ
        ����mid������low��high �����������������Ҫȥ���low��high�Ƿ���������Ҫ���ҵ�ֵ
    */
    while (low + 1 < high){ // �������ȷ���� low ��highֵ�Ĳ�����Ϊ2 �������ǵ�midһ��������low��high
        int mid = low + (high - low) / 2;
        if (target == arr[mid]){
            return mid;
        }else if(target < arr[mid]){
            high = mid; // high��û�б���ѯ���������ڷ�Χ��
        }else{
            low = mid; // low��û�б���ѯ���������ڷ�Χ��
        }
    }
    // ����п������ǲ�û�в��low��high ���� {1��3��5} ����ֻ��ѯ��3�ͻ����ѭ�� ��target=1 low��û�б����� ���target=5 high��û�б����� ����low�� high���п����Ǹ�ֵ
    if (arr[low] == target) return low;
    if (arr[high] == target) return high;
    return -1;
}

int main(){
    int arr[] = {1, 2,3,4,6,6,7,10,100,1000,10000,999999};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    int result = bs_1(0, n-1, arr, target);
    cout << result << endl;
    result = bs_2(0, n, arr, target);
    cout << result << endl;
    result = bs_3(0, n-1, arr, target);
    cout << result << endl;
    return 0;
}