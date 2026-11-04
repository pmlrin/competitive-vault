#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], p0 = 0, p1 = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2)
            p1++;
        else
            p0++;
    }
    if (p0 && p1) {
        sort(a + 1, a + 1 + n);
    }
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
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
