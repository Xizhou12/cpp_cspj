#include <bits/stdc++.h>
using namespace std;

// 快速排序步骤
/*
    1. 每次挑选最后一个点 作为我们的pivot
    2. 我们要保证在第一次 排序的时候 让这个pivot就到达它排完序的位置 并且它的左边的数字都比他小 他的右边的数都比他大
        在步骤2 当中 我们对 从第一个数开始到 pivot-1的数进行比较 并且初始化 i=-1
        如果发现当前j位置的数字比 pivot要小 
            那么i++
            并且让 i和j位置的数字进行交换
        这个过程我们可以确保 位置 <= i 的数字都是比 pivot要小的
    3. 快速排序左边的那些并未排序的数字 快速排序右边那些并未排序的数字 （递归）

    1. 排 3 （p)
    2. 排 3 左边的数组
    3. 排 3 右边的数组

*/

void quick_sort(int arr[], int low, int high){
    // 可以帮我们把这个数组内从低到高的数字进行排序 low=低，high=高
    // 1 4 2 6 5 10 3
    int pivot = arr[high];
    int i= -1;
    for(int j = low; j <= high-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]); //交换
            /*
                int temp = arr[i];
                arr[j] = arr[i];
                arr[i] = temp;
            */
        }
    }
    // 1 2 4 6 5 10 || 3
    // i=1 arr[i]=2现在是多少
    // pivot 应该换到 i+1这个位置把
    swap(arr[high], arr[i+1]);
    // 1 2  [3] 4 6 5 10
    quick_sort(arr, low, i);
    quick_sort(arr, i+2, high);
}

int main()
{
    int arr[] = {4, 2, 10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}