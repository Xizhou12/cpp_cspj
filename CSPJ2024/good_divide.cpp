#include<bits/stdc++.h>

using namespace std;

int main(){

    int x;
    cin >> x;

    if ( x% 2 ==1){
        cout << -1;
        return 0;
    }


    while (x != 0){
        int div = 2;
        while (div <=x){
            div *=2;
        }
        cout << div/2 << " ";
        x -= div/2;
    }

    return 0;
}
