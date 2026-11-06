#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], ans = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++) {
        ll tmp = 0;
        for (ll j = 1; j <= n; j++) {
            if (a[j] % a[i] == 0) {
                tmp++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << n - ans << endl;
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
