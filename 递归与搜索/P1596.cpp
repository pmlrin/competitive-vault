#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100 + 10;
const ll nxtX[] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
const ll nxtY[] = {0, 1, -1, 0, 0, 1, -1, 1, -1};

ll n, m, vis[N][N], ans = 0;
string s[N];

void dfs(ll x, ll y) {
    vis[x][y] = 1;
    for (ll i = 1; i <= 8; i++) {
        ll ux = x + nxtX[i], uy = y + nxtY[i];
        if (ux < 1 || ux > n || uy < 1 || uy > m) {
            continue;
        }
        if (vis[ux][uy]) {
            continue;
        }
        if (s[ux][uy] == '.') {
            continue;
        }
        dfs(ux, uy);
    }
}

int main() {
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (!vis[i][j] && s[i][j] == 'W') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}