#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 250000 + 10;

ll n, a[N], q;
ll dou0[N], dou1[N], num0[N], num1[N];

void solve() {
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    dou0[1] = dou1[1] = 0;
    num0[0] = num1[0] = 0;
    a[0] = a[n + 1] = -1;
    for (ll i = 1; i <= n; i++) {
        if (a[i] == 0) {
            num0[i] = num0[i - 1] + 1;
            num1[i] = num1[i - 1];
        } else {
            num0[i] = num0[i - 1];
            num1[i] = num1[i - 1] + 1;
        }

        if (i == 2 && a[i] == a[i - 1]) {
            if (a[i] == 0) {
                dou0[i] = dou0[i - 1] + 1;
                dou1[i] = dou1[i - 1];
            } else {
                dou1[i] = dou1[i - 1] + 1;
                dou0[i] = dou0[i - 1];
            }
        } else if (i >= 3 && a[i] == a[i - 1]) {
            if (a[i] == 0 && a[i - 2] == 1) {
                dou0[i] = dou0[i - 1] + 1;
                dou1[i] = dou1[i - 1];
            }
            if (a[i] == 0 && a[i - 2] == 0) {
                dou0[i] = dou0[i - 1];
                dou1[i] = dou1[i - 1];
            }
            if (a[i] == 1 && a[i - 2] == 0) {
                dou1[i] = dou1[i - 1] + 1;
                dou0[i] = dou0[i - 1];
            }
            if (a[i] == 1 && a[i - 2] == 1) {
                dou1[i] = dou1[i - 1];
                dou0[i] = dou0[i - 1];
            }
        } else {
            dou0[i] = dou0[i - 1];
            dou1[i] = dou1[i - 1];
        }
        //cout << dou0[i] << " ";
    }
    //cout << endl;
    for (ll i = 1, l, r, d0, d1, n0, n1, ans; i <= q; i++) {
        cin >> l >> r;
        d0 = dou0[r] - dou0[l - 1];
        d1 = dou1[r] - dou1[l - 1];
        n0 = num0[r] - num0[l - 1];
        n1 = num1[r] - num1[l - 1];
        if (a[l] == a[l - 1] && (l <= 2 || (l >= 3 && a[l] != a[l - 2]))) {
            if (a[l] == 0)
                d0--;
            else
                d1--;
        }
        if (a[l] == a[l + 1] && a[l] == a[l - 1]) {
            if (a[l] == 0)
                d0++;
            else
                d1++;
        }
        if (n0 % 3 != 0 || n1 % 3 != 0) {
            cout << -1 << endl;
            continue;
        }
        //cout << d0 << " " << d1 << endl;
        ans = n0 / 3 + n1 / 3;
        if (d0 <= 0 && d1 <= 0)
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }
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
12 1
0 0 1 1 1 1 1 0 1 0 1 0
4 12
 */
