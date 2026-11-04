#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 400 + 10;
const ll nxtX[] = {0, 2, 1, -2, -1, 2, 1, -2, -1};
const ll nxtY[] = {0, 1, 2, 1, 2, -1, -2, -1, -2};

ll n, m, x, y, vis[N][N];

void bfs() {
    queue<PII> q;
    vis[x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        PII u = q.front();
        q.pop();
        for (ll i = 1; i <= 8; i++) {
            ll ux = u.first + nxtX[i], uy = u.second + nxtY[i];
            if (ux < 1 || ux > n || uy < 1 || uy > m) {
                continue;
            }
            if (vis[ux][uy] != -1) {
                continue;
            }
            q.push({ux, uy});
            vis[ux][uy] = vis[u.first][u.second] + 1;
        }
    }
}

int main() {
    cin >> n >> m >> x >> y;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            vis[i][j] = -1;
        }
    }
    bfs();
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}