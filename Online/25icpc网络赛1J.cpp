#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 50 + 10, mod = 998244353, M = 100000 + 50;
const ll inf = 1145141919810;

PII pos[N];
ll n, m, k, a[N], ans1, ans2, fac[M], ifac[M];

ll ksm(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b % 2)
            ret = ret * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ret;
}

ll inv(ll a) {
    return ksm(a, mod - 2);
}

ll C(ll n, ll m) {
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

ll dis(ll d) {
    if ((m - d) % 2)
        return 0;
    if (m < d)
        return 0;
    return C(m, (m - d) / 2);
}

ll find(ll x[], ll L, ll R) {
    ll mul = 1;
    for (ll i = 1; i <= n; i++) {
        ll sum = 0;
        for (ll j = L; j <= R; j++) {
            sum = (sum + dis(abs(j - x[i]))) % mod;
        }
        if (i == 1)
            mul = sum;
        else
            mul = mul * sum % mod;
    }
    return mul;
}

ll calc(ll x[]) {
    ll ret = 0, L = inf, R = -inf;
    for (ll i = 1; i <= n; i++) {
        L = min(L, x[i]);
        R = max(R, x[i]);
    }
    for (ll i = L - m; i <= R + m; i++) {
        ret = ((ret + find(x, i, i + k) - find(x, i + 1, i + k)) % mod + mod) % mod;
    }
    return ret;
}

void solve() {
    cin >> n >> m >> k;
    for (ll i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        pos[i] = (PII){u + v, u - v};
    }
    for (ll i = 1; i <= n; i++)
        a[i] = pos[i].first;
    ans1 = calc(a);
    for (ll i = 1; i <= n; i++)
        a[i] = pos[i].second;
    ans2 = calc(a);
    cout << ans1 * ans2 % mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    fac[0] = 1;
    for (ll i = 1; i <= M - 10; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (ll i = 0; i <= M - 10; i++)
        ifac[i] = inv(fac[i]);
    while (T--) {
        solve();
    }
    return 0;
}
