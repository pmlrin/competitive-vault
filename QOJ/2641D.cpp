#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const string Num[] = {"1110111", "0010010", "1011101", "1011011",
                      "0111010", "1101011", "1101111", "1010010",
                      "1111111", "1111011", "0000000"};

ll checkNum(string a, string b) {
    for (ll i = 0; i <= 6; i++) {
        if (a[i] != b[i] && a[i] != 'W') {
            return 0;
        }
    }
    return 1;
}

string mask(string a, ll x) {
    string b = a;
    for (ll i = 0; i <= 6; i++) {
        if (x % 2) {
            b[i] = 'W';
        }
        x /= 2;
    }
    return b;
}

void solve() {
    ll n, K;
    cin >> n >> K;
    string s, a[n + 10];
    cin >> s;
    for (ll i = 1; i <= n; i++) {
        a[i].push_back(s[i * 5 - 4]);
    }
    cin >> s >> s;
    for (ll i = 1; i <= n; i++) {
        a[i].push_back(s[i * 5 - 5]);
        a[i].push_back(s[i * 5 - 2]);
    }
    cin >> s;
    for (ll i = 1; i <= n; i++) {
        a[i].push_back(s[i * 5 - 4]);
    }
    cin >> s >> s;
    for (ll i = 1; i <= n; i++) {
        a[i].push_back(s[i * 5 - 5]);
        a[i].push_back(s[i * 5 - 2]);
    }
    cin >> s;
    for (ll i = 1; i <= n; i++) {
        a[i].push_back(s[i * 5 - 4]);
    }

    ll f[n + 10][K + 10][2] = {}, g[n + 10][K + 10][2] = {},
                     g0[n + 10][K + 10][2] = {};
    g[0][0][1] = g0[0][0][1] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= (1ll << 7) - 1; j++) {
            string tmp = mask(a[i], j);
            ll cnt[11] = {}, val = 0,
               cost = __builtin_popcount((unsigned long long)j);
            for (ll k = 0; k <= 10; k++) {
                if (checkNum(tmp, Num[k])) {
                    cnt[k]++;
                    val++;
                }
            }
            if (cnt[10]) {
                for (ll k = 0; k <= K; k++) {
                    if (k - cost < 0) {
                        continue;
                    }
                    g0[i][k][1] += g0[i - 1][k - cost][1];
                    g0[i][k][0] += g0[i - 1][k - cost][0];

                    ll tmp1 = (f[i - 1][k - cost][1] + 1) * (val - 1) -
                              (cnt[0] && i != n),
                       tmp2 = f[i - 1][k - cost][0] * (val - 1);

                    if (f[i][k][1] < tmp1 && tmp1 >= 1 &&
                        g0[i - 1][k - cost][1] >= 1) {
                        f[i][k][1] = tmp1;
                        g[i][k][1] = g[i - 1][k - cost][1];
                    } else if (f[i][k][1] == tmp1 && tmp1 >= 1 &&
                               g0[i - 1][k - cost][1] >= 1) {
                        g[i][k][1] += g[i - 1][k - cost][1];
                    }

                    if (f[i][k][0] < tmp2 && tmp2 >= 1) {
                        f[i][k][0] = tmp2;
                        g[i][k][0] = g[i - 1][k - cost][0];
                    } else if (f[i][k][0] == tmp2 && tmp2 >= 1) {
                        g[i][k][0] += g[i - 1][k - cost][0];
                    }

                    if (f[i][k][1] == 0) {
                        g[i][k][1] = g0[i][k][1];
                    }
                    if (f[i][k][0] == 0) {
                        g[i][k][0] = g0[i][k][0];
                    }
                }
            } else {
                for (ll k = 0; k <= K; k++) {
                    if (k - cost < 0) {
                        continue;
                    }
                    g0[i][k][0] += g0[i - 1][k - cost][1];
                    g0[i][k][0] += g0[i - 1][k - cost][0];

                    ll tmp1 = (f[i - 1][k - cost][1] + 1) * val -
                              (cnt[0] && i != n),
                       tmp2 = f[i - 1][k - cost][0] * val;

                    if (f[i][k][0] < tmp1 && tmp1 >= 1 &&
                        g0[i - 1][k - cost][1] >= 1) {
                        f[i][k][0] = tmp1;
                        g[i][k][0] = g[i - 1][k - cost][1];
                    } else if (f[i][k][0] == tmp1 && tmp1 >= 1 &&
                               g0[i - 1][k - cost][1] >= 1) {
                        g[i][k][0] += g[i - 1][k - cost][1];
                    }

                    if (f[i][k][0] < tmp2 && tmp2 >= 1) {
                        f[i][k][0] = tmp2;
                        g[i][k][0] = g[i - 1][k - cost][0];
                    } else if (f[i][k][0] == tmp2 && tmp2 >= 1) {
                        g[i][k][0] += g[i - 1][k - cost][0];
                    }

                    if (f[i][k][1] == 0) {
                        g[i][k][1] = g0[i][k][1];
                    }
                    if (f[i][k][0] == 0) {
                        g[i][k][0] = g0[i][k][0];
                    }
                }
            }
        }
    }
    ll ans1 = 0, ans2 = 0;
    for (ll i = 0; i <= K; i++) {
        if (f[n][i][0] > ans1) {
            ans1 = f[n][i][0];
            ans2 = g[n][i][0];
        } else if (f[n][i][0] == ans1) {
            ans2 += g[n][i][0];
        }
        if (f[n][i][1] > ans1) {
            ans1 = f[n][i][1];
            ans2 = g[n][i][1];
        } else if (f[n][i][1] == ans1) {
            ans2 += g[n][i][1];
        }
    }
    cout << ans1 << " " << ans2 << endl;
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
