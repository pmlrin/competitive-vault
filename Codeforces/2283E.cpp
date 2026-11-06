#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e3 + 10, inf = 1e17, mod = 998244353;

ll f[N][N], S1[N], S2[N];

void solve() {
    ll n, tmp = -1, ans1 = 0, ans2 = 1;
    string s;
    vector<ll> C1(2), C2;
    cin >> n >> s;
    s = " " + s + s.back();
    for (ll i = 1; i <= n; i++) {
        if (s[i] != s[i + 1]) {
            if (tmp == -1) {
                tmp = 2;
            } else {
                tmp++;
            }
        } else {
            if (tmp != -1) {
                C2.push_back(tmp);
                tmp = -1;
            } else {
                C1[s[i] - '0']++;
            }
        }
    }
    for (auto i : C1) {
        if (i == 0) {
            continue;
        }
        ans1 = (ans1 + i) % mod;
        ans2 = (ans2 * S1[i]) % mod;
        // cout << ans2 << " ";
    }
    // cout << endl;
    for (auto i : C2) {
        ans1 = (ans1 + i * 2) % mod;
        ans2 = (ans2 * S2[i]) % mod;
        // cout << ans2 << " ";
    }
    // cout << endl;
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    f[0][0] = 1, S2[0] = 1;
    for (ll i = 1; i <= N - 10; i++) {
        S2[i] = (S2[i - 2] + S2[i - 3]) % mod;
        for (ll j = 1; j <= N - 10; j++) {
            f[i][j] = (f[i - 1][j - 1] + j * f[i - 1][j] % mod) % mod;
            S1[i] = (S1[i] + f[i][j]) % mod;
        }
    }
    while (T--) {
        solve();
    }
    return 0;
}
