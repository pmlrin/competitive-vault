#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e4 + 10, inf = 1e17, mod = 998244353;

ll n, m, f[N], c[N], v[N];
void solve() {
    ll ans = 0;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> c[i];
        v[i] = i;
    }
    for (ll i = 1; i <= m; i++) {
        for (ll j = 0; j <= n; j++) {
            if (j - v[i] >= 0) {
                f[j] = max(f[j], f[j - v[i]] + c[i]);
            }
        }
    }
    for (ll i = 0; i <= n; i++) {
        ans = max(ans, f[i]);
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