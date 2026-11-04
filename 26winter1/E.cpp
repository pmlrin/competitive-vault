#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e4 + 10, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[2 * n + 10], b[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (ll i = 1; i <= n; i++) {
        a[n + i] = a[i];
    }
    ll ans = -inf;
    for (ll i = 1; i <= n; i++) {
        ll val = inf;
        for (ll j = 1; j <= n; j++) {
            val = min(val, abs(a[i + j - 1] - b[j]));
        }
        ans = max(ans, val);
    }
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
/*
1
5
1 2 3 4 5
1 2 3 4 5 */
