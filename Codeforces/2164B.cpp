#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll r = 2; r <= n; r++) {
        for (ll l = 1; l < r; l++) {
            if (a[r] % a[l] % 2 == 0) {
                cout << a[l] << " " << a[r] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
