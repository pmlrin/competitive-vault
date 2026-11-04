#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    cout << "call f(" << x << ")" << endl;
    if (x == 0) {
        return 1;
    }
    return x * f(x - 1);
}

int main() {
    cout << f(3) << endl;
    return 0;
}