#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + 1 + n);
        ll ans;
        ans = abs(a[1] - a[2]);
        for (ll i = 1; i <= n; i += 2) {
            ans = max(ans, abs(a[i] - a[i + 1]));
        }
        cout << ans << endl;
    }
    return 0;
}
