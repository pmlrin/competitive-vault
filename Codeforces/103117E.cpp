#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17;

ll n, m, index, vis[N], r[N], head[N], ans;
vector<ll> e[N];

void dfs(ll u) {
    if (!vis[u]) {
        vis[u] = 1;
        for (auto v : e[u]) {
            r[u] = max(r[u], v);
        }
    }
    while (index <= r[u]) {
        if (e[u].size() > head[u] && index > e[u][head[u]]) {
            head[u]++;
        } else if (e[u].size() > head[u] && index == e[u][head[u]]) {
            head[u]++;
            dfs(index++);
        } else {
            ans++;
            dfs(index++);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        vis[i] = 0;
        r[i] = i;
        head[i] = 0;
    }
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
    }
    index = 1;
    ans = 0;
    r[1] = n;
    dfs(index++);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
