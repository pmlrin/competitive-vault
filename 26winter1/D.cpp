#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, ans = 0;
    cin >> n;
    map<ll, ll> a;
    for (ll i = 1, t; i <= n; i++) {
        cin >> t;
        if (t % 2 == 0) {
            a[t]++;
        }
    }
    while (!a.empty()) {
        auto p = a.rbegin();
        ll k = p->first, v = p->second;
        if (k % 2) {
            a.erase(k);
        } else {
            ans++;
            a.erase(k);
            a[k / 2] += v;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
