
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, Q;
    int op;
    int x,v;
    int cur;
    int res;
    cin >> n >> Q;
    int a[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int q = 0; q < Q; q++){
        cin >> op;
        if (op == 1){
            cin >> x >> v;
            a[x] = v;
        }else{ // op == 2
            cin >>x;
            res = x;
            for(int i = 1; i < x; i++){
                if (a[i] > a[x]){
                    res--;
                }
            }
            for(int i = n; i > x; i--){
                if (a[i] < a[x]){
                    res++;
                }
            }
            cout << res <<endl;
        }
    }
    return 0;
}
