#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1000 + 50;

ll n, m, a[5][N], ans1 = 0, ans2 = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tx, ty;
    cin >> n >> m;
    for (ll i = 2; i <= n - 1; i++)
        for (ll j = 1; j <= 4; j++)
            a[j][i] = 1;
    for (ll i = 1; i <= m; i++) {
        cin >> tx >> ty;
        a[1][tx] = a[3][n - tx + 1] = 0;
        a[2][ty] = a[4][n - ty + 1] = 0;
    }
    for (ll i = 2; i <= n / 2; i++) {
        for (ll j = 1; j <= 4; j++)
            ans1 += a[j][i];
    }
    for (ll i = n - 1; i >= n - n / 2 + 1; i--) {
        for (ll j = 1; j <= 4; j++)
            ans2 += a[j][i];
    }
    if (n % 2 == 1) {
        if (a[1][n / 2 + 1] || a[2][n / 2 + 1] || a[3][n / 2 + 1] || a[4][n / 2 + 1]) {
            ans1++;
            ans2++;
        }
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}
