
#include <bits/stdc++.h>

using namespace std;

template <typename T>
int max3(T a, T b, T c) {
    return max(a, max(b, c));
}
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(3) << float (max3(a,b,c)) / (max3(a+b,b,c)*max3(a,b,b+c)) << endl;
}