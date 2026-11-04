#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17, mod = 1e9 + 7;

ll n, m;

void solve() {
    ll ans = 0;
    cin >> n >> m;
    ll f[m + 10][n + 10] = {}; // end =
    ll g[n + 10] = {};         // end <=
    for (ll i = 1; i <= n; i++) {
        f[1][i] = 1; // end = i
    }
    for (ll i = 2; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 1; k <= j; k++) {
                f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        g[i] = (g[i - 1] + f[m][i]) % mod;
    }
    for (ll i = 1; i <= n; i++) {
        ans = (ans + f[m][i] * g[n - i + 1] % mod) % mod;
    }
    cout << ans << endl;
    return;
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
