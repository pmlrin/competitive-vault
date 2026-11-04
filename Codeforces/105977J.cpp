#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

ll lb(ll x) { return x & -x; }

void solve() {
    ll n;
    vector<ll> ans;
    cin >> n;
    while (n != lb(n)) {
        ans.push_back(lb(n));
        n += lb(n);
    }
    ll jud = 0;
    for (ll i = 1; i <= n; i *= 2) {
        jud++;
    }
    if (jud % 2 == 0) {
        ans.push_back(n);
    }
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i << " ";
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
