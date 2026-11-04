#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, flag = 1;
    cin >> n;
    ll a[n + 10];
    string ans;
    for (ll i = 0; i <= n; i++) {
        cin >> a[i];
        a[i]--;
        if (i != 0 && i != n) {
            a[i]--;
        }
        if (a[i] < 0) {
            flag = 0;
        }
    }
    for (ll i = 0; i < n; i++) {
        while (a[i] > 0 && a[i + 1] > 0) {
            a[i]--, a[i + 1]--;
            ans += "RL";
        }
        if (a[i] > 0) {
            flag = 0;
        }
        ans += "R";
    }
    if (a[n] > 0) {
        flag = 0;
    }
    for (ll i = 1; i <= n; i++) {
        ans += 'L';
    }
    if (flag == 0) {
        cout << "Impossible\n";
    } else {
        cout << ans << "\n";
    }
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
