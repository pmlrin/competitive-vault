#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

ll n, kx, ky, dx, dy;

ll dfs(ll n, ll kx, ll ky, ll dx, ll dy) {
    if (kx == dx || ky == dy) {
        if (kx == dx && ky == dy)
            return 0;
        if (kx == dx && ky < dy) {
            return ky + dy - ky;
        }
        if (kx == dx && ky > dy) {
            return n - ky + ky - dy;
        }
        if (kx < dx && ky == dy) {
            return kx + dx - kx;
        }
        if (kx > dx && ky == dy) {
            return n - kx + kx - dx;
        }
    } else {
        if (kx > dx && ky > dy) {
            ll ans = max(n - dx, n - dy);
            if (kx - dx + 1 <= ky - dy)
                ans = max(ans, dfs(n, dx, ky, dx, dy + kx - dx));
            if (ky - dy + 1 <= kx - dx) {
                ans = max(ans, dfs(n, kx, dy, dx + ky - dy, dy));
            }
            return ans;
        } else {
            if (kx < dx) {
                dx = n - dx;
                kx = n - kx;
            }
            if (ky < dy) {
                dy = n - dy;
                ky = n - ky;
            }
            return dfs(n, kx, ky, dx, dy);
        }
    }
}

void solve() {
    cin >> n >> kx >> ky >> dx >> dy;
    cout << dfs(n, kx, ky, dx, dy) << endl;
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

/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

ll n, kx, ky, dx, dy;

ll dfs(ll n, ll kx, ll ky, ll dx, ll dy) {
    if (kx == dx || ky == dy) {
        if (kx == dx && ky == dy)
            return 0;
        if (kx == dx && ky < dy) {
            return ky + min(dy - ky, max(kx, n - kx));
        }
        if (kx == dx && ky > dy) {
            return n - ky + min(ky - dy, max(kx, n - kx));
        }
        if (kx < dx && ky == dy) {
            return kx + min(dx - kx, max(ky, n - ky));
        }
        if (kx > dx && ky == dy) {
            return n - kx + min(kx - dx, min(ky, n - ky));
        }
    } else if ((kx == 0 || kx == n) && (ky == 0 || ky == n)) {
        return max(abs(kx - dx), abs(ky - dy));
    } else {
        if (kx < dx && ky < dy) {
            return max(dx, dy);
        }
        if (kx > dx && ky < dy) {
            return max(n - dx, dy);
        }
        if (kx < dx && ky > dy) {
            return max(dx, n - dy);
        }
        if (kx > dx && ky > dy) {
            return max(n - dx, n - dy);
        }
    }
}

void solve() {
    cin >> n >> kx >> ky >> dx >> dy;
    cout << dfs(n, kx, ky, dx, dy) << endl;
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
}*/

/*
1
5 5 4 4 1
 */
