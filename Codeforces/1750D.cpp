#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

const ll M = 1e5 + 10, mod = 998244353;
vector<ll> primes;
ll notprime[M], phi[M];

vector<ll> fact(ll x) {
    vector<ll> ret;
    for (auto p: primes) {
        if (p * p > x)
            break;
        if (x % p == 0) {
            ret.push_back(p);
            while (x % p == 0) {
                x /= p;
            }
        }
    }
    if (x != 1)
        ret.push_back(x);
    return ret;
}

void solve() {
    ll n, m, ans = 1;
    cin >> n >> m;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 2; i <= n; i++) {
        if (a[i - 1] % a[i] != 0) {
            cout << 0 << endl;
            return;
        }
    }
    for (ll i = 2; i <= n; i++) {
        vector<ll> fac = fact(a[i - 1] / a[i]);
        ll siz = fac.size(), cnt = m / a[i];
        for (ll j = 1; j <= (1ll << siz) - 1; j++) {
            ll tmp = j, f = 1, div = 1;
            for (ll k = 0; k <= siz - 1; k++) {
                if (tmp % 2) {
                    f *= -1;
                    div *= fac[k];
                }
                tmp /= 2;
            }
            cnt = ((cnt + f * (m / a[i] / div)) % mod + mod) % mod;
        }
        ans = ans * cnt % mod;
    }
    cout << ans << endl;
}

void init() {
    notprime[0] = notprime[1] = 1;
    for (ll i = 2; i <= M - 10; i++) {
        if (notprime[i] == 0) {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (auto j: primes) {
            if (i * j > M - 10)
                break;
            notprime[i * j] = 1;
            if (i % j != 0) {
                phi[i * j] = phi[i] * phi[j];
            }
            if (i % j == 0) {
                phi[i * j] = phi[i] * j;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    init();
    while (T--) {
        solve();
    }
    return 0;
}

/*
1
2 1000000000
1000000000 2
 */
