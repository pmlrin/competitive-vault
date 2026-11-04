#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10, inf = 7e18;

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
            if (flow == 0) {
                return res;
            }
        }
    }
    return res;
}

void add(ll a, ll b, ll c) {
    e[a].push_back((edge){b, c, e[b].size()});
    e[b].push_back((edge){a, 0, e[a].size() - 1});
}

const ll nx[] = {0, 1, -1, 0, 0};
const ll ny[] = {0, 0, 0, 1, -1};

ll n, m, a[50][50], Flag;

void build(ll x) {
    dinicn = n * m + 2;
    for (ll i = 1; i <= dinicn; i++) {
        e[i].clear();
    }
    s = n * m + 1;
    t = n * m + 2;
    Flag = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if ((i + j) % 2 == 0) {
                add(s, (i - 1) * m + j, x - a[i][j]);
                Flag += x - a[i][j];
            } else {
                add((i - 1) * m + j, t, x - a[i][j]);
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if ((i + j) % 2 == 0) {
                for (ll k = 1; k <= 4; k++) {
                    ll i2 = i + nx[k], j2 = j + ny[k];
                    if (i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= m) {
                        add((i - 1) * m + j, (i2 - 1) * m + j2, inf);
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
    if (ret == Flag) {
        return 1;
    }
    return 0;
}

void solve() {
    ll B0 = 0, W1 = 0, b0 = 0, w1 = 0, ans = -1, mx = 0;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            if ((i + j) % 2 == 0) {
                B0++;
                b0 += a[i][j];
            } else {
                W1++;
                w1 += a[i][j];
            }
        }
    }
    if (B0 != W1) {
        build((b0 - w1) / (B0 - W1));
        if (check()) {
            cout << Flag << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        ll l = mx, r = 3e9;
        while (l <= r) {
            ll mid = (l + r) / 2;
            build(mid);
            if (check()) {
                ans = Flag;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
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
/*
1
2 3
0 9 9
9 9 0
*/