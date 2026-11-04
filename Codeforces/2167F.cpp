#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10;

ll n, k, f[N], d[N];
vector<ll> e[N], siz[N];

ll dfs(ll root, ll dad, ll dep) {
    ll ret = 1;
    d[root] = dep;
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        ret += dfs(son, root, dep + 1);
    }
    return f[root] = ret;
}

void solve() {
    ll ans = 0;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        siz[i].clear();
        f[i] = 0;
    }
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1, 1);
    for (ll i = 1; i <= n; i++) {
        ll tal = 0;
        for (auto j: e[i]) {
            if (d[j] > d[i]) {
                siz[i].push_back(f[j]);
                tal += f[j];
            }
        }
        if (n - 1 - tal >= 1) {
            siz[i].push_back(n - 1 - tal);
        }
    }
    for (ll i = 1; i <= n; i++) {
        ans++;
        for (auto in: siz[i]) {
            ll out = n - 1 - in;
            if (out >= k - 1) {
                ans += in;
            }
        }
    }
    cout << ans << endl;
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
