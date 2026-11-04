#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17;

struct Data {
    ll id, dis, from;
    bool operator<(const Data &a) const { return dis > a.dis; }
};

ll n, m, k, c[N], dis[N][2], from[N];
vector<ll> e[N];
priority_queue<Data> q;

ll bfs() {
    while (!q.empty()) {
        Data u = q.top();
        q.pop();
        if (from[u.id] == u.id && u.id != u.from) {
            while (!q.empty()) {
                q.pop();
            }
            return 1;
        }
        if (u.dis >= k) {
            continue;
        }
        for (auto v : e[u.id]) {
            if (dis[v][0] > u.dis + 1) {
                dis[v][0] = u.dis + 1;
                from[v] = u.from;
                q.push({v, u.dis + 1, u.from});
            } else if (dis[v][1] > u.dis + 1 && u.from != from[v]) {
                dis[v][1] = u.dis + 1;
                q.push({v, u.dis + 1, u.from});
            }
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }
    for (ll i = 1; i <= 50; i++) {
        for (ll j = 1; j <= n; j++) {
            dis[j][0] = dis[j][1] = inf;
            from[j] = 0;
        }
        for (ll j = 1; j <= n; j++) {
            if (c[j] == i) {
                dis[j][0] = 1;
                from[j] = j;
                q.push({j, 1, j});
            }
        }
        if (bfs()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
