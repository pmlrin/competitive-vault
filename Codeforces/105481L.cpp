#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 20;

ll a4_100[N], a_100[N];

ll isrun(ll x) {
    ll cnt = 0;
    for (ll i = 0; i <= 8; i++) {
        if ((x % (4 * (ll) pow(100, i))) == 0 && (x % (ll) pow(100, i + 1)) != 0)
            cnt++;
    }
    if (cnt == 1)
        return 1;
    return 0;
}

ll dpow(ll a, ll b) {
    ll ret = 1;
    for (ll i = 1; i <= b; i++)
        ret *= a;
    return ret;
}

void solve() {
    ll n, ans = 0;
    cin >> n;
    n += 1533;
    for (ll i = 8; n >= 1; i--) {
        ll cnt = 0;
        while (n >= a_100[i + 1] && cnt <= 23) {
            n -= a_100[i + 1];
            cnt++;
            ans += (ll) (dpow(100, i + 1));
            //cout << n << "-" << a_100[i + 1] << ans << endl;
        }
        if (n <= 0)
            break;
        cnt = 0;
        while (n >= a4_100[i] && cnt <= 23) {
            n -= a4_100[i];
            cnt++;
            ans += (ll) (4ll * dpow(100, i));
            //cout << n << "-" << a4_100[i] << " " << ans << endl;
        }
    }
    cout << ans - isrun(ans) << endl;
}

void debug() {
    ll x = 4000, cnt = 0;
    for (ll i = 1; i <= x; i++) {
        if (isrun(i))
            continue;
        cnt++;
    }
    //cout << cnt - 1533 << endl;
    //cout << isrun(1e18) << endl;
    //cout << a_100[9] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    a4_100[0] = 3;
    a_100[0] = 1;
    a_100[1] = a4_100[0] * 25 + 1;
    for (ll i = 1; i <= 8; i++) {
        a4_100[i] = a_100[i] * 4 - 1;
        a_100[i + 1] = a4_100[i] * 25 + 1;
    }
    //debug();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
7
 2
 3
 4
 114514
 998244353

 8

1
1

1
1000000000000000000

4
757575757575757576
1533
757575757575756043
757575757575756042
 */
