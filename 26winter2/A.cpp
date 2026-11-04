#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

ll n, m, k;
map<PII, ll> a;

ll jud(ll x, ll y) {
    if (a.count({x, y}) >= 1 && a.count({x, y + 1}) >= 1 &&
        a.count({x + 1, y}) >= 1 && a.count({x + 1, y + 1}) >= 1) {
        return 1;
    }
    return 0;
}

void solve() {
    cin >> n >> m >> k;
    for (ll i = 1, x, y; i <= k; i++) {
        cin >> x >> y;
        a[{x, y}] = 1;
        if (jud(x - 1, y - 1) || jud(x - 1, y) || jud(x, y - 1) || jud(x, y)) {
            cout << i << endl;
            return;
        }
    }
    cout << 0 << endl;
    return;
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
