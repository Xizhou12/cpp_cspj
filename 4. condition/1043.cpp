#include <iostream>
using namespace std;


int force_cast(){
    int x = -10;
    unsigned int y = 5;
    int sum =  x + y;
    cout << x + y << endl;
    cout << sum << endl;

    char a = 'A';
    cout << a + 10 << endl;
    return 0;
}

int main() {
    // force_cast();
    // int age = 18;
    // string status = (age >= 18) ? "成年人" : "未成年人";
    // cout << status << endl;

    long long s = 0;
    int n;
    cin >> n;
    int p = 1;
    for(int i = 1; i <= n; i++){
        p = (p % 1000000) * i;
        s += p;
    }
    s %= 1000000;
    cout << s << endl;
    return 0;
}