#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0, inf = 1e18 + 10;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 2;; i++) {
        for (ll j = 1; j <= n; j++) {
            if (gcd(i, a[j]) == 1) {
                cout << i << endl;
                return;
            }
        }
    }
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
