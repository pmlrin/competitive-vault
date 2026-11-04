#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, tmp, ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> tmp;
        tmp ^= 3;
        ans += tmp * tmp * tmp;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
