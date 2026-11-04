#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17;

struct Data {
    ll id, dis, from, id2;
    bool operator<(const Data &a) const { return dis > a.dis; }
};

ll n, m, k, ans, vis[N][2], dis[N][2], from[N];
vector<PII> e[N];
priority_queue<Data> q;

void dij() {
    while (!q.empty()) {
        Data u = q.top();
        q.pop();
        if (from[u.id] == u.id && u.id != u.from) {
            ans = min(ans, u.dis);
        }
        if (u.dis >= ans) {
            continue;
        }
        if (vis[u.id][u.id2]) {
            continue;
        }
        vis[u.id][u.id2] = 1;
        for (auto [v, w] : e[u.id]) {
            if (dis[v][0] > u.dis + w) {
                dis[v][0] = u.dis + w;
                from[v] = u.from;
                q.push({v, u.dis + w, u.from, 0});
            } else if (dis[v][1] > u.dis + w && u.from != from[v]) {
                dis[v][1] = u.dis + w;
                q.push({v, u.dis + w, u.from, 1});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        dis[i][0] = dis[i][1] = inf;
        from[i] = vis[i][0] = vis[i][1] = 0;
    }
    ans = inf;
    for (ll i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (ll i = 1, a; i <= k; i++) {
        cin >> a;
        dis[a][0] = 0;
        from[a] = a;
        q.push({a, 0, a, 0});
    }
    dij();
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
