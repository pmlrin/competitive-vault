#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17, mod = 998244353;

void solve() {
    ll l, r, ans1 = 0, ans2 = 0;
    cin >> l >> r;
    for (ll i = l; i <= min(l + 9, r); i++) {
        ll j = i;
        while (j) {
            if (j % 10 > ans1) {
                ans1 = j % 10;
                ans2 = i;
            }
            j /= 10;
        }
    }
    cout << ans1 << " ";
    string sl = to_string(l), sr = to_string(r);
    if (sl.size() == sr.size()) {
        cout << ans2 << endl;
    } else {
        ans1 = 9;
        ll ans3 = pow(10, max(0ll, (ll) sr.size() - 1)) + ans1;
        ll ans4 = pow(10, max(0ll, (ll) sr.size() - 2)) + ans1;
        if (ans3 <= r && ans3 >= l) {
            cout << ans3 << endl;
        } else if (ans4 <= r && ans4 >= l && sr.size() - sl.size() >= 2) {
            cout << ans4 << endl;
        } else {
            cout << ans2 << endl;
        }
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
/*4
11 17
8 39
5 27
1 2*/
