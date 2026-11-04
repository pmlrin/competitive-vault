#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e2 + 10, inf = 1e17;

struct edge {
    ll to, val, rev;
};

ll dinicn, m, s, t, cur[N], lvl[N];
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

void solve() {
    ll ans = 0;
    cin >> dinicn >> m >> s >> t;
    for (ll i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[u].push_back((edge){v, w, e[v].size()});
        e[v].push_back((edge){u, 0, e[u].size() - 1});
    }
    while (bfs()) {
        ans += dfs(s, inf);
    }
    cout << ans << endl;
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
