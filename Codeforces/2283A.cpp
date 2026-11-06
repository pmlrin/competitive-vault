#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll l, r;
    cin >> l >> r;
    if (l == 0 && r == 0) {
        cout << 0 << "\n";
        return;
    }
    if (l >= 0 && r >= 0) {
        cout << r - l - (l == 0 || r == 0) << "\n";
        return;
    }
    if (l <= 0 && r <= 0) {
        cout << r - l - (l == 0 || r == 0) << "\n";
        return;
    }
    ll sum = 0;
    for (ll i = l; i <= r; i++) {
        sum += i;
    }
    // cout << "sum: " << sum << endl;
    if (l <= sum && sum <= r) {
        cout << 0 << "\n";
    } else if (sum > r) {
        ll ans = 0;
        for (ll i = r; i >= l; i--) {
            if (sum - i < l || i == 0) {
                continue;
            }
            sum -= i;
            ans++;
            if (sum <= i || sum == 0) {
                break;
            }
        }
        cout << ans << "\n";
    } else {
        ll ans = 0;
        for (ll i = l; i <= r; i++) {
            if (sum - i > r || i == 0) {
                continue;
            }
            sum -= i;
            ans++;
            if (sum >= i || sum == 0) {
                break;
            }
        }
        cout << ans << "\n";
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
