#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 5000 + 50;

ll n, p[N], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (ll i = 1; i <= n; i++)
            cin >> p[i];
        for (ll i = 1; i <= n; i++) {
            ll pos, L = 0, R = 0, L1 = 0, R1 = 0;
            for (ll j = 1; j <= n; j++) {
                if (p[j] == i) {
                    pos = j;
                    break;
                }
            }
            for (ll j = 1; j <= pos - 1; j++) {
                if (p[j] > p[pos] && p[j] != -1)
                    L++;
            }
            for (ll j = pos + 1; j <= n; j++) {
                if (p[j] < p[pos] && p[j] != -1)
                    R++;
                if (p[j] != -1)
                    R1++;
            }
            ans = ans + min(L + R, L1 + R1);
            p[pos] = -1;
        }
        cout << ans << endl;
    }
    return 0;
}
