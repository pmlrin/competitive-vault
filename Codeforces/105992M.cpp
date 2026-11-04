#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

ll getBit(ll x, ll p) { return ((x >> (p - 1)) & 1); }

void solve() {
    ll n, x, y, sum = 0, ans = 0;
    cin >> n >> x >> y;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 32; i >= 1; i--) {
        for (ll j = 1; j <= n; j++) {
            ans += getBit(a[j], i) * x;
            sum += getBit(a[j], i);
        }
        if (sum > 0 && i != 1) {
            if (sum > y) {
                ans += y;
            } else if (sum * x > y) {
                ans += y;
            } else {
                ans += sum * x;
            }
            sum *= 2;
        }
    }
    cout << (ll) ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
