#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 200, inf = 1e17;
const ll nx[] = {0, -1, 1, 2, 2, 1, -1, -2, -2};
const ll ny[] = {0, 2, 2, 1, -1, -2, -2, -1, 1};

ll n, k, ans = 0, vis[N][N];
queue<PII> q;

void solve() {
    ll x, y;
    cin >> n >> k >> x >> y;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        ans++;
        if (vis[cx][cy] >= k + 1) {
            continue;
        }
        for (ll i = 1; i <= 8; i++) {
            ll tx = cx + nx[i], ty = cy + ny[i];
            if (tx < 1 || tx > n || ty < 1 || ty > n ||
                (vis[tx][ty] <= vis[cx][cy] + 1 && vis[tx][ty])) {
                continue;
            }
            vis[tx][ty] = vis[cx][cy] + 1;
            q.push({tx, ty});
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
