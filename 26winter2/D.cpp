#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

long double f(long double h, long double c, ll x) {
    x = x / 2;
    return ((x + 1) * 1.0 * h + x * 1.0 * c) / (2 * x * 1.0 + 1);
}

void solve() {
    ll h, c, t;
    cin >> h >> c >> t;
    if (t == h) {
        cout << 1 << endl;
    } else if (t > (h + c) / 2 && t < h) {
        long double cur = fabs((h + c) * 1.0 / 2.0 - t);
        ll fans = 2;

        long double ans = (h - t) * 1.0 / (2 * t * 1.0 - h - c);
        ll lans = (ll)(ans * 2 + 1);
        if (lans % 2 == 0) {
            lans++;
        }
        for (ll i = max(1ll, lans - 300); i <= lans + 300; i += 2) {
            if (cur > fabs(f(h, c, i) - t)) {
                cur = fabs(f(h, c, i) - t);
                fans = i;
            }
        }
        cout << fans << endl;
        // printf("%.9lf %.9lf\n", f(h, c, 999997), f(h, c, 999999));

    } else {
        cout << 2 << endl;
    }
    return;
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
1
1000000 1 500001
 */