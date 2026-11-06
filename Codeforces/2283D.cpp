#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 3e5 + 10, inf = 1e17;

ll f[N];
vector<ll> e[N];

void dfs(ll root, ll dad, ll col, ll disa) {
    f[root] = col;
    for (auto son : e[root]) {
        if (son == dad || son == disa) {
            continue;
        }
        dfs(son, root, col, disa);
    }
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (ll i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n % 2 == 0) {
        cout << n + 1 << "\n";
        return;
    } else {
        ll k, pos, len;

        k = n, pos = n, len = e[pos].size();
        for (ll i = 1; i <= n; i++) {
            f[i] = 0;
        }
        for (ll i = 1; i <= len; i++) {
            dfs(e[pos][i - 1], e[pos][i - 1], i, pos);
        }
        for (ll i = 1; i <= n - 1; i++) {
            if (i >= k - i) {
                continue;
            }
            if (f[i] != f[k - i]) {
                cout << k << "\n";
                return;
            }
        }

        k = n + 1, pos = n / 2 + 1, len = e[pos].size();
        for (ll i = 1; i <= n; i++) {
            f[i] = 0;
        }
        for (ll i = 1; i <= len; i++) {
            dfs(e[pos][i - 1], e[pos][i - 1], i, pos);
        }
        for (ll i = 1; i <= n; i++) {
            if (i >= k - i) {
                continue;
            }
            if (f[i] != f[k - i]) {
                cout << k << "\n";
                return;
            }
        }

        k = n + 2, pos = 1, len = e[pos].size();
        for (ll i = 1; i <= n; i++) {
            f[i] = 0;
        }
        for (ll i = 1; i <= len; i++) {
            dfs(e[pos][i - 1], e[pos][i - 1], i, pos);
        }
        for (ll i = 2; i <= n; i++) {
            if (i >= k - i) {
                continue;
            }
            if (f[i] != f[k - i]) {
                cout << k << "\n";
                return;
            }
        }
        cout << n << "\n";
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
