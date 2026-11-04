#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PII pair<ll, ll>
const ll mod = 1e9 + 7, N = 1e4 + 10, inf = 1e17;
const ld eps = 1e-9;

ll a[N], b[N], c[N], n;

ld calc(ld x) {
    ld ans = -inf;
    for (ll i = 1; i <= n; i++) {
        ans = max(ans, x * x * a[i] + x * b[i] + c[i]);
    }
    return ans;
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ld l = 0, r = 1000;
    while (r - l > eps) {
        ld m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (calc(m1) < calc(m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    cout << fixed << setprecision(4) << calc(l) << endl;
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