#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define PII pair<ll,ll>
const ll N = 0, inf = 1145141919;

struct Data {
    ll val, h, w;
};

vector<Data> neat(vector<Data> rec) {
    map<ll, Data> b;
    for (auto k: rec) {
        if (b.count(k.w) == 0) {
            b[k.w] = k;
        } else if (b[k.w].val > k.val)
            b[k.w] = k;
    }
    rec.clear();
    for (auto [key,val]: b)
        rec.push_back(val);
    return rec;
}

void solve() {
    ll n, m, revflag = 0;
    cin >> n >> m;
    ll a[min(n, m) + 10][max(n, m) + 10] = {};
    ll ans[min(n, m) + 10][max(n, m) + 10] = {};
    if (n <= m) {
        string tmp;
        for (ll i = 1; i <= n; i++) {
            cin >> tmp;
            for (ll j = 1; j <= m; j++)
                a[i][j] = tmp[j - 1] - '0';
        }
    } else {
        string tmp;
        for (ll i = 1; i <= n; i++) {
            cin >> tmp;
            for (ll j = 1; j <= m; j++)
                a[j][i] = tmp[j - 1] - '0';
        }
        swap(n, m);
        revflag = 1;
    }
    vector<Data> rec[n + 10][m + 10];
    for (ll i1 = 1; i1 < n; i1++) {
        for (ll i2 = i1 + 1; i2 <= n; i2++) {
            ll last = -1;
            for (ll j = 1; j <= m; j++) {
                if (a[i1][j] == 1 && a[i2][j] == 1) {
                    if (last != -1) {
                        ll h = i2 - i1 + 1, w = j - last + 1;
                        rec[i1][last].push_back({h * w, h, w});
                        if (rec[i1][last].size() >= 100)
                            rec[i1][last] = neat(rec[i1][last]);
                    }
                    last = j;
                }
            }
        }
    }
    ll f[n + 10][n + 10];
    for (ll j = 1; j <= m; j++) {
        for (ll l = 0; l <= n + 1; l++) {
            for (ll r = 0; r <= n + 1; r++) {
                f[l][r] = inf;
            }
        }
        for (ll i = 1; i <= n; i++) {
            for (auto k: rec[i][j]) {
                f[i][i + k.h - 1] = min(f[i][i + k.h - 1], k.val);
                if (k.w >= 2)
                    rec[i][j + 1].push_back({k.val, k.h, k.w - 1});
            }
            rec[i][j].clear();
        }
        //cout << endl;
        for (ll r = n; r >= 1; r--) {
            for (ll l = 1; l <= r; l++) {
                f[l][r] = min({f[l][r], f[l - 1][r], f[l][r + 1]});
            }
        }
        for (ll i = 1; i <= n; i++) {
            ans[i][j] = f[i][i];
            if (ans[i][j] == inf)
                ans[i][j] = 0;
        }
    }
    if (revflag)
        swap(n, m);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (revflag)
                cout << ans[j][i] << " ";
            else
                cout << ans[i][j] << " ";
        }
        cout << endl;
    }
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
r
5   /
4  /
3 /
2/
12345l
 */
