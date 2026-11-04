#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e3 + 10, L = 18;

struct Data {
    ll dis, tag, num;
};

ll n, c[N], k[N], vis[N], ans = 0;
vector<PII> e[N];

void getInfo(ll root, ll dad, ll dis, ll tag, vector<Data> &tmp) {
    tmp.push_back({dis, tag, root});
    for (auto [son, d] : e[root]) {
        if (vis[son] || son == dad) {
            continue;
        }
        getInfo(son, root, dis + d, tag ^ c[son], tmp);
    }
}

void dfs(ll root) {
    vector<Data> cur;
    vis[root] = 1;
    cur.push_back({0, 0, root});
    for (auto [son, dis] : e[root]) {
        if (vis[son]) {
            continue;
        }
        vector<Data> tmp;
        getInfo(son, root, dis, c[son], tmp);
        for (auto [d1, t1, n1] : cur) {
            for (auto [d2, t2, n2] : tmp) {
                if (d1 + d2 <= k[n1] && d1 + d2 <= k[n2] &&
                    (t1 ^ t2 ^ c[root]) == 0) {
                    ans++;
                }
            }
        }
        for (auto t : tmp) {
            cur.push_back(t);
        }
    }
    for (auto [son, dis] : e[root]) {
        if (vis[son]) {
            continue;
        }
        dfs(son);
    }
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for (ll i = 1, u, v, w; i <= n - 1; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1);
    cout << ans << endl;
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
