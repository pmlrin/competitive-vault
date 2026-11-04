#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2200, inf = 1e17, mod = 998244353;

ll mul[N * 2];

ll pow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b % 2) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ret;
}

ll inv(ll x) {
    return pow(x, mod - 2);
}

ll isprime(ll x) {
    if (x == 1)
        return 0;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void init() {
    mul[0] = 1;
    for (ll i = 1; i <= N * 2 - 10; i++) {
        mul[i] = mul[i - 1] * i % mod;
    }
}

void solve() {
    ll n, m = 0, sum = 0;
    cin >> n;
    map<ll, ll> a;
    for (ll i = 1, t; i <= n * 2; i++) {
        cin >> t;
        a[t]++;
    }
    ll f[n + 10] = {}, g[n + 10] = {};
    PII b[n * 2 + 10];
    for (auto [k, v]: a) {
        b[++m] = (PII){isprime(k), v};
        //cout << isprime(k) << " " << v << endl;
    }

    if (b[1].first) {
        g[0] = g[1] = 1;
    } else {
        g[0] = 1;
    }
    sum = b[1].second;

    for (ll i = 2; i <= m; i++) {
        for (ll j = 0; j <= min(sum, n); j++) {
            f[j] = g[j] * inv(mul[sum - j]) % mod * mul[sum - j + b[i].second] % mod * inv(mul[b[i].second]) % mod;
        }
        if (b[i].first) {
            for (ll j = 1; j <= min(sum + 1, n); j++) {
                f[j] = (f[j] + g[j - 1] * inv(mul[sum - j + 1]) % mod * mul[sum - j + b[i].second] % mod * inv(
                                mul[b[i].second - 1]) % mod) % mod;
            }
        }
        sum += b[i].second;
        for (ll j = 0; j <= n; j++) {
            g[j] = f[j];
        }
    }
    cout << g[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    init();
    while (T--) {
        solve();
    }
    return 0;
}

/*
2 2 3 5 -
2 2 5 3 -
2 3 5 2 -
2 5 2 3
2 5 3 2 -
3 2 5 2 -
*/
