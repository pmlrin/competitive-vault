#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, m, k;
    cin >> n >> m;
    ll a[n + 10] = {}, b[n + 10] = {}, S[n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = max(0ll, a[i] - a[i - 1]);
        S[i] = S[i - 1] + b[i];
    }
    cin >> k;
    for (ll i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        cout << k + S[r] - S[l] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*6 2
3 2 4 5 3 6
2
2 4
3 6*/
