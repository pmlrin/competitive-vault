#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 150 + 50;

ll n, a[N], b[N], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(b, 0, sizeof(b));
        ans = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            b[a[i]]++;
        }
        for (ll i = 1; i <= n; i++) {
            if (b[i])
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
