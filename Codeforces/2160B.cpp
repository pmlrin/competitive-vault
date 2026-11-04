#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1e5 + 10;

ll n, b[N], a[N];

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    ll cur = 0;
    a[1] = ++cur;
    cout << a[1] << " ";
    for (ll i = 2; i <= n; i++) {
        ll add = b[i] - 1 - b[i - 1];
        if (add == i - 1)
            a[i] = ++cur;
        else
            a[i] = a[i - add - 1];
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
