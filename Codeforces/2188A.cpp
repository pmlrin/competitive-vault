#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], l = 1, r = n;
    for (ll i = 1; i <= n; i++) {
        if (i % 2)
            a[i] = l, l++;
        else
            a[i] = r, r--;
    }
    for (ll i = n; i >= 1; i--)
        cout << a[i] << " ";
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
