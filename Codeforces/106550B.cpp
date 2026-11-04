#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll x, ans = inf;
    cin >> x;
    ll a = sqrt(x), b = a - 1;
    for (ll i = 0;; i++) {
        b++;
        if (a * b > x) {
            a--, b--;
        }
        ll c = x - a * b;
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
        if (ans <= i) {
            cout << ans << endl;
            return;
        }
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
