#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll inf = 1e17, N = 8e3 + 10;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], c[n + 10], f[n + 10], g[n + 10];
    map<ll, ll> raw;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        raw[a[i]] = 1;
    }
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    ll index = 0;
    for (auto [k,v]: raw) {
        raw[k] = ++index;
    }
    for (ll i = 1; i <= n; i++) {
        a[i] = raw[a[i]];
    }
    for (ll i = 0; i <= n; i++) {
        f[i] = inf;
        g[i] = inf;
    }
    for (ll i = 1; i <= n; i++) {
        if (i < a[1]) {
            f[i] = c[1];
        } else if (i == a[1]) {
            f[i] = 0;
        } else {
            f[i] = c[1];
        }
        g[i] = min(g[i - 1], f[i]);
    }
    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (j < a[i]) {
                f[j] = g[j] + c[i];
            } else if (j == a[i]) {
                f[j] = g[j];
            } else {
                f[j] = g[j] + c[i];
            }
            g[j] = min(g[j - 1], f[j]);
        }
    }
    cout << g[n] << endl;
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
