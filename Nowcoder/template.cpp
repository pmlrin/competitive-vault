#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, cnt = 0;
    double x = 0.0100000001;
    cin >> n;
    cout << n * 2 << endl;
    for (ll i = 0; i <= 9; i++) {
        for (ll j = 0; j <= 9; j++) {
            cnt++;
            cout << fixed << setprecision(10) << x * i << " " << x * j << " "
                 << 0 << endl;
            cout << fixed << setprecision(10) << x * i << " " << x * j << " "
                 << 0.9901 << endl;
            if (cnt == n) {
                break;
            }
        }
        if (cnt == n) {
            break;
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
