#include <bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;
    typedef pair<ll, ll> PII;
    static const ll M = 2000000 + 10;
    ll len = 0, b[M] = {}, ans = 0, S = 1, nmax = 0;

public:
    long long maxProduct(vector<int> &nums) {
        len = nums.size();
        ans = 0;
        nmax = 0;
        S = 1;
        for (auto i: nums) {
            b[i] = i;
            nmax = max(nmax, (ll) i);
        }
        while (S <= nmax)
            S *= 2;
        S--;
        for (ll i = 1; i <= S; i++) {
            ll tmp = i;
            while (tmp) {
                ll cur = i ^ (tmp & -tmp);
                b[i] = max(b[i], b[cur]);
                tmp -= (tmp & -tmp);
            }
        }
        for (auto i: nums)
            ans = max(ans, i * b[i ^ S]);
        for (ll i = 0; i <= S; i++)
            b[i] = 0;
        return ans;
    }
};
