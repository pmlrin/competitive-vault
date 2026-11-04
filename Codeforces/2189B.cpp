#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, x, B = -inf, B1 = 0;
    cin >> n >> x;
    for (ll i = 1, a, b, c; i <= n; i++) {
        cin >> a >> b >> c;
        B = max(B, a * b - c);
        B1 += a * (b - 1);
    }
    // cout << "b = " << B1 << " B = " << B << endl;
    if (B1 >= x) {
        cout << 0 << endl;
    } else if (B <= 0) {
        cout << -1 << endl;
    } else {
        x -= B1;
        ll ans = x / B;
        if (x % B)
            ans++;
        cout << ans << endl;
    }
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
