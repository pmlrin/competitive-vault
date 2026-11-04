#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 3e5 + 100, inf = 1e17, mod = 998244353;

vector<ll> prime;
ll notPrime[N];

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

ll inv(ll x) { return pow(x, mod - 2); }

void init() {
    notPrime[1] = 1;
    for (ll i = 2; i <= N - 10; i++) {

        if (notPrime[i] == 0) {
            prime.push_back(i);
        }
        for (auto p: prime) {
            if (p * i >= N) {
                break;
            }
            notPrime[p * i] = 1;
            if (i % p == 0) {
                break;
            }
        }
    }
}

void solve() {
    ll n, m, p = 1, ans = 0, la = 1, cur = 0;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        ans = (m % mod * ans % mod + m % mod) % mod;
    }
    for (ll i = 1; i <= n; i++) {
        if (prime[cur] <= i) {
            p = p * prime[cur++];
            if (p > m) {
                break;
            }
        }
        ans = ((ans - (m / p) % mod * la % mod) % mod + mod) % mod;
        la = (m / p) % mod * la % mod;
    }
    cout << ans << endl;
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
