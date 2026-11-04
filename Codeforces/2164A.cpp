#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n, x;
    cin >> n;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> x;
    /*ll big = 0, sma = 0;
    for (ll i = 1; i <= n; i++) {
        if (a[i] > x)
            big++;
        if (a[i] < x)
            sma++;
    }
    if (big == n || sma == n)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;*/
    if (n == 1 && a[1] == x) {
        cout << "YES" << endl;
        return;
    }
    for (ll i = 1; i <= n - 1; i++) {
        if (min(a[i], a[i + 1]) <= x && x <= max(a[i], a[i + 1])) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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
