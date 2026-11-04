#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1e6 + 10, M = 1e6 + 10, inf = 1145141919810;

struct UFDS {
    ll dad[N + M];

    void init(ll siz) {
        for (ll i = 1; i <= siz; i++)
            dad[i] = i;
    }

    ll find(ll x) {
        while (dad[x] != x) {
            x = dad[x] = dad[dad[x]];
        }
        return x;
    }

    void merge(ll x, ll y) {
        x = find(x), y = find(y);
        dad[x] = y;
    }
} s;

struct edge {
    ll u, v, w;
} g[M];

ll n, m, d[N + M], cnt, len[N + M], ans;
vector<ll> e[N + M];

void dfs(ll root, ll dad) {
    len[root] = min(len[root], len[dad]);
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        dfs(son, root);
        d[root] += d[son];
    }
    ans += len[root] * (d[root] / 2);
    d[root] %= 2;
}

void solve() {
    cin >> n >> m;
    s.init(n + m);
    cnt = n;
    ans = 0;
    for (ll i = 1; i <= n + m; i++) {
        d[i] = 0;
        len[i] = inf;
        e[i].clear();
    }
    for (ll i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        g[i] = (edge){u, v, w};
        ans += w;
        d[u]++;
        d[v]++;
    }
    for (ll i = 1; i <= n; i++) {
        d[i] %= 2;
    }
    for (ll i = 1; i <= m; i++) {
        ll u = s.find(g[i].u), v = s.find(g[i].v);
        if (u != v) {
            cnt++;
            s.merge(u, cnt);
            s.merge(v, cnt);
            len[cnt] = g[i].w;
            e[u].push_back(cnt);
            e[cnt].push_back(u);
            e[v].push_back(cnt);
            e[cnt].push_back(v);
        } else {
            len[u] = min(len[u], g[i].w);
        }
    }
    dfs(cnt, cnt);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
