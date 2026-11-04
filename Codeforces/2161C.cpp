#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n, x, ans = 0, s = 0;
    cin >> n >> x;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll l = 1, r = n;
    vector<ll> pos;
    while (l <= r) {
        if (s + a[l] < x) {
            pos.push_back(a[l]);
            s += a[l++];
        } else {
            pos.push_back(a[r]);
            ans += a[r];
            s += a[r--];
        }
        s %= x;
    }
    cout << ans << endl;
    for (auto i: pos) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
