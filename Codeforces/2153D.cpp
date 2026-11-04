#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 4e5 + 10, inf = 1145141919810999999;

ll n, d[N], f[N][4];

ll calc(ll a[]) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 2; j <= 3; j++) {
            f[i][j] = inf;
        }
    }
    f[0][2] = f[0][3] = 0;
    f[2][2] = abs(a[1] - a[2]);
    f[3][3] = max({a[1], a[2], a[3]}) - min({a[1], a[2], a[3]});
    for (ll i = 3; i <= n; i++) {
        ll p2 = abs(a[i] - a[i - 1]);
        ll p3 = max({a[i], a[i - 1], a[i - 2]}) - min({a[i], a[i - 1], a[i - 2]});
        f[i][2] = min(f[i - 2][2], f[i - 2][3]) + p2;
        f[i][3] = min(f[i - 3][2], f[i - 3][3]) + p3;
    }
    return min(f[n][2], f[n][3]);
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    ll ans = inf;
    for (ll i = 1; i <= 3; i++) {
        ans = min(ans, calc(d + i));
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
