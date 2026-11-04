#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<ll, ll>
const ll base = 19260817;

void solve() {
    ll n, m, cnt = 0;
    cin >> n >> m;
    map<ull, ll> b;
    ll a[m * 2 + 10];
    ull pre[m * 2 + 10], suc[m * 2 + 10], mul[m * 2 + 10];
    mul[0] = 1;
    for (ll i = 1; i <= m * 2; i++) {
        mul[i] = mul[i - 1] * base;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> a[j];
            a[j + m] = a[j];
        }
        pre[0] = suc[m * 2 + 1] = 0;
        for (ll j = 1; j <= m * 2; j++) {
            pre[j] = pre[j - 1] + a[j] * mul[j];
        }
        for (ll j = 1; j <= m * 2; j++) {
            suc[j] = suc[j - 1] + a[m * 2 - j + 1] * mul[j];
        }
        ull has = pre[m * 2] - pre[m];
        for (ll j = 1; j <= m; j++) {
            has = min(has, (pre[j + m] - pre[j]) * mul[m - j]);
            // cout << (pre[j + m] - pre[j]) * mul[m - j] << endl;
        }
        for (ll j = 1; j <= m; j++) {
            has = min(has, (suc[j + m] - suc[j]) * mul[m - j]);
            // cout << (suc[j + m] - suc[j]) * mul[m - j] << endl;
        }
        // cout << has << endl;
        if (b.count(has) == 0) {
            b[has] = ++cnt;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
