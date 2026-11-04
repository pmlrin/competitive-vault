#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, k, l, r, a[N];
map<ll, ll> b1, b2;

ll calc(ll l1, ll r1, ll l2, ll r2) {
    if (r1 < l2)
        return 0;
    l1 = max(l1, l2);
    r1 = min(r1, r2);
    if (l1 > r1)
        return 0;
    return r1 - l1 + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll L = 0, R1 = 0, R2 = 0;
        ll ans = 0;
        cin >> n >> k >> l >> r;
        b1.clear();
        b2.clear();
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 1; i <= n - l + 1; i++) {
            L = i;
            if (b1.count(a[L - 1]) >= 1) {
                b1[a[L - 1]]--;
                if (b1[a[L - 1]] <= 0)
                    b1.erase(a[L - 1]);
            }
            if (b2.count(a[L - 1]) >= 1) {
                b2[a[L - 1]]--;
                if (b2[a[L - 1]] <= 0)
                    b2.erase(a[L - 1]);
            }
            while (b1.size() < k && R1 < n) {
                R1++;
                b1[a[R1]]++;
            }
            while (b2.size() <= k && R2 < n) {
                R2++;
                b2[a[R2]]++;
            }
            ll len1 = R1 - L + 1, len2 = R2 - L;
            //cout << L << " " << R1 << " " << R2 << endl;
            if (b2.size() == k)
                len2++;
            if (b1.size() == k && (b2.size() == k || b2.size() == k + 1))
                ans += calc(len1, len2, l, r);
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1
5 2 2 3
1 2 1 3 2
 */


/*
1
5 2 2 3
1 2 1 3 2

1
2 2 1 2
1 2

1
4 1 1 4
1 1 1 1

1
6 2 1 6
1 1 1 2 2 2
 */
