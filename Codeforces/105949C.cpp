#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll M = 1e5 + 10, inf = 1e17;

ll N;
long double f[M];
vector<ll> e[M];

void init() {
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                e[i].push_back(j);
                if (j * j != i) {
                    e[i].push_back(i / j);
                }
            }
        }
        for (ll j = i * 2; j <= N; j += i) {
            e[i].push_back(j);
        }
    }
    for (ll i = 0; i <= N; i++) {
        f[i] = i;
    }
    for (ll k = 1; k <= 100; k++) {
        for (ll i = 1; i <= N; i++) {
            long double tmp = 0;
            for (auto j: e[i]) {
                tmp += f[j - 1];
            }
            f[i] = min(f[i - 1] + 1, tmp / e[i].size() + 1);
        }
    }
}

void solve() {
    ll x;
    cin >> x;
    cout << fixed << setprecision(6) << f[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> N >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}
/*
1000 2
114
514
*/
