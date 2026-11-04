#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10, inf = 1e17, mod = 998244353;

ll n, a[N], b[N], st[30][N];
map<ll, ll> dif;

ll ksm(ll a, ll b) {
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

ll inv(ll x) { return ksm(x, mod - 2); }
ll inv2 = inv(2);

ll calc(ll l, ll r) { return (r + l) * (r - l + 1) / 2 * l % mod; }

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll query(ll l, ll r) {
    ll len = r - l + 1;
    ll x = st[b[len]][l];
    ll y = st[b[len]][r + 1 - (1 << b[len])];
    return gcd(x, y);
}

void solve() {
    ll ans = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        st[0][i] = a[i] * 2;
    }
    st[0][n + 1] = 1;
    for (ll i = 1; i <= 20; i++) {
        for (ll j = 1; j <= n + 1; j++) {
            st[i][j] = gcd(st[i - 1][j], st[i - 1][j + (1ll << (i - 1))]);
        }
    }
    for (ll i = 1; i <= 20; i++) {
        b[1ll << i] = 1;
    }
    for (ll i = 1; i <= n + 1; i++) {
        b[i] += b[i - 1];
    }
    for (ll i = n; i >= 1; i--) {
        dif[i] = 1;
        vector<ll> de;
        for (auto [k, v] : dif) {
            if (query(i, k) == query(i, k + 1)) {
                de.push_back(k);
            }
        }
        for (auto j : de) {
            dif.erase(j);
        }
        ll lstk = i - 1;
        for (auto [k, v] : dif) {
            ans =
                (ans + query(i, k) * (calc(i, k) - calc(i, lstk)) % mod) % mod;
            lstk = k;
            // cout << k << " ";
        }
        // cout << endl;
    }
    cout << ans * inv2 % mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
/*
10 2 6 6 8
10 2 2 2 2
   2 2 2 2
     6 6 2
       6 2
         8
*/