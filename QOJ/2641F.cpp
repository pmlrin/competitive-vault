#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 300 + 10, inf = 1e17;

ll n, m, x, y;
vector<ll> e[N];

ll out[N][N];
ll oncycle[N], lvl[N], last[N];

ll find(ll st, ll ed) {
    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        last[i] = 0;
    }
    last[st] = st;
    q.push(st);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if ((u == st && v == ed) || (u == ed && v == st) || last[v]) {
                continue;
            }
            last[v] = u;
            if (v == ed) {
                return 1;
            }
            q.push(v);
        }
    }
    return 0;
}

void mark(ll u, ll v) {
    ll cur = v;
    while (last[cur] != cur) {
        out[cur][last[cur]] = -1;
        out[last[cur]][cur] = 1;
        oncycle[cur] = 1;
        cur = last[cur];
    }
    out[u][v] = -1;
    out[v][u] = 1;
    oncycle[u] = 1;

    cur = u;
    while (lvl[cur] != cur) {
        out[cur][lvl[cur]] = -1;
        out[lvl[cur]][cur] = 1;
        oncycle[cur] = 1;
        cur = lvl[cur];
    }
    oncycle[cur] = 1;
}

void bfs() {
    queue<ll> q;
    for (ll i = 1; i <= n; i++) {
        lvl[i] = 0;
    }
    lvl[x] = x;
    lvl[y] = y;
    q.push(x);
    q.push(y);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto v : e[u]) {
            if (!lvl[v]) {
                lvl[v] = u;
                if (find(u, v)) {
                    mark(u, v);
                    return;
                }
                q.push(v);
            }
        }
    }
}

void solve() {
    ll type = 1;
    cin >> n >> m >> x >> y;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        for (ll j = 1; j <= n; j++) {
            out[i][j] = 0;
        }
        oncycle[i] = 0;
    }
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        if ((u == x && v == y) || (u == y && v == x)) {
            type = 2;
        }
    }
    if (type == 1) {
        cout << "Yes\n";
        oncycle[x] = oncycle[y] = 1;
    } else if (n - 1 < m) {
        cout << "Yes\n";
        lvl[x] = x;
        if (find(x, y)) {
            mark(x, y);
        } else {
            bfs();
            if (!oncycle[y]) {
                out[y][x] = 1;
                out[x][y] = -1;
                oncycle[y] = 1;
            }
        }
    } else {
        cout << "No\n";
        return;
    }
    for (ll u = 1; u <= n; u++) {
        for (auto v : e[u]) {
            if (out[u][v]) {
                continue;
            }
            if (oncycle[u]) {
                out[u][v] = -1;
                out[v][u] = 1;
            } else {
                out[u][v] = 1;
                out[v][u] = -1;
            }
        }
    }
    for (ll i = 1; i <= n - 1; i++) {
        for (ll j = i + 1; j <= n; j++) {
            if (out[i][j] == 1) {
                cout << i << " " << j << "\n";
            }
            if (out[i][j] == -1) {
                cout << j << " " << i << "\n";
            }
        }
    }
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
