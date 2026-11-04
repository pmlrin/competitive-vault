#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], b[n + 10];
    map<ll, ll> c, fa, fa1;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        c[a[i]]++;
    }
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    for (auto [k,v]: c) {
        for (ll i = 1; i * i <= k + 1; i++) {
            if (k % i == 0) {
                fa[i] += v;
                if (i != k / i) {
                    fa[k / i] += v;
                }
            }
            if ((k + 1) % i == 0) {
                fa1[i] += v;
                if (i != (k + 1) / i) {
                    fa1[(k + 1) / i] += v;
                }
            }
        }
    }
    ll ans = 2;
    for (auto [k,v]: fa) {
        if (v >= 2 && k != 1) {
            cout << 0 << endl;
            return;
        }
        if (k != 1 && v >= 1 && fa1.count(k) >= 1 && fa1[k] >= 1) {
            ans = min(ans, 1ll);
        }
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
