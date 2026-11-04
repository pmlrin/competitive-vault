#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 13, inf = 1e17, mod = 998244353;

ll n, m;
void solve() {
    ll b, c, l, r, ans = 0;
    cin >> b >> c >> l >> r;
    auto f = [&](ll x) { return x * x + b * x + c; };
    for (ll i = l; i <= r; i++) {
        if (i % 2 == 0) {
            ans += f(i);
        }
    }
    cout << ans * 2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}