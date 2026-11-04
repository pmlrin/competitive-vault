#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17;

struct edge {
    ll to, val, rev;
};

ll dinicn, s, t, cur[N], lvl[N];
vector<edge> e[N];

ll bfs() {
    for (ll i = 1; i <= dinicn; i++) {
        lvl[i] = 0;
        cur[i] = 0;
    }
    queue<ll> q;
    q.push(s);
    lvl[s] = 1;
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        for (auto [to, val, rev] : e[now]) {
            if (val > 0 && !lvl[to]) {
                q.push(to);
                lvl[to] = lvl[now] + 1;
                if (to == t)
                    return 1;
            }
        }
    }
    return 0;
}

ll dfs(ll now, ll flow) {
    if (now == t) {
        return flow;
    }
    ll res = 0;
    for (ll &i = cur[now]; i < e[now].size(); i++) {
        auto [to, val, rev] = e[now][i];
        if (val > 0 && lvl[to] == lvl[now] + 1) {
            ll f = dfs(to, min(val, flow));
            if (f == 0) {
                lvl[to] = 0;
            }
            e[now][i].val -= f;
            e[to][rev].val += f;
            res += f;
            flow -= f;
        }
    }
    return res;
}

ll n, m, sum = 0, k, L[N], C[N];
set<PII> ob;
map<ll, ll> Ln, Cn;

void add(ll a, ll b, ll c) {
    e[a].push_back((edge){b, c, e[b].size()});
    e[b].push_back((edge){a, 0, e[a].size() - 1});
}

void build() {
    for (ll i = 1; i <= dinicn; i++) {
        e[i].clear();
    }
    dinicn = 0;
    ob.clear();
    Ln.clear();
    Cn.clear();
    s = ++dinicn;
    t = ++dinicn;
    for (ll i = 1; i <= m; i++) {
        Ln[i] = ++dinicn;
        add(s, Ln[i], L[i]);
    }
    for (ll i = 1; i <= n; i++) {
        Cn[i] = ++dinicn;
        add(Cn[i], t, C[i]);
    }
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            add(Ln[i], Cn[j], 1);
        }
    }
}

ll check() {
    ll ans = 0;
    while (bfs()) {
        ans += dfs(s, inf);
    }
    return ans + sum;
}

void solve() {
    dinicn = 0;
    cin >> m >> n >> k;
    for (ll i = 1; i <= m; i++) {
        cin >> L[i];
        L[i] = n - L[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> C[i];
        C[i] = m - C[i];
    }
    for (ll i = 1, u, v; i <= k; i++) {
        cin >> u >> v;
        ob.insert({u, v});
        L[u]--;
        C[v]--;
        sum++;
        if (L[u] < 0 || C[v] < 0) {
            cout << "JIONG!" << endl;
            return;
        }
    }
    build();
    cout << m * n - check() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}