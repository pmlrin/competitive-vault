#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17, mod = 998244353;

ll n, f[N], b[N], nmin[N], pmin[N];
void solve() {
    cin >> n;
    ll cnt = n * 2 + 1;
    for (ll i = 1; i <= n + 1; i++) {
        cin >> f[i * 2 - 1];
        f[i * 2 - 1] *= -1;
    }
    for (ll i = 1; i <= n; i++) {
        cin >> f[i * 2];
        b[i * 2] = f[i * 2];
    }
    for (ll i = 1; i <= cnt; i++) {
        f[i] += f[i - 1];
    }
    nmin[cnt + 1] = inf;
    pmin[0] = inf;
    for (ll i = cnt; i >= 1; i--) {
        nmin[i] = min(f[i], nmin[i + 1]);
    }
    for (ll i = 1; i <= cnt; i++) {
        pmin[i] = min(f[i], pmin[i - 1]);
    }
    for (ll i = 2; i <= n * 2; i += 2) {
        ll inc = f[i - 1] - min(0ll, pmin[i - 1]);
        ll dec = (nmin[i] - f[i]) * -1;
        // cout << inc << " " << dec << endl;
        cout << max(dec - inc, 0ll) - min(0ll, pmin[i - 1]) << " ";
    }
    cout << endl;
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
/*
-5 0 -5 100 -5 0 -5
-5 -5 -10 90 85 85 80
*/