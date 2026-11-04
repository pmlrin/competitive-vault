#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 50;

ll n, k, f[N][N * N], ans[N];
vector<ll> p[N][N * N];

void solve() {
    cin >> n >> k;
    ll cur = n, pos = 0;
    if (f[n][n * (n - 1) / 2 - k] == 0) {
        cout << 0 << endl;
        return;
    }
    for (auto i: p[n][n * (n - 1) / 2 - k]) {
        for (ll j = 1; j <= i; j++) {
            ans[pos + j] = cur - i + j;
        }
        pos += i;
        cur -= i;
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

void init() {
    f[0][0] = 1;
    p[0][0].clear();
    for (ll i = 0; i <= 30; i++) {
        for (ll j = 0; j <= i * (i - 1) / 2; j++) {
            if (f[i][j] == 0)
                continue;
            for (ll k = 1; i + k <= 30; k++) {
                if (f[i + k][j + k * (k - 1) / 2])
                    continue;
                f[i + k][j + k * (k - 1) / 2] = 1;
                p[i + k][j + k * (k - 1) / 2] = p[i][j];
                p[i + k][j + k * (k - 1) / 2].push_back(k);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    init();
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
