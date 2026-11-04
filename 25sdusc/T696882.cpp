#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    if (n == 3) {
        cout << "1 0 4\n0 3 0\n2 0 5" << endl;
        return;
    }
    ll ans[n + 10][n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        ans[i][i] = i * 2 - 1;
    }
    for (ll i = 1, index = n * 2; i <= n / 2; i++) {
        ans[i][i + (n / 2) + (n % 2)] = index;
        index -= 2;
    }
    for (ll i = n, index = 2; i > (n / 2); i--) {
        ans[i][i - (n / 2)] = index;
        index += 2;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
