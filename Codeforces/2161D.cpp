#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0, inf = 1145141919810;

void solve() {
    ll n, ans = inf;
    cin >> n;
    vector<ll> pos[n + 10], f[n + 10];
    ll len[n + 10] = {};
    for (ll i = 1, a; i <= n; i++) {
        cin >> a;
        pos[a].push_back(i);
        f[i].push_back(inf);
        f[a].push_back(inf);
        len[a]++;
    }
    for (ll i = 0; i <= len[1]; i++) {
        f[1][i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        ll res = len[i], cur = 0;
        vector<ll> g(len[i - 1] + 1);
        for (ll j = 0; j <= len[i - 1]; j++) {
            if (j < len[i - 1]) {
                while (cur < len[i] && pos[i - 1][j] > pos[i][cur]) {
                    cur++, res--;
                }
            } else {
                res = 0;
            }
            g[j] = f[i - 1][j] + res;
        }
        for (ll j = len[i - 1] - 1; j >= 0; j--) {
            g[j] = min(g[j], g[j + 1]);
        }
        f[i][len[i]] = f[i - 1][0] + len[i];
        cur = max(len[i - 1] - 1, 0ll);
        for (ll j = len[i] - 1; j >= 0; j--) {
            while (cur >= 1 && pos[i - 1][cur] > pos[i][j]) {
                cur--;
            }
            f[i][j] = min(f[i][j + 1], g[cur] + j);
        }
    }
    cout << f[n][0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
1
9
1 2 2 1 1 2 1 2 2

2
5
1 2 2 2 3
8
2 3 1 2 3 3 3 2

2 3

1
5
1 2 2 2 3
 */
