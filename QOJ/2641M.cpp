#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 10, inf = 1e17;

ll a[N], b[N], s[N], vis[N];
double p[N], ans = 0;

void calc(ll l, ll r) {
    if (l == r) {
        p[s[l]] = 1;
        return;
    }
    ll mid = (l + r) / 2;
    calc(l, mid);
    calc(mid + 1, r);
    double tmp[N] = {};
    for (ll i = l; i <= mid; i++) {
        for (ll j = mid + 1; j <= r; j++) {
            tmp[s[i]] +=
                p[s[i]] * p[s[j]] * (a[s[i]] * 1.0 / (a[s[i]] + b[s[j]]));
            tmp[s[j]] +=
                p[s[i]] * p[s[j]] * (b[s[j]] * 1.0 / (a[s[i]] + b[s[j]]));
        }
    }
    for (ll i = l; i <= r; i++) {
        p[s[i]] = tmp[s[i]];
    }
}

void dfs(ll step) {
    if (step == 9) {
        calc(1, 8);
        ans = max(ans, p[1]);
        return;
    }
    for (ll i = 1; i <= 8; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            s[step] = i;
            dfs(step + 1);
            s[step] = 0;
            vis[i] = 0;
        }
    }
}

void solve() {
    for (ll i = 1; i <= 8; i++) {
        cin >> a[i] >> b[i];
    }
    dfs(1);
    cout << fixed << setprecision(8) << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
