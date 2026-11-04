#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0, inf = 1145141919810;

void solve() {
    ll n, minn = inf, maxn = -inf;
    cin >> n;
    ll a[n + 10], b[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        minn = min(a[i], minn);
        maxn = max(a[i], maxn);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    ll flag = 1;
    for (ll i = 2; i <= n; i++) {
        if (a[i - 1] > a[i])
            flag = 0;
    }
    if (flag == 1) {
        cout << -1 << endl;
        return;
    }
    ll k1 = max(maxn - a[1], a[1] - minn); //min
    ll k2 = max(maxn - a[n], a[n] - minn); //max
    vector<ll> res;
    for (ll i = 1; i <= n; i++) {
        if (a[i] != b[i])
            res.push_back(a[i]);
    }
    for (auto i: res) {
        if (maxn - i >= i - minn)
            k2 = min(k2, maxn - i);
        if (maxn - i <= i - minn)
            k1 = min(k1, i - minn);
    }
    cout << min(k1, k2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
2 3 1 4
1 3 2 4
 */
