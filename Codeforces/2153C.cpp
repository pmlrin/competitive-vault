#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 20;

ll n, a[N], rlen;
map<ll, ll> b, b2;
vector<ll> res;

void solve() {
    ll ans = 0;
    cin >> n;
    b.clear();
    b2.clear();
    res.clear();
    res.push_back(0);
    rlen = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll flag = 0;
    for (auto [key,val]: b) {
        if (val >= 2) {
            b2[key] += val - (val % 2);
            b[key] -= val - (val % 2);
            flag += val / 2;
        }
    }
    for (auto [key,val]: b) {
        if (val >= 1) {
            res.push_back(key);
            rlen++;
        }
    }
    if (flag == 0) {
        cout << 0 << endl;
    } else if (flag == 1) {
        ll base = 0, p1 = 0, p2 = 0;
        for (auto [key,val]: b2) {
            base += key * val;
        }
        for (ll i = 1; i <= rlen; i++) {
            if (base > res[i])
                ans = max(ans, base + res[i]);
        }
        if (rlen >= 2) {
            for (ll i = 1; i <= rlen - 1; i++) {
                if (base + res[i] > res[i + 1] && base + res[i + 1] > res[i])
                    ans = max(ans, base + res[i] + res[i + 1]);
            }
        }
        cout << ans << endl;
    } else {
        ll base = 0, p1 = 0, p2 = 0;
        for (auto [key,val]: b2) {
            base += key * val;
        }
        ans = base;
        for (ll i = 1; i <= rlen; i++) {
            if (base > res[i])
                ans = max(ans, base + res[i]);
        }
        if (rlen >= 2) {
            for (ll i = 1; i <= rlen - 1; i++) {
                if (base + res[i] > res[i + 1] && base + res[i + 1] > res[i])
                    ans = max(ans, base + res[i] + res[i + 1]);
            }
        }
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
6
2 2 1 1 19 111
 */
