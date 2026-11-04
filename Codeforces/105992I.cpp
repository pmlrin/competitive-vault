#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e3 + 10, inf = 1e17, mod = 998244353;

ll n, a[N], f[N][N];
vector<ll> e[N];

void dfs(ll root, ll dad) {}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        e[i].clear();
    }
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
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
