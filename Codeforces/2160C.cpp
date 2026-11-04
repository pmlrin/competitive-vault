#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

ll n, x, fx, cur;

ll setbit(ll num, ll pos, ll b) {
    if (((num >> (pos - 1)) & 1) == 1) {
        num -= (1ll << (pos - 1));
    }
    num += (b << (pos - 1));
    return num;
}

ll calc(ll cur, ll tmp) {
    x = (1ll << (cur - 1)), fx = 1;
    for (ll i = 1; tmp >= 1; tmp /= 2, i++) {
        ll now = tmp % 2;
        if ((((x ^ fx) >> (i - 1)) & 1) != now) {
            ll b = ((x >> (i - 1)) & 1) ^ 1;
            x = setbit(x, i, b);
            fx = setbit(fx, cur - i + 1, b);
        }
    }
    //cout << x << " " << fx << endl;
    if ((x ^ fx) == n)
        return 1;
    return 0;
}

void solve() {
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= 60; i++) {
        ans = max(ans, calc(i, n));
    }
    if (ans == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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

/*
 */
