
#include <bits/stdc++.h>

using namespace std;

int bs_1(int low, int high, int arr[], int target){
    /*
        在 arr数组的 low和high之间寻找target
        如果能找到返回target的位置 否则返回-1
        版本1当中 low ~ high是数组内需要被寻找的范围
    */
    while(low <= high){ // 如果这里不用 <= 那么high有可能没有被查询到
        // 由于cpp 除法是向下取整 所以当low < high不相同时 mid永远不会等于high(high又是我们查询的范围) -> 导致了上面循环的条件我们需要让low==high的时候也能够进行查询
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
        版本2 low ~ high - 1才是数组内需要被寻找的范围
        注意high并不是我们查询的范围 所以通常high是作为已经被查询的下标或是作为数组的长度size（size-1 才是最后一个元素的下标）
    */
   int n = high; // 最开始的时候 high是数组的长度
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
        版本3 low ~ high 是数组内需要被寻找的范围
        但是mid不会是low和high 代表了在最后我们需要去检查low和high是否是我们需要查找的值
    */
    while (low + 1 < high){ // 这个条件确定了 low 和high值的差至少为2 所以他们的mid一定不会是low和high
        int mid = low + (high - low) / 2;
        if (target == arr[mid]){
            return mid;
        }else if(target < arr[mid]){
            high = mid; // high并没有被查询过继续放在范围内
        }else{
            low = mid; // low并没有被查询过继续放在范围内
        }
    }
    // 最后有可能我们并没有查过low和high 例如 {1，3，5} 我们只查询了3就会结束循环 若target=1 low就没有被检查过 如果target=5 high就没有被检查过 所以low和 high都有可能是该值
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