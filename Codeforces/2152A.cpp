#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200;

ll n, a[N];
map<ll, ll> b;

void solve() {
    cin >> n;
    b.clear();
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    cout << b.size() * 2 - 1 << endl;
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
