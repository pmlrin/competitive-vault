#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e2 + 10, inf = 1e17;

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

ll n, m, sum = 0, a[60], b[60], g[60][60];

void add(ll a, ll b, ll c) {
    e[a].push_back((edge){b, c, e[b].size()});
    e[b].push_back((edge){a, 0, e[a].size() - 1});
}

void build(ll mid) {
    for (ll i = 1; i <= dinicn; i++) {
        e[i].clear();
    }
    dinicn = 0;
    s = ++dinicn;
    t = ++dinicn;
    ll ain[60] = {}, bin[60] = {};
    for (ll i = 1; i <= m; i++) {
        add(s, bin[i] = ++dinicn, mid * b[i]);
    }
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            if (!ain[j]) {
                ain[j] = ++dinicn;
            }
            if (g[i][j]) {
                add(bin[i], ain[j], inf);
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        add(ain[i], t, a[i]);
    }
}

ll check() {
    ll ans = 0;
    while (bfs()) {
        ans += dfs(s, inf);
    }
    if (ans == sum) {
        return 1;
    }
    return 0;
}

void solve() {
    ll ans = 0, L = 0, R = 1e9;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 10000;
        sum += a[i];
    }
    for (ll i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    dinicn = 0;
    while (L <= R) {
        ll mid = (L + R) / 2;
        build(mid);
        if (check()) {
            R = mid - 1;
            ans = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << fixed << setprecision(4) << ans * 1.0 / 10000 << endl;
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