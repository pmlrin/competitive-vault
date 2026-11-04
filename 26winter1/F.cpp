#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 55, inf = 1e17;

ll n, a[N], sum = 0, ans = 0;
ll f[N][3];

ll dfs(ll step, ll cur) {
    if (step == n + 1) {
        return 0;
    }
    if (f[step][cur]) {
        return f[step][cur];
    }
    if (cur == 2) {
        return f[step][cur] = max(dfs(step + 1, 1) + a[step], dfs(step + 1, 2));
    } else {
        return f[step][cur] = min(dfs(step + 1, 1) + a[step], dfs(step + 1, 2));
    }
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ans = dfs(1, 2);
    cout << sum - ans << " " << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
