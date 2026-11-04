#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 5e3 + 10, mod = 998244353, Ex = 5001;

ll n, a[N], f[N], ans = 0;

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    f[0] = 1;
    for (ll i = 1; i <= n; i++) {
        ll tal = 0;
        for (ll j = a[i] + 1; j <= Ex; j++) {
            tal += f[j];
            tal = (tal % mod + mod) % mod;
        }
        ans = (ans + tal) % mod;
        //cout << tal << endl;
        for (ll j = Ex; j >= 0; j--) {
            if (j + a[i] >= Ex) {
                f[Ex] = (f[Ex] + f[j]) % mod;
            } else {
                f[j + a[i]] = (f[j + a[i]] + f[j]) % mod;
            }
        }
    }
    cout << ans << endl;
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
