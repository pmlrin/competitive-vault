#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, k, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll ans = 0, an1 = 0, an2 = 0;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i <= n; i++) {
            b[i] = 0;
        }
        for (ll i = 1; i <= n; i++) {
            b[a[i]]++;
        }
        for (ll i = 0; i <= k - 1; i++) {
            if (b[i] == 0)
                an1++;
        }
        an2 = b[k];
        cout << max(an1, an2) << endl;
    }
    return 0;
}
