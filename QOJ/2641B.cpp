#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, m, a, b, ans = inf;
    cin >> n >> m >> a >> b;
    ll s[n * m + 10] = {}, cnt[n * m + 10] = {};
    for (ll i = 1, tmp; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> tmp;
            cnt[tmp]++;
        }
    }
    sort(cnt + 1, cnt + 1 + n * m);
    for (ll i = 1; i <= n * m; i++) {
        s[i] = s[i - 1] + cnt[i];
    }
    for (ll i = n * m, cur = 0; i >= 0; i--) {
        ans = min(ans, s[i] * a + cur + cnt[0] * (n * m - i) * b);
        cur += (n * m - i) * b * cnt[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
