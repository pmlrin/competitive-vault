#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, k, ans = 0;
    cin >> n >> k;
    ll a[n + 10] = {}, s[n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (ll i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    if (k % 2) {
        ll L1 = k / 2, L2 = k - k / 2;
        for (ll i = L1 + 1; i <= n - L2 + 1; i++) {
            ll j = i + L2 - 1;
            ans = max(ans, s[n] - s[L1] - s[j] + s[i - 1] + k * a[i]);
        }
    } else {
        ll L = k / 2;
        for (ll i = L + 1; i <= n - L + 1; i++) {
            ll j = i + L - 1;
            ans =
                max(ans, s[n] - s[L] - s[j] + s[i - 1] + k * (a[L] + a[i]) / 2);
        }
        for (ll i = L; i <= n - L; i++) {
            ll j = i + L;
            ans = max(ans, s[n] - s[L - 1] - s[j] + s[i - 1] +
                               k * (a[i] + a[i + 1]) / 2);
        }
    }
    cout << ans << endl;
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
