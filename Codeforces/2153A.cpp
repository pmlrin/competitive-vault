#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 110;

ll n;
map<ll, ll> b;

void solve() {
    cin >> n;
    b.clear();
    for (ll i = 1, a; i <= n; i++) {
        cin >> a;
        b[a]++;
    }
    cout << b.size() << endl;
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
