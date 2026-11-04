#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100 + 10;
const ll nxtX[] = {0, 0, 0, 1, -1};
const ll nxtY[] = {0, 1, -1, 0, 0};

ll n, m, vis[N][N];
string s[N];

void dfs(ll x, ll y) {
    vis[x][y] = 1;
    if (x == n && y == m) {
        return;
    }
    for (ll i = 1; i <= 4; i++) {
        ll ux = x + nxtX[i], uy = y + nxtY[i];
        if (ux < 1 || ux > n || uy < 1 || uy > m) {
            continue;
        }
        if (vis[ux][uy]) {
            continue;
        }
        if (s[ux][uy] == '#') {
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
    dfs(1, 1);
    if (vis[n][m]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
/*
3 5
.##.#
.##..
...#.
*/