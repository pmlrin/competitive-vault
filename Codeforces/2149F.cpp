#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll d, h;

ll calc(ll n) { return n * (n + 1) / 2; }

ll check(ll num) {
    ll p1, p2, n1, n2;
    p1 = d / num;
    p2 = d / num + 1;
    n2 = d % num;
    n1 = num - n2;
    if (h + num - 1 - calc(p1) * n1 - calc(p2) * n2 >= 1)
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> h >> d;
        ll l = 1, r = d + 1, ans = 2 * d;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check(mid)) {
                ans = min(ans, d + mid - 1);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1
44 12
 */
