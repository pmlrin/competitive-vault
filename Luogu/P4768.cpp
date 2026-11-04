#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

const ll N = 2e5 + 10, M = 4e5 + 10, inf = 1145141919810;

struct edge {
    ll u, v, len;
} h[M];

struct CompareMin {
    bool operator()(const PII &a, const PII &b) const {
        return a.second > b.second;
    }
};

struct UFDS {
    ll dad[N + M];

    void init() {
        for (ll i = 1; i <= N + M - 10; i++)
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

vector<PII > g[N];
vector<ll> e[N + M];
priority_queue<PII, vector<PII >, CompareMin> q;
ll n, m, cnt, lastans, dis[N + M], vis[N], high[N + M], f[25][N + M];
ll Q, K, S;

bool cmp(edge a, edge b) {
    return a.len > b.len;
}

void dij(ll st) {
    dis[st] = 0;
    q.push((PII){st, 0});
    while (!q.empty()) {
        ll now = q.top().first;
        q.pop();
        if (vis[now]) {
            continue;
        }
        vis[now] = 1;
        for (auto [to,len]: g[now]) {
            if (dis[to] > dis[now] + len) {
                dis[to] = dis[now] + len;
                q.push((PII){to, dis[to]});
            }
        }
    }
}

void dfs(ll root, ll dad) {
    f[0][root] = dad;
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        dfs(son, root);
        dis[root] = min(dis[root], dis[son]);
    }
}

ll query(ll v, ll p) {
    for (ll i = 20; i >= 0; i--) {
        if (high[f[i][v]] > p) {
            v = f[i][v];
        }
    }
    return dis[v];
}

void solve() {
    cin >> n >> m;
    lastans = 0;
    cnt = n;
    s.init();
    for (ll i = 1; i <= n; i++) {
        g[i].clear();
        vis[i] = 0;
    }
    for (ll i = 1; i <= n + m; i++) {
        dis[i] = inf;
        e[i].clear();
    }
    for (ll i = 1, u, v, l, a; i <= m; i++) {
        cin >> u >> v >> l >> a;
        g[u].push_back((PII){v, l});
        g[v].push_back((PII){u, l});
        h[i] = (edge){u, v, a};
    }
    sort(h + 1, h + 1 + m, cmp);
    dij(1);

    for (ll i = 1; i <= m; i++) {
        ll u = s.find(h[i].u), v = s.find(h[i].v);
        if (u != v) {
            cnt++;
            s.merge(u, cnt);
            s.merge(v, cnt);
            high[cnt] = h[i].len;
            e[u].push_back(cnt);
            e[cnt].push_back(u);
            e[v].push_back(cnt);
            e[cnt].push_back(v);
        }
    }
    dfs(cnt, cnt);

    for (ll i = 1; i <= 20; i++) {
        for (ll j = 1; j <= cnt; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }

    cin >> Q >> K >> S;

    for (ll i = 1, v, p; i <= Q; i++) {
        cin >> v >> p;
        v = (v + K * lastans - 1) % n + 1;
        p = (p + K * lastans) % (S + 1);
        cout << (lastans = query(v, p)) << endl;
    }
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
