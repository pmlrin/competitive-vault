#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, M = 100 + 10, inf = 1e17;

ll n, m, t, w[N], dis[N][M], vis[N];
vector<ll> e[N];
queue<ll> q;

void solve() {
    cin >> n >> m >> t;
    for (ll i = 1; i <= n; i++) {
        cin >> w[i];
        for (ll j = 0; j <= 100; j++) {
            dis[i][j] = inf;
        }
    }
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (ll i = 1; i <= 100; i++) {
        for (ll j = 1; j <= n; j++) {
            vis[j] = 0;
            if (w[j] <= i) {
                q.push(j);
                vis[j] = 1;
                dis[j][i] = 0;
            }
        }
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            for (auto v : e[u]) {
                if (vis[v]) {
                    continue;
                }
                q.push(v);
                vis[v] = 1;
                dis[v][i] = dis[u][i] + 1;
            }
        }
        for (ll j = 1; j <= n; j++) {
            dis[j][i] = min(dis[j][i], dis[j][i - 1]);
        }
    }
    for (ll i = 1, p, a; i <= t; i++) {
        cin >> p >> a;
        if (dis[p][a] == inf) {
            cout << "-1\n";
        } else {
            cout << dis[p][a] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
