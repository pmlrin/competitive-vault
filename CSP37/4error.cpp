#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10, inf = 1e17, mod = 998244353;

vector<ll> primes;
ll minp[N];
void eular() {
    minp[0] = 0;
    minp[1] = 1;
    for (ll i = 2; i <= N - 10; i++) {
        if (minp[i] == 0) {
            primes.push_back(i);
            minp[i] = i;
        }
        for (auto j : primes) {
            if (i * j > N - 10)
                break;
            minp[i * j] = j;
            if (i % j == 0) {
                break;
            }
        }
    }
}

ll n, a[N];

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

ll inv2 = ksm(2, mod - 2);

ll calc(ll l, ll r) {
    cout << "[" << l << " " << r << "]: ";
    auto sum_n = [](ll a, ll b) -> ll {
        return ((b * (b + 1) / 2) - (a - 1) * a / 2) % mod;
    };
    auto sum_sq = [](ll a, ll b) -> ll {
        return ((b * (b + 1) * (2 * b + 1) / 6) -
                ((a - 1) * a * (2 * a - 1) / 6)) %
               mod;
    };
    auto sum_cb = [&](ll a, ll b) -> ll {
        ll s1 = sum_n(1, b), s2 = sum_n(1, a - 1);
        return ((s1 * s1 % mod - s2 * s2 % mod) % mod + mod) % mod;
    };
    ll t1 = (r * r + r) % mod * sum_n(l, r) % mod;
    ll t2 = sum_cb(l, r) % mod;
    ll t3 = sum_sq(l, r) % mod;
    ll ret = ((t1 - t2 + t3) % mod + mod) % mod * inv2 % mod;
    cout << ret << endl;
    return ret;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

unordered_map<ll, ll> factor(ll x) {
    unordered_map<ll, ll> ret;
    while (minp[x] != x) {
        ret[minp[x]]++;
        x /= minp[x];
    }
    if (minp[x] >= 2) {
        ret[minp[x]]++;
    }
    return ret;
}

vector<ll> ins[N];
list<ll> stkpre;
unordered_map<ll, ll> mappre;
ll stk[N], top = 0;

void solve() {
    ll ans = 0, cur = 1;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    eular();
    for (ll i = n; i >= 0; i--) {
        unordered_map<ll, ll> now = factor(a[i]);
        vector<list<ll>::iterator> de;
        for (auto j = stkpre.begin(); j != stkpre.end(); ++j) {
            ll k = *j;
            ll dif = mappre[*j];
            if (now.count(k)) {
                dif -= now[k];
            }
            if (dif >= 1) {
                ll L = i + 1, R = ins[k].back();
                ll calcLR = calc(L, R);
                ll term = ((calcLR - stk[top]) % mod + mod) % mod;
                ans = (ans + term * cur % mod) % mod;
                cout << -k << ": " << term << " " << cur << " "
                     << term * cur % mod << endl;
                cur /= k;
                ins[k].pop_back();
                stk[--top] += calcLR;
                mappre[*j]--;
                de.push_back(j);
            }
        }
        for (auto j : de) {
            stkpre.erase(j);
        }
        for (auto [k, v] : now) {
            ll dif = v;
            if (mappre.count(k)) {
                dif -= mappre[k];
            }
            while (dif >= 1) {
                stk[++top] = 0;
                ins[k].push_back(i);
                stkpre.push_front(k);
                mappre[k]++;
                cur *= k;
                cout << "+" << k << ": " << i << endl;
                dif--;
            }
        }
    }
    ll term = ((calc(1, n) - stk[top]) % mod + mod) % mod;
    ans = (ans + term * cur % mod) % mod;
    cout << term << " " << cur << " " << term * cur % mod << endl;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cout << 2689361290 % mod << endl;
    while (T--) {
        solve();
    }
    return 0;
}
/*
3
5 15 3
123

20
114514 114514 114514 114514 114514 114514 114514 114514 114514
114514 114514 114514 114514 114514 114514 114514 114514 114514 114514 114514

20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

20
14 12 10 10 34 36 26 6 22 24 14 18 32 30 10 38 40 26 28 12

20
7 6 5 5 17 18 13 3 11 12 7 9 16 15 5 19 20 13 14 6
7 1 1 1 1  1  1  1 1  1  1 1 1  1  1 1  1  1  1  1
  6 1 1 1  1  1  1 1  1  1 1 1  1  1 1  1  1  1  1
    5 5 1  1  1  1 1  1  1 1 1  1  1 1  1  1  1  1
      5 1  1  1  1 1  1  1 1 1  1  1 1  1  1  1  1
        17 1  1  1 1  1  1 1 1  1  1 1  1  1  1  1
           18 1  1 1  1  1 1 1  1  1 1  1  1  1  1
              13 1 1  1  1 1 1  1  1 1  1  1  1  1
                 3 1  1  1 1 1  1  1 1  1  1  1  1
                   11 1  1 1 1  1  1 1  1  1  1  1
                      12 1 1 1  1  1 1  1  1  1  1
                         7 1 1  1  1 1  1  1  1  1
                           9 1  1  1 1  1  1  1  1
                             16 1  1 1  1  1  1  1
                                15 5 1  1  1  1  1
                                   5 1  1  1  1  1
                                     19 1  1  1  1
                                        20 1  1  1
                                           13 1  1
                                              14 2
                                                 6
*/