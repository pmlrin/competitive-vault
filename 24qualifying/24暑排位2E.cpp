#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

const ll N = 105, M = 30;
ll n, k, f[N][N][M], a[N], ans = 0, cnt = 0;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    s = ' ' + s;
    for (ll i = 1; i <= n; i++)
        a[i] = s[i] - 'a' + 1;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            if (j == 0) {
                f[i][j][0] = 1;
            }
            if (j == 1) {
                f[i][j][a[i]] = 1; //y
                for (ll k = 1; k <= 26; k++) {
                    if (k == a[i])
                        continue;
                    f[i][j][k] = f[i - 1][j][k]; //n
                }
            }
            if (j >= 2) {
                for (ll k = 1; k <= 26; k++) {
                    f[i][j][a[i]] += f[i - 1][j - 1][k]; //y
                    if (k == a[i])
                        continue;
                    f[i][j][k] = f[i - 1][j][k]; //n
                }
            }
        }
    }
    for (ll i = n; i >= 0; i--) {
        for (ll j = 1; j <= 26; j++) {
            f[n][i][0] += f[n][i][j];
        }
        //cout << f[n][i][0] << endl;
        if (cnt + f[n][i][0] >= k) {
            ans += (k - cnt) * (n - i);
            cout << ans << endl;
            return 0;
        }
        cnt += f[n][i][0];
        ans += f[n][i][0] * (n - i);
    }
    cout << "-1" << endl;
    return 0;
}
