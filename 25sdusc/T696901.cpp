#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17, mod = 998244353;

ll a[N], f[N], ans = 0;
vector<ll> e[N];

ll ksm(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b % 2) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ret;
}

ll inv2 = ksm(2, mod - 2);

void dfs(ll root, ll dad) {
    vector<ll> tmp;
    for (auto son : e[root]) {
        if (son == dad) {
            continue;
        }
        dfs(son, root);
        if (a[son] != a[root]) {
            tmp.push_back(f[son]);
        }
    }
    ll sum = 0, tans = 0;
    for (auto i : tmp) {
        sum = (sum + i) % mod;
    }
    for (auto i : tmp) {
        tans = (tans + i * (sum - i) % mod) % mod;
    }
    f[root] = (sum + 1) % mod;
    ans = (ans + tans * inv2 % mod + f[root]) % mod;
}

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    for (ll i = 1; i <= n; i++) {
        if (s[i - 1] == 'W') {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
        e[i].clear();
        f[i] = 0;
    }
    ans = 0;
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }
    dfs(1, 1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
