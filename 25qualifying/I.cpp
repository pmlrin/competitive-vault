#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll mx = 0, ans = 0;
    k--;
    for (int p = 0; p < m && k >= 0; p++) {
        vector<int> b(m, 0);
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (!(a[i] >> p & 1)) {
                c++;
                for (int j = 0; j < p; j++) {
                    if (a[i] >> j & 1)
                        b[j]++;
                }
            }
        }
        ll res = c * (1ll << p), tmp = 1ll << p;
        vector<PLL> co;
        for (int j = 0; j < p; j++) {
            co.emplace_back((PLL) {(c - b[j]) * (1ll << j) - b[j] * (1ll << j), j});
        }
        sort(co.begin(), co.end(), [&](const PLL &t1, const PLL &t2) -> bool {
            auto [v1, j1] = t1;
            auto [v2, j2] = t2;
            if (v1 == v2)
                return j1 < j2;
            return v1 > v2;
        });
        int d = 0;
        for (auto [v, j]: co) {
            if (v <= 0 || d >= k)
                break;
            res += v;
            tmp |= 1 << j;
            d++;
        }
        if (res > mx)
            ans = tmp, mx = res;
        else if (res == mx && ans > tmp)
            ans = tmp;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
