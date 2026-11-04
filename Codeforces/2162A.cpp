#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 20;

ll n, ans;

void solve() {
    cin >> n;
    ans = -1;
    for (ll i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        ans = max(a, ans);
    }
    cout << ans << endl;
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
