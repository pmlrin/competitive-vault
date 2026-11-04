#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 300 + 10, inf = 1e17, mod = 998244353;

ll n, a[N], f[N][N][N], g3[N][N][N], g2[N][N][N];

ll dfs(ll u, ll v, ll w) {
    // cout << u << " " << v << " " << w << endl;
    if (f[u][v][w]) {
        return f[u][v][w];
    }
    if (u == 0 && v == 0 && w == 0) {
        return f[u][v][w] = 1;
    }
    ll ret = 0;
    ll f1 = u - v, f2 = v - w, f3 = w;
    ll i = 1;
    for (i = 1; i <= f3; i++) {
        if (g3[u - 1][v - 1][w - i]) {
            ret = (ret + g3[u - 1][v - 1][w - i]) % mod;
            break;
        } else {
            ret = (ret + dfs(u - 1, v - 1, w - i)) % mod;
        }
    }
    for (; i >= 1; i--) {
        if (w - i >= 1) {
            g3[u - 1][v - 1][w - i] = (f[u - 1][v - 1][w - i] + g3[u - 1][v - 1][w - i - 1]) % mod;
        } else if (w - i == 0) {
            g3[u - 1][v - 1][w - i] = f[u - 1][v - 1][w - i];
        }
    }
    for (i = 1; i <= f2; i++) {
        if (g2[u - 1][v - i][w]) {
            ret = (ret + g2[u - 1][v - i][w]) % mod;
            break;
        } else {
            ret = (ret + dfs(u - 1, v - i, w)) % mod;
        }
    }
    for (; i >= 1; i--) {
        if (v - i >= w + 1) {
            g2[u - 1][v - i][w] = (f[u - 1][v - i][w] + g2[u - 1][v - i - 1][w]) % mod;
        } else if (v - i == w) {
            g2[u - 1][v - i][w] = f[u - 1][v - i][w];
        }
    }
    if (f1 >= 1) {
        ret = (ret + dfs(u - 1, v, w)) % mod;
    }
    return f[u][v][w] = ret;
}

void solve() {
    ll ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll pu = n, pv = n, pw = n;
    ll n1 = 0, n2 = 0, n3 = 0;
    for (ll i = 1; i <= n; i++) {
        if (a[i] > n3) {
            n3 = a[i];
        } else if (a[i] > n2) {
            n2 = a[i];
        } else if (a[i] > n1) {
            n1 = a[i];
        } else {
            break;
        }
        ll u = 0, v = 0, w = 0;
        for (ll j = i + 1; j <= n; j++) {
            if (a[j] > n3) {
                u++, v++, w++;
            } else if (a[j] > n2) {
                u++, v++;
            } else if (a[j] > n1) {
                u++;
            }
        }
        // cout << n1 << " " << n2 << " " << n3 << endl;
        // cout << u << " " << v << " " << w << endl;
        ll f1 = u - v, f2 = v - w, f3 = w;
        if (a[i] == n3 || a[i] == n2 || a[i] == n1) {
            for (ll j = 1; j <= f3; j++) {
                ans = (ans + f[pu - 1][pv - 1][w - j]) % mod;
            }
        }
        if (a[i] == n2 || a[i] == n1) {
            for (ll j = 1; j <= f2; j++) {
                ans = (ans + f[pu - 1][v - j][pw]) % mod;
            }
        }
        pu = u, pv = v, pw = w;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    dfs(300, 300, 300);
    while (T--) {
        solve();
    }
    return 0;
}
