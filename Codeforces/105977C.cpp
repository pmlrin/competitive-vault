#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17;

ll n, a[N], b[N];

ll check(ll x) {
    ll stk[n + 10], top = 0;
    for (ll i = 1; i <= n; i++) {
        stk[++top] = (a[i] >= x);
        while (top >= 3) {
            if (stk[top - 2] + stk[top - 1] + stk[top] == 0) {
                top -= 2;
                stk[top] = 0;
            } else if (stk[top] == 0) {
                break;
            } else if (stk[top - 2] + stk[top - 1] + stk[top] == 1) {
                top -= 2;
                stk[top] = 0;
            } else if (stk[top - 2] + stk[top - 1] + stk[top] == 2) {
                top -= 2;
                stk[top] = 1;
            } else {
                break;
            }
        }
    }
    ll ret = 0;
    for (ll i = 1; i <= top; i++) {
        if (stk[i] == 1)
            ret++;
        else
            ret--;
    }
    return (ret > 0);
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    ll L = 1, R = n, ans = 0;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (check(b[mid])) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << b[ans] << endl;
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
/*
2
9
9 9 8 2 4 4 3 5 3
7
1 0 0 1 0 0 1
*/
