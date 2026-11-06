#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;

ll p[110], dp[2][21000][210];

void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        p[i] = -1;
    }
    for (int i = 0; i <= n * n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[0][i][j] = dp[1][i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        ll pos, v;
        cin >> pos >> v;
        p[pos] = v;
    }
    dp[1][0][0] = 1;
    for (int o = 1; o <= n; o++) {
        for (int i = 0; i <= n * n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[(o + 1) & 1][i][j] = 0;
            }
        }
        if (p[o] != -1) {
            for (int i = 0; i <= n * n; i++)
                if (i != p[o]) {
                    for (int j = 0; j <= n; j++) {
                        dp[o & 1][i][j] = 0;
                    }
                }
        }
        for (int i = 0; i <= n * n; i++) {
            for (int j = 0; j <= n; j++)
                if (dp[o & 1][i][j]) {
                    (dp[(o + 1) & 1][i + j][j] += dp[o & 1][i][j]) %= mod;
                    (dp[(o + 1) & 1][i + j + 1][j + 1] += dp[o & 1][i][j]) %=
                        mod;
                }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n * n; i++)
        for (int j = 0; j <= n; j++)
            (ans += dp[n & 1][i][j]) %= mod;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
