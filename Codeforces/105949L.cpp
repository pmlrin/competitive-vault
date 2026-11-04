#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17;

ll n, S[N], tmp[N];

ll calcLen(ll len) {
    ll t1 = (len) * (len + 1) / 2;
    ll t2 = (len) * (len + 1) * (2 * len + 1) / 6;
    ll t3 = len * t1;
    return t3 - t2 + t1;
}

ll calcAbs(ll l, ll r) {
    ll ret = 0, len = r - l + 1;
    S[l - 1] = 0;
    for (ll i = l; i <= r; i++) {
        S[i] = S[i - 1] + tmp[i];
    }
    sort(S + l - 1, S + r + 1);
    for (ll i = l - 1; i <= r; i++) {
        ll base = (i - l + 1) - (r - i);
        ret += S[i] * base;
    }
    return ret;
}

void solve() {
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    string s;
    cin >> n >> s;
    s = " " + s + " ";
    ll L = 0, flag1 = 0, flag2 = 0;
    ll an = 0, bn = 0, cn = 0;
    for (ll i = 1; i <= n + 1; i++) {
        if (s[i] == 'a') {
            tmp[i] = 1;
            flag1 = 1;
        } else if (s[i] == 'b') {
            tmp[i] = -1;
            flag2 = 1;
        } else {
            tmp[i] = 0;
            if (flag1 && flag2) {
                ans2 += (calcLen(i - 1 - L) - calcAbs(L + 1, i - 1)) / 2;
            }
            L = i;
            flag1 = flag2 = 0;
        }
    }
    ans1 += calcAbs(1, n);
    L = flag1 = flag2 = 0;
    an = bn = cn = 0;
    for (ll i = 1; i <= n + 1; i++) {
        if (s[i] == 'a') {
            tmp[i] = 1;
            flag1 = 1;
        } else if (s[i] == 'c') {
            tmp[i] = -1;
            flag2 = 1;
        } else {
            tmp[i] = 0;
            if (flag1 && flag2) {
                ans2 += (calcLen(i - 1 - L) - calcAbs(L + 1, i - 1)) / 2;
            }
            L = i;
            flag1 = flag2 = 0;
        }
    }
    ans1 += calcAbs(1, n);
    L = flag1 = flag2 = 0;
    an = bn = cn = 0;
    for (ll i = 1; i <= n + 1; i++) {
        if (s[i] == 'b') {
            tmp[i] = 1;
            flag1 = 1;
        } else if (s[i] == 'c') {
            tmp[i] = -1;
            flag2 = 1;
        } else {
            tmp[i] = 0;
            if (flag1 && flag2) {
                ans2 += (calcLen(i - 1 - L) - calcAbs(L + 1, i - 1)) / 2;
            }
            L = i;
            flag1 = flag2 = 0;
        }
    }
    ans1 += calcAbs(1, n);
    ans1 /= 2;
    an = bn = cn = 0;
    for (ll i = 1; i <= n + 1; i++) {
        if (s[i] == 'a') {
            an++;
        } else {
            ans3 += calcLen(an);
            an = 0;
        }
        if (s[i] == 'b') {
            bn++;
        } else {
            ans3 += calcLen(bn);
            bn = 0;
        }
        if (s[i] == 'c') {
            cn++;
        } else {
            ans3 += calcLen(cn);
            cn = 0;
        }
    }
    cout << ans1 - ans2 - ans3 << endl;
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
