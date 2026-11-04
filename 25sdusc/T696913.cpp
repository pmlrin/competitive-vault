#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 10], b[n + 10], d[n + 10], f[n + 10];
    for (ll i = 0; i < n; i++) {
        f[i] = i;
    }
    auto find = [&](ll x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    };
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        f[find(i)] = find((i + a[i]) % n);
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (ll i = 0; i < n; i++) {
        d[i] = b[(i - 1 + n) % n] - b[i];
    }
    map<ll, ll> jud;
    for (ll i = 0; i < n; i++) {
        jud[find(i)] += d[i];
    }
    for (auto [k, v] : jud) {
        if (v) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
8
2
2 2
7 8
2
1 2
4 4
7
4 3 7 1 2 6 1
3 -10 -9 -10 -14 -18 -16
1
1
599220866
5
1 1 1 1 1
1 0 -1 -2 -3
3
3 3 3
0 0 0
3
1 2 3
1 2 1
3
1 2 3
1 2 2
*/