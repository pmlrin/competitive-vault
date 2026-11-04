#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17, mod = 998244353;

ll n, m, b[N], f[N][15];
// *ccf*cspark*
// 0123456789

void solve() {
    cin >> n >> m;
    for (ll i = 1, t; i <= m; i++) {
        cin >> t;
        b[t] = 1;
    }
    f[0][0] = 1;
    for (ll i = 1; i <= n; i++) {
        if (!b[i]) {
            f[i][0] =
                (f[i - 1][0] * 25 + f[i - 1][1] * 25 + f[i - 1][2] * 24) % mod;
            f[i][1] = f[i - 1][0];
            f[i][2] = (f[i - 1][1] + f[i - 1][2]) % mod;
            f[i][3] = 0;
            f[i][4] = (f[i - 1][2] + f[i - 1][4] * 25 + f[i - 1][5] * 24 +
                       f[i - 1][6] * 24 + f[i - 1][7] * 24 + f[i - 1][8] * 24 +
                       f[i - 1][9] * 24) %
                      mod;
            f[i][5] = (f[i - 1][4] + f[i - 1][5] + f[i - 1][6] + f[i - 1][7] +
                       f[i - 1][8] + f[i - 1][9]) %
                      mod;
            f[i][6] = f[i - 1][5];
            f[i][7] = f[i - 1][6];
            f[i][8] = f[i - 1][7];
            f[i][9] = f[i - 1][8];
            f[i][11] = (f[i - 1][9] + f[i - 1][11] * 26) % mod;
        } else {
            f[i][0] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % mod;
            f[i][1] = f[i][2] = f[i][3] = 0;
            f[i][4] = (f[i - 1][4] + f[i - 1][5] + f[i - 1][6] + f[i - 1][7] +
                       f[i - 1][8] + f[i - 1][9]) %
                      mod;
            f[i][5] = f[i][6] = f[i][7] = f[i][8] = f[i][9] = f[i][10] = 0;
            f[i][11] = f[i - 1][11];
        }
        // cout << f[i][1] << endl;
    }
    cout << f[n][11] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}