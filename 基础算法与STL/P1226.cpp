#include <bits/stdc++.h>
using namespace std;
#define int long long

#define PII pair<int, int>

int ksm(int a, int b, int p) {
    int res = 1;
    a %= p;
    while (b) {
        if (b % 2) {
            res = res * a % p;
        }
        a = a * a % p;
        b /= 2;
    }
    return res % p;
}

void solve() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << ksm(a, b, p) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}