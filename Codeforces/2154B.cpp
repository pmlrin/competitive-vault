#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll inf = 1145141919810;

void solve() {
    ll n, ans = 0;
    cin >> n;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    ll maxn = a[1];
    for (ll i = 1; i <= n; i++) {
        maxn = max(maxn, a[i]);
        if (i % 2 == 0)
            a[i] = maxn;
    }
    a[0] = a[n + 1] = inf;
    for (ll i = 1; i <= n; i += 2) {
        ll minn = min(a[i - 1], a[i + 1]);
        if (minn <= a[i])
            ans += a[i] - minn + 1;
    }
    cout << ans << endl;
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
