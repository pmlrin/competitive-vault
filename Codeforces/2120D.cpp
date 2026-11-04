#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 1000000 + 50, mod = 1000000000 + 7;

ll a, b, k, n, m;
ll mul[N];

ll qpow(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y % 2)
            ret = ret * x % mod;
        y /= 2;
        x = x * x % mod;
    }
    return ret % mod;
}

ll inv(ll x) {
    return qpow(x, mod - 2) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    mul[0] = 1;
    for (ll i = 1; i <= N - 5; i++) {
        mul[i] = mul[i - 1] * i % mod;
    }
    while (T--) {
        cin >> a >> b >> k;
        n = ((a - 1) * k + 1) % mod;
        m = ((n - a + 1) % mod + mod) % mod;
        if (m > n)
            m = 0;
        for (ll i = (m + 1) % mod; i <= n; i = (i + 1) % mod) {
            m = m * i % mod;
        }
        m = m * inv(mul[a]) % mod;
        m = m * (b - 1) % mod;
        m = m * k % mod;
        m = (m + 1) % mod;
        cout << n << " " << m << endl;
    }
    return 0;
}
