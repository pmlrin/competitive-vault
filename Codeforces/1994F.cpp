#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10, inf = 1e17;

ll n, m, du[N], used[N], vis[N * 2], cur[N];
vector<PII> e[N], g[N];
vector<ll> ans;

bool cmp(PII a, PII b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void eular(ll now) {
    for (ll &i = cur[now]; i < e[now].size(); i++) {
        if (!vis[e[now][i].second]) {
            vis[e[now][i].second] = 1;
            vis[e[now][i].second ^ 1] = 1;
            eular(e[now][i].first);
        }
    }
    ans.push_back(now);
}

int dfs(ll root, ll dad, ll num) {
    used[root] = 1;
    for (auto son: g[root]) {
        if (used[son.first]) {
            continue;
        }
        dfs(son.first, root, son.second);
    }
    if (du[root] && dad != root) {
        du[root] ^= 1;
        du[dad] ^= 1;
        vis[num] = 1;
        vis[num ^ 1] = 1;
    }
    return du[root];
}

void solve() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        g[i].clear();
        e[i].clear();
        du[i] = 0;
        used[i] = 0;
        cur[i] = 0;
    }
    for (ll i = 0; i <= m * 2 + 10; i++) {
        vis[i] = 0;
    }
    ans.clear();
    for (ll i = 1, u, v, c; i <= m; i++) {
        cin >> u >> v >> c;
        du[u] = (du[u] + 1) % 2;
        du[v] = (du[v] + 1) % 2;
        e[u].push_back({v, 2 * i});
        e[v].push_back({u, 2 * i + 1});
        if (c == 0) {
            g[u].push_back({v, 2 * i});
            g[v].push_back({u, 2 * i + 1});
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (!used[i]) {
            if (dfs(i, i, 0)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    eular(1);
    cout << "Yes" << endl << ans.size() - 1 << endl;
    for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
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
