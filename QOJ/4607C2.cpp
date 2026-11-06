#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>

const ll N = 100 + 10, M = 50 * 99 + 10, mod = 998244353;

ll f[N][M][N], sum[N][M][N], n, m, fc[N][N], vfc[N][N];
PII a[N];

ll calc(ll step, ll last) {
    if (vfc[step][last]) {
        return fc[step][last];
    }
    if (step > m) {
        ll len = n - a[m].first + 1, cnt = len * (len - 1) / 2;
        return fc[step][last] = sum[len][cnt][len - 1];
    }
    vfc[step][last] = 1;
    ll ret = 0, len = a[step].first - a[step - 1].first + 1,
       cnt = a[step].second - a[step - 1].second - last * (len - 1);
    for (ll i = 0; i <= len - 1; i++) {
        ret = (ret + f[len][cnt][i] * calc(step + 1, i + last) % mod) % mod;
    }
    return fc[step][last] = ret;
}

void solve() {
    ll ans = 0;
    cin >> n >> m;
    if (m == 0) {
        cout << sum[n][n * (n - 1) / 2][n - 1] << "\n";
        return;
    }
    for (ll i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (ll i = 1; i <= m + 1; i++) {
        for (ll j = 0; j <= n; j++) {
            fc[i][j] = vfc[i][j] = 0;
        }
    }
    for (ll i = 0; i <= a[1].first - 1; i++) {
        ans = (ans + f[a[1].first][a[1].second][i] * calc(2, i) % mod) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    f[0][0][0] = 1;
    for (ll i = 1; i <= N - 10; i++) {
        for (ll j = 0; j <= M - 10; j++) {
            for (ll k = 0; k <= i - 1; k++) {
                if (j - k < 0) {
                    continue;
                }
                f[i][j][k] = f[i - 1][j - k][k];
                if (k - 1 < 0) {
                    continue;
                }
                f[i][j][k] = (f[i][j][k] + f[i - 1][j - k][k - 1]) % mod;
            }
        }
    }
    for (ll i = 0; i <= N - 10; i++) {
        sum[i][0][0] = f[i][0][0];
        for (ll j = 1; j <= M - 10; j++) {
            sum[i][j][0] = (sum[i][j - 1][0] + f[i][j][0]) % mod;
        }
        for (ll k = 1; k <= i - 1; k++) {
            sum[i][0][k] = (sum[i][0][k - 1] + f[i][0][k]) % mod;
        }
        for (ll j = 1; j <= M - 10; j++) {
            for (ll k = 1; k <= i - 1; k++) {
                sum[i][j][k] = ((f[i][j][k] + sum[i][j - 1][k] +
                                 sum[i][j][k - 1] - sum[i][j - 1][k - 1]) %
                                    mod +
                                mod) %
                               mod;
            }
        }
    }
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
