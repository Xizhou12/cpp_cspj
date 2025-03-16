// #include <bits/stdc++.h>
// using namespace std;
// #include <iostream>

// void counter() {
//     static int count = 0; // Static local variable
//     count++;
//     std::cout << "Count: " << count << std::endl;
// }

// int main() {
//     counter(); // Output: Count: 1
//     counter(); // Output: Count: 2
//     counter(); // Output: Count: 3
//     return 0;
// }

#include<bits/stdc++.h>
 
using namespace std;

char a[10000];

void dao(int n){
    if(a[n] == '!'){
        return;
    }
    dao(n+1);
    cout << a[n];
}
int main(){
   cin >> a;
   dao(0);
   return 0;
}
