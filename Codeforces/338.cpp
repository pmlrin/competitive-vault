#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 20, inf = 1e17;

ll f[N][2][2][10], g[N][2][2], vis[N][2][2], a[N], n;

void dfs(ll step, ll flag, ll bef) {
    if (vis[step][flag][bef]) {
        return;
    }
    if (step > n) {
        g[step][flag][bef] = 1;
        vis[step][flag][bef] = 1;
        return;
    }
    if (flag) {
        dfs(step + 1, 1, 0);
        g[step][flag][bef] += g[step + 1][1][0];
        for (ll i = 0; i <= 9; i++) {
            f[step][flag][bef][i] += f[step + 1][1][0][i];
        }
        f[step][flag][bef][a[step]] += g[step + 1][1][0];
        for (ll i = 0; i <= a[step] - 1; i++) {
            dfs(step + 1, 0, (bef && i == 0));
            g[step][flag][bef] += g[step + 1][0][(bef && i == 0)];
            for (ll j = 0; j <= 9; j++) {
                f[step][flag][bef][j] += f[step + 1][0][(bef && i == 0)][j];
            }
            if (!(bef && i == 0)) {
                f[step][flag][bef][i] += g[step + 1][0][(bef && i == 0)];
            }
        }
    } else {
        for (ll i = 0; i <= 9; i++) {
            dfs(step + 1, 0, (bef && i == 0));
            g[step][flag][bef] += g[step + 1][0][(bef && i == 0)];
            for (ll j = 0; j <= 9; j++) {
                f[step][flag][bef][j] += f[step + 1][0][(bef && i == 0)][j];
            }
            if (!(bef && i == 0)) {
                f[step][flag][bef][i] += g[step + 1][0][(bef && i == 0)];
            }
        }
    }
    vis[step][flag][bef] = 1;
}

void init(ll x) {
    for (n = 1; x; n++) {
        a[n] = x % 10;
        x /= 10;
    }
    n--;
    for (ll i = 1; i <= n / 2; i++) {
        swap(a[i], a[n - i + 1]);
    }
}

void solve(ll L, ll R) {
    ll ans[10] = {};
    if (L > R) {
        swap(L, R);
    }
    L--;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(vis, 0, sizeof(vis));
    init(L);
    dfs(1, 1, 1);
    for (ll i = 0; i <= 9; i++) {
        ans[i] -= f[1][1][1][i];
    }
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(vis, 0, sizeof(vis));
    init(R);
    dfs(1, 1, 1);
    for (ll i = 0; i <= 9; i++) {
        ans[i] += f[1][1][1][i];
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) {
            break;
        }
        solve(x, y);
    }
    return 0;
}
