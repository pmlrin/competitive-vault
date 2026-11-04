#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
    typedef pair<ll, ll> PII;
    static const ll N = 10000 + 10, mod = 1000000000 + 7;
    ll len = 0, ans[N * 7], maxn = 0, cnt = 0, t[N * 7];
    vector<ll> gnum[N * 7];

    ll lb(ll x) { return x & -x; }

    void add(ll x, ll k) {
        for (ll i = x; i <= maxn; i += lb(i))
            t[i] = (t[i] + k) % mod;
    }

    ll query(ll x) {
        ll ret = 0;
        for (ll i = x; i > 0; i -= lb(i))
            ret = (ret + t[i]) % mod;
        return ret;
    }

public:
    long long totalBeauty(vector<int> &nums) {
        len = nums.size();
        maxn = 0;
        cnt = 0;
        for (auto i: nums) {
            maxn = max(maxn, (ll) i);
            for (ll j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    gnum[j].push_back(i / j);
                    if (j != i / j)
                        gnum[i / j].push_back(j);
                }
            }
        }
        for (ll i = 1; i <= maxn; i++) {
            ans[i] = 0;
        }
        for (ll i = maxn; i >= 1; i--) {
            for (ll j = 1; j <= maxn / i; j++)
                t[j] = 0;
            for (auto j: gnum[i]) {
                ans[i] += query(j - 1) + 1;
                add(j, query(j - 1) + 1);
            }
            for (ll j = i * 2; j <= maxn; j += i)
                ans[i] -= ans[j];
        }
        for (ll i = 1; i <= maxn; i++) {
            cnt += ans[i] * i % mod;
            cnt %= mod;
        }
        return cnt;
    }
};
