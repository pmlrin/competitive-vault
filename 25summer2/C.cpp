#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>

const ll N = 200000 + 10, inf = 1145141919810;

string t;
ll maxk, n, e[50][50], f[120][40][120], s[N];

void add(ll x, ll y, ll len) { e[x][y] = len; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    char u, v;
    ll len, ans = -inf, tmp;
    cin >> t >> maxk >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> u >> v >> len;
        add(u - 'a' + 1, v - 'a' + 1, len);
    }
    len = t.size(), t = ' ' + t;
    for (ll i = 1; i <= len; i++)
        s[i] = t[i] - 'a' + 1;
    for (ll i = 1; i <= 26; i++) {
        if (s[1] == i) {
            f[1][i][0] = 0;
            f[1][i][1] = -inf;
        } else {
            f[1][i][0] = -inf;
            f[1][i][1] = 0;
        }
        for (ll j = 2; j <= maxk; j++)
            f[1][i][j] = -inf;
    }

    for (ll i = 2; i <= len; i++) { // 100
        for (ll j = 1; j <= 26; j++) {
            if (s[i] == j)
                f[i][j][0] = f[i - 1][s[i - 1]][0] + e[s[i - 1]][s[i]];
            else
                f[i][j][0] = -inf;

            for (ll k = 1; k <= maxk; k++) {
                f[i][j][k] = -inf;
                for (ll prej = 1; prej <= 26; prej++) {
                    tmp = -inf;
                    if (j != s[i])
                        tmp = max(tmp, f[i - 1][prej][k - 1] + e[prej][j]);
                    else {
                        tmp = max(tmp, f[i - 1][prej][k] + e[prej][j]);
                    }
                    f[i][j][k] = max(f[i][j][k], tmp);
                }
            }
        }
    }
    for (ll i = 1; i <= 26; i++) {
        for (ll j = 0; j <= maxk; j++) {
            ans = max(ans, f[len][i][j]);
        }
    }
    /*for (ll i = 1; i <= len; i++)
        for (ll j = 1; j <= 26; j++)
            for (ll k = 0; k <= maxk; k++)
                cout << f[i][j][k] << " ";*/
    // cout << f[len][s[len] + 1][0] << endl;
    cout << ans << endl;
    return 0;
}
/*
abc 100
3
bc -2
ad -2
dc -2

aaaa 0
3
a a 10
a b 25
a c 9
 */
