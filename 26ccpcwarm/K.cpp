#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

ll n, a[N], b[N], r[N], fa[N], d[N];
vector<PII> e[N];

void dfs(ll root, ll dad) {
    fa[root] = dad;
    for (auto [son, dis] : e[root]) {
        if (son == dad) {
            continue;
        }
        d[son] = dis;
        dfs(son, root);
    }
}

void solve() {
    ll Q;
    cin >> n;
    for (ll i = 1, u, v, w; i <= n - 1; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (ll i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> r[i];
    }
    dfs(1, 0);
    cin >> Q;
    for (ll i = 1, v, q; i <= Q; i++) {
        cin >> v >> q;
        ll dis = 0, u = v, ans = LLONG_MAX;
        while (u) {
            if (dis <= r[u]) {
                ans = min(ans, a[u] * q + b[u] + dis);
            }
            dis += d[u];
            u = fa[u];
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
