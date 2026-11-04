#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int,int>

const ll N = 2005;
const ll M = N * N;
ll n, h, l, r, a[N], p[N], f[N][N], ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> h >> l >> r;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    f[0][0] = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= i; j++) {
            ll cur = ((p[i] - j) % h + h) % h;
            ll flag = 0;
            if (l <= cur && cur <= r)
                flag = 1;

            if (i > j)
                f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + flag;
            else
                f[i][j] = f[i - 1][j - 1] + flag;
        }
    }
    for (ll i = 0; i <= n; i++)
        ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}
