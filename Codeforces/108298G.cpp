#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 100000 + 50;

ll n, q, val[N];
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll ps, pt, ans, st, m, cur;
    cin >> n >> q >> s;
    for (ll i = 1; i <= n; i++)
        val[i] = val[i - 1] + i;
    for (ll i = 1; i <= q; i++) {
        cin >> t >> st;
        m = t.size();
        ans = cur = 0;
        for (ll j = 0; j <= m - 1; j++) {
            ps = j + st - 1;
            pt = j;
            if (s[ps] == t[pt])
                cur++;
            else {
                ans += val[cur];
                cur = 0;
            }
        }
        cout << ans + val[cur] << endl;
    }
    return 0;
}
