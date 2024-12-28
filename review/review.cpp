#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    int a = 7, b = 5, c = 3, d = 1;
    
    // a | b ^ c & d
    int result1 = a | b ^ c & d;
    // a | (b ^ (c & d))
    int result2 = a | (b ^ (c & d));
    
    cout << "result1: " << result1 << endl;
    cout << "result2: " << result2 << endl;

    return 0;
}