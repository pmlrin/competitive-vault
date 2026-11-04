#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e3 + 10, inf = 1e17;

struct edge {
    ll to, val, rev, cost;
};

ll dinicn, m, s, t, cur[N], lvl[N], vis[N], maxFlow = 0, minCost = 0;
vector<edge> e[N];

ll bfs() {
    for (ll i = 1; i <= dinicn; i++) {
        lvl[i] = inf;
        cur[i] = 0;
        vis[i] = 0;
    }
    queue<ll> q;
    q.push(s);
    lvl[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        vis[now] = 0;
        for (auto [to, val, rev, cost] : e[now]) {
            if (val > 0 && lvl[to] > lvl[now] + cost) {
                lvl[to] = lvl[now] + cost;
                if (!vis[to]) {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
    if (lvl[t] == inf) {
        return 0;
    }
    return 1;
}

ll dfs(ll now, ll flow) {
    if (now == t) {
        return flow;
    }
    vis[now] = 1;
    ll res = 0;
    for (ll &i = cur[now]; i < e[now].size(); i++) {
        auto [to, val, rev, cost] = e[now][i];
        if (!vis[to] && val > 0 && lvl[to] == lvl[now] + cost) {
            ll f = dfs(to, min(val, flow));
            if (f == 0) {
                lvl[to] = inf;
            }
            e[now][i].val -= f;
            e[to][rev].val += f;
            res += f;
            flow -= f;
            minCost += f * cost;
            if (flow == 0) {
                return res;
            }
        }
    }
    vis[now] = 0;
    return res;
}

void add(ll a, ll b, ll c, ll cost) {
    e[a].push_back((edge){b, c, e[b].size(), cost});
    e[b].push_back((edge){a, 0, e[a].size() - 1, -cost});
}

void solve() {
    maxFlow = minCost = 0;
    cin >> dinicn >> m >> s >> t;
    for (ll i = 1, u, v, w, c; i <= m; i++) {
        cin >> u >> v >> w >> c;
        add(u, v, w, c);
    }
    while (bfs()) {
        maxFlow += dfs(s, inf);
    }
    cout << maxFlow << " " << minCost << endl;
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
