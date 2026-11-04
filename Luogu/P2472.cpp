#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17;

struct edge {
    ll to, val, rev;
};

ll n, m, s, t, cur[N], lvl[N];
vector<edge> e[N];

ll bfs() {
    for (ll i = 1; i <= n; i++) {
        lvl[i] = 0;
        cur[i] = 0;
    }
    // cout << "ok" << endl;
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

map<PII, PII> p;

void add(PII a, PII b, ll c) {
    if (!p.count(a)) {
        p[a].first = n + 1;
        p[a].second = n + 2;
        n += 2;
    }
    if (!p.count(b)) {
        p[b].first = n + 1;
        p[b].second = n + 2;
        n += 2;
    }
    e[p[a].second].push_back((edge){p[b].first, c, e[p[b].first].size()});
    e[p[b].first].push_back((edge){p[a].second, 0, e[p[a].second].size() - 1});
}

void add(ll a, ll b, ll c) {
    e[a].push_back((edge){b, c, e[b].size()});
    e[b].push_back((edge){a, 0, e[a].size() - 1});
}

void solve() {
    ll ans = 0, r, c, d;
    n = 0;
    s = ++n;
    t = ++n;
    cin >> r >> c >> d;
    string g1[30], g2[30];
    for (ll i = 0; i < r; i++) {
        cin >> g1[i];
    }
    for (ll i = 0; i < r; i++) {
        cin >> g2[i];
    }
    for (ll i1 = 0; i1 < r; i1++) {
        for (ll j1 = 0; j1 < c; j1++) {
            for (ll i2 = -1; i2 <= r; i2++) {
                for (ll j2 = -1; j2 <= c; j2++) {
                    if ((i1 - i2) * (i1 - i2) + (j1 - j2) * (j1 - j2) <=
                        d * d) {
                        add({i1, j1}, {i2, j2}, inf);
                    }
                }
            }
            add(p[{i1, j1}].first, p[{i1, j1}].second, g1[i1][j1] - '0');
            if (g2[i1][j1] == 'L') {
                add(s, p[{i1, j1}].first, 1);
                ans++;
            }
        }
    }
    for (ll i2 = -1; i2 <= r; i2++) {
        for (ll j2 = -1; j2 <= c; j2++) {
            if (i2 == -1 || j2 == -1 || i2 == r || j2 == c) {
                add(p[{i2, j2}].first, t, inf);
            }
        }
    }

    while (bfs()) {
        ans -= dfs(s, inf);
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
