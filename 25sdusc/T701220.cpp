#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6, inf = 1e17;

ll a[N];

void solve() {
    ll n = 0;
    for (ll i = 1; i <= 499999; i++) {
        a[++n] = 1;
    }
    for (ll i = 1; i <= 499999; i++) {
        a[++n] = 3;
    }
    for (ll i = 1; i <= 2; i++) {
        a[++n] = 2;
    }
    cout << n << endl;
    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
