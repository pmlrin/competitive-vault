#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll inf = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n + 10], f[n + 10], minf;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = 1e18;
    }
    if (k == 1) {
        cout << 0 << endl;
        return;
    }
    sort(a + 1, a + 1 + n);
    minf = f[0] = -a[1];
    a[n + 1] = 0;
    for (ll i = k; i <= n; i++) {
        f[i] = minf + a[i] - a[i + 1];
        minf = min(minf, f[i - k + 1]);
    }
    cout << f[n] << endl;
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

/*
5 3
8 7 114514 114513 222222222
 */
