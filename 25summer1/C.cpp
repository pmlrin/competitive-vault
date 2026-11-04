#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 200000 + 10, M = 40, inf = 1145141919810;

struct edge {
    ll u, v, len;
};

struct CompareMin {
    bool operator()(const edge &a, const edge &b) const { return a.len > b.len; }
};

priority_queue<edge, vector<edge>, CompareMin> q;

ll n, m, dis[N], vis[N];
vector<edge> e[N];

void add(ll x, ll y, ll len) {
    e[x].push_back({x, y, len});
    e[y].push_back({y, x, len});
}

void dij() {
    for (ll i = 1; i <= n; i++)
        q.push({0, i, dis[i]});
    while (!q.empty()) {
        ll now = q.top().v;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (auto to: e[now]) {
            if (dis[to.v] > dis[now] + to.len) {
                dis[to.v] = dis[now] + to.len;
                q.push({now, to.v, dis[to.v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll u, v, len;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> u >> v >> len;
        add(u, v, len * 2);
    }
    for (ll i = 1; i <= n; i++)
        cin >> dis[i];
    dij();
    for (ll i = 1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;
    return 0;
}
// 101
