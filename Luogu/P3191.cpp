#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10, inf = 1e17;

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

ll n, m, cnt = 0, f[505][505];
string g[30];
map<PII, ll> p, d, ip;

void add(ll a, ll b, ll c) {
    // cout << "<" << a << ", " << b << ">" << endl;
    e[a].push_back((edge){b, c, e[b].size()});
    e[b].push_back((edge){a, 0, e[a].size() - 1});
}

const ll nx[] = {0, 1, -1, 0, 0};
const ll ny[] = {0, 0, 0, 1, -1};

void build(ll mid) {
    for (ll i = 1; i <= dinicn; i++) {
        e[i].clear();
    }
    p.clear();
    d.clear();
    dinicn = 0;
    s = ++dinicn;
    t = ++dinicn;
    for (ll i = 0; i <= n - 1; i++) {
        for (ll j = 0; j <= m - 1; j++) {
            if (g[i][j] == 'D') {
                p[{i, j}] = ++dinicn;
                for (ll k = 1; k <= mid; k++) {
                    d[{p[{i, j}], k}] = ++dinicn;
                    add(d[{p[{i, j}], k}], t, 1);
                    if (k >= 2) {
                        add(d[{p[{i, j}], k - 1}], d[{p[{i, j}], k}], inf);
                    }
                }
                for (ll ni = 0; ni <= n - 1; ni++) {
                    for (ll nj = 0; nj <= m - 1; nj++) {
                        if (g[ni][nj] == '.' &&
                            f[ip[{ni, nj}]][ip[{i, j}]] <= mid) {
                            if (!p.count({ni, nj})) {
                                p[{ni, nj}] = ++dinicn;
                                add(s, p[{ni, nj}], 1);
                            }
                            add(p[{ni, nj}],
                                d[{p[{i, j}], f[ip[{ni, nj}]][ip[{i, j}]]}], 1);
                        }
                    }
                }
            }
        }
    }
}

ll check() {
    ll ret = 0;
    while (bfs()) {
        ret += dfs(s, inf);
    }
    return ret;
}

void init() {
    ll index = 0;
    for (ll i = 0; i <= n - 1; i++) {
        for (ll j = 0; j <= m - 1; j++) {
            if (g[i][j] == '.') {
                cnt++;
            }
            if (g[i][j] != 'X') {
                ip[{i, j}] = ++index;
            }
        }
    }
    for (ll i = 1; i <= index; i++) {
        for (ll j = 1; j <= index; j++) {
            if (i == j) {
                f[i][j] = 0;
            } else {
                f[i][j] = inf;
            }
        }
    }
    for (ll i = 0; i <= n - 1; i++) {
        for (ll j = 0; j <= m - 1; j++) {
            if (ip.count({i, j})) {
                for (ll k = 1; k <= 4; k++) {
                    ll ni = i + nx[k], nj = j + ny[k];
                    if (ip.count({ni, nj})) {
                        f[ip[{i, j}]][ip[{ni, nj}]] = 1;
                        f[ip[{ni, nj}]][ip[{i, j}]] = 1;
                    }
                }
            }
        }
    }
    for (ll k = 1; k <= index; k++) {
        for (ll i = 1; i <= index; i++) {
            for (ll j = 1; j <= index; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
}

void solve() {
    dinicn = 0;
    cin >> n >> m;
    for (ll i = 0; i <= n - 1; i++) {
        cin >> g[i];
    }
    init();
    ll L = 0, R = 10000, ans = -1;
    while (L <= R) {
        ll mid = (L + R) / 2;
        build(mid);
        if (check() == cnt) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    if (ans == -1) {
        cout << "impossible" << endl;
        return;
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
/*
5 5
DDDDD
D...D
D.X.D
D...D
DDDDD
*/