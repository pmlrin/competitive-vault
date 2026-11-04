#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1000000 + 50, inf = 1145141919810, mod = 1000000000 + 7;

ll n, f[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    f[1][1] = 1;
    f[1][0] = 0;
    for (ll i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            f[i][0] = (f[i - 1][1] + f[i - 1][0] + 1) % mod;
            f[i][1] = f[i - 1][1] % mod;
        } else {
            f[i][0] = f[i - 1][0] % mod;
            f[i][1] = (f[i - 1][1] + f[i - 1][0] + 1) % mod;
        }
    }
    cout << (f[n][0] + f[n][1]) % mod << endl;
    return 0;
}

/*
5 3
1 2 3 4 5
 */
