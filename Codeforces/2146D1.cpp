#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 10;

ll l, r, a[N];

void solve() {
    cin >> l >> r;
    cout << (r + 1) * r << endl;
    ll cur = (1ll << 30) - 1;
    for (ll i = l; i <= r; i++)
        a[i] = 0;
    for (ll i = r; i >= l; i--) {
        while (((i ^ cur) > r || a[i ^ cur]) && cur >= 1)
            cur = (cur + 1) / 2 - 1;
        a[i ^ cur] = i;
    }
    for (ll i = l; i <= r; i++)
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
