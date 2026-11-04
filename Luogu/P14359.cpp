#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 5e5 + 10;

ll n, k, a[N];
map<ll, ll> b;

void solve() {
    ll ans = 0, cur = 0;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    b[0] = 1;
    for (ll i = 1; i <= n; i++) {
        cur ^= a[i];
        if (b.count(k ^ cur)) {
            ans++;
            cur = 0;
            b.clear();
        }
        b[cur] = 1;
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
