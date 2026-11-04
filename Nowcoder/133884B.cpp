#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n + 10] = {}, b[n + 10] = {}, ans = 0;
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        ans = max(ans, ++a[u]);
        ans = max(ans, ++b[v]);
    }
    cout << n - ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
