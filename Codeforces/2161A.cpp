#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll R, X, D, n, ans = 0;
    string a;
    cin >> R >> X >> D >> n >> a;
    for (ll i = 0; i <= n - 1; i++) {
        if (a[i] == '1' || (a[i] == '2' && R < X)) {
            ans++;
            R = max(0ll, R - D);
        }
    }
    cout << ans << endl;
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
