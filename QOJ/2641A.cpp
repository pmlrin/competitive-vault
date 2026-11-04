#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t l128;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

ll n, k, a, b;

l128 mygcd(l128 a, l128 b) { return b ? mygcd(b, a % b) : a; }

l128 check(l128 x) {
    l128 res = 0;
    for (l128 i = 1; i <= 2e6; i++) {
        l128 r = min((l128)n, (x - 2 * b * i + a * i * i) / 2 / a / i);
        l128 l = 1 + i;
        res += max(r - l + 1, (l128)0);
    }
    // cout << (ll)res << endl;
    return res;
}

void solve() {
    cin >> n >> k >> a >> b;
    l128 g = mygcd(a, b);
    a /= g, b /= g;
    l128 l = 1, r = 5e18, ans = 0;
    while (l <= r) {
        l128 mid = (l + r) / 2;
        // cout << (ll)mid << endl;
        if (check(mid) < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    g = mygcd(ans, a);
    ans /= g, a /= g;
    cout << (ll)ans << " " << (ll)a << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
