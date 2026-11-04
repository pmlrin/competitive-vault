#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10, inf = 1e17;

ll cnt[N], cnti[N];

void solve() {
    ll n, ans = 0;
    cin >> n;
    vector<ll> a[n + 10];
    ll all = 0, allopt = 0;
    for (ll i = 1, len; i <= n; i++) {
        cin >> len;
        all += len;
        allopt += len * (n - 1);
        for (ll j = 1, t; j <= len; j++) {
            cin >> t;
            a[i].push_back(t);
            cnt[t]++;
        }
        sort(a[i].begin(), a[i].end());
    }
    for (ll i = 1; i <= n; i++) {
        ll check = 0, mex1 = 0, mex2 = 0;
        ll alli = a[i].size();
        for (auto j: a[i]) {
            if (j == check) {
                check++;
            }
        }
        mex2 = check;
        check = 0;
        for (auto j: a[i]) {
            if (mex2 == check)
                check++;
            if (j == check)
                check++;
            if (mex2 == check)
                check++;
            cnti[j]++;
            cnt[j]--;
        }
        mex1 = check;

        // cout << "mex1 = " << mex1 << " mex2 = " << mex2 << endl;

        for (auto j: a[i]) {
            if (cnti[j] >= 2 && j < mex2) {
                ans += mex2 * (n - 1);
            } else if (cnti[j] <= 1 && j < mex2) {
                ans += j * (n - 1);
            } else {
                ans += mex2 * (n - 1);
            }
        }

        ans += mex2 * (all - alli - cnt[mex2]);
        ans += mex1 * (cnt[mex2]);
        ans += mex2 * (allopt - (all - alli) - (n - 1) * alli);

        for (auto j: a[i]) {
            cnti[j]--;
            cnt[j]++;
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (auto j: a[i]) {
            cnt[j]--;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
1
2
6 0 0 1 2 2 3
3 0 2 3

43*/
