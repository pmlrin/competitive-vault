#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], b[n + 10];
    ll p1 = 0, pn = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            p1 = i;
        if (a[i] == n)
            pn = i;
        b[i] = a[i];
    }
    swap(b[p1], b[pn]);
    for (ll i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
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
