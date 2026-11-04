#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 300 + 10, M = 300 * 200 + 300, inf = 1e14;

struct Data {
    ll u, v, a, b;
} e[M];
ll n, m, f[N][M];

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= M - 300; j++) {
            f[i][j] = inf;
        }
    }
    for (ll i = 1, u, v, a, b; i <= m; i++) {
        cin >> u >> v >> a >> b;
        e[i] = (Data) {u, v, a, b};
    }
    f[1][0] = 0;
    for (ll i = 0; i <= M - 300; i++) {
        for (ll j = 1; j <= m; j++) {
            f[e[j].v][i + e[j].a] = min(f[e[j].v][i + e[j].a], f[e[j].u][i] + e[j].b);
        }
    }
    ll ans = inf, ansa, ansb;
    for (ll i = 1; i <= M - 300; i++) {
        if (f[n][i] * i < ans) {
            ans = f[n][i] * i;
            ansa = i;
            ansb = f[n][i];
        }
    }
    cout << ansa << " " << ansb << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
