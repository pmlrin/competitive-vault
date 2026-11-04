#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 39;

ll n, m, s, dad[N], vis[N], ans[N];
vector<ll> e[N];
vector<PII> q[N];

ll find(ll x) {
    while (x != dad[x]) {
        x = dad[x] = dad[dad[x]];
    }
    return x;
}

void dfs(ll root) {
    dad[root] = root;
    vis[root] = 1;
    for (auto son : e[root]) {
        if (!vis[son]) {
            dfs(son);
            dad[son] = root;
        }
    }
    for (auto [son, id] : q[root]) {
        if (vis[son]) {
            ans[id] = find(son);
        }
    }
}

void solve() {
    cin >> n >> m >> s;
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (ll i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        q[a].push_back({b, i});
        q[b].push_back({a, i});
    }
    dfs(s);
    for (ll i = 1; i <= m; i++) {
        cout << ans[i] << endl;
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