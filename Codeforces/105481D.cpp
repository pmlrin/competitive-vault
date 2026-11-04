#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

double calc(PII a,PII b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

void solve() {
    ll n;
    cin >> n;
    PII a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    double f[n + 10][n + 10];
    for (ll i = 1; i <= n; i++) {
        for (ll j = i; j <= n; j++) {
            f[i][j] = calc(a[i], a[j]);
        }
    }
    for (ll len = 2; len <= n; len++) {
        for (ll l = 1; l <= n; l++) {
            ll r = l + len - 1;
            if (r > n)
                continue;
            f[l][r] = max({f[l][r], f[l + 1][r], f[l][r - 1]});
        }
    }
    double g[n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= i - 1; j++) {
            g[i] = max(g[i], g[j] + f[j + 1][i]);
        }
    }
    printf("%.8lf\n", g[n]);
}

int main() {
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

/*
7
 1 0
 0 1
 0 0
 1 1
 1 2
 3 2
 3 3
 */
