#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10] = {}, b[n + 10], k = -1;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    for (ll i = 1; i <= n; i++) {
        if (b[i] < 0) {
            k = max(k, -b[i]);
        }
    }
    ll L = -1, R = -1;
    for (ll i = 1; i <= n; i++) {
        if (b[i] < 0) {
            if (L == -1) {
                L = i;
                continue;
            }
            R = i - 1;
            ll maxn = 0;
            for (ll j = L; j <= R; j++) {
                maxn = max(maxn, b[j]);
            }
            if (maxn < k) {
                cout << "No" << endl;
                return;
            }
            L = i;
        }
    }
    cout << "Yes" << endl;
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
