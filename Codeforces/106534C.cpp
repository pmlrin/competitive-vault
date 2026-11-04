#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17, mod = 998244353;

void solve() {
    ll n;
    cin >> n;
    ll l = 1, r = n;
    if (n % 4 != 2) {
        for (ll i = 1; i <= n; i++) {
            if ((i - 1) % 4 <= 1) {
                cout << l << " ";
                l++;
            } else {
                cout << r << " ";
                r--;
            }
        }
    } else {
        cout << n << " " << n - 3 << " " << n - 2 << " " << n - 1 << " " << 1 << " ";
        l = 2, r = n - 4;
        for (ll i = 2; i <= n - 4; i++) {
            if ((i - 1) % 4 <= 1) {
                cout << l << " ";
                l++;
            } else {
                cout << r << " ";
                r--;
            }
        }
    }
    cout << endl;
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
