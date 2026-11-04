#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, a[N], max1, g, pg, b[N];

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = 0;
    }
    max1 = 0;
    pg = g = a[1];
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                b[j]++;
                if (b[j] != i)
                    max1 = max(max1, b[j]);
                if (j != a[i] / j) {
                    b[a[i] / j]++;
                    if (b[a[i] / j] != i)
                        max1 = max(max1, b[a[i] / j]);
                }
            }
        }
        g = gcd(g, a[i]);
        for (ll j = pg; j > g; j--) {
            if (b[j] != i)
                max1 = max(max1, b[j]);
        }
        pg = g;
        if (max1 == 0)
            cout << 0 << " ";
        else
            cout << max1 << " ";
    }
    cout << endl;
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
