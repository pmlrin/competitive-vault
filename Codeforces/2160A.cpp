#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 120;

ll n, a[N];
map<ll, ll> b;

void solve() {
    cin >> n;
    b.clear();
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    for (ll i = 0; i <= 100; i++) {
        if (b.count(i) == 0) {
            cout << i << endl;
            return;
        }
    }
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
