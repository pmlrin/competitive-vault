#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, tar = 0, ans1 = 0, ans2 = 0;
    cin >> n;
    ll a[n + 10];
    unordered_map<ll, ll> num;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            num[2]++;
            continue;
        }
        ll tmp = a[i];
        for (ll j = 1; tmp > 1; j++) {
            num[tmp]++;
            if (tmp % 2 == 1) {
                tmp += 1;
            } else {
                tmp /= 2;
            }
        }
    }
    num[1] = n;
    for (auto [k, v]: num) {
        if (v == n) {
            tar = max(tar, k);
        }
    }
    if (num[tar - 1] != n) {
        ans1 = inf;
    }
    // cout << " " << tar << endl;
    for (ll i = 1; i <= n; i++) {
        if (a[i] == 1 && tar == 2) {
            ans2++;
            continue;
        }
        ll tmp = a[i];
        for (ll j = 1; tmp > 1; j++) {
            // cout << tmp << " ";
            if (tmp % 2 == 1) {
                if (tmp + 1 == tar) {
                    ans2 += j;
                }
                if (tmp + 1 == tar - 1) {
                    ans1 += j;
                }
                tmp += 1;
            } else {
                if (tmp / 2 == tar) {
                    ans2 += j;
                }
                if (tmp / 2 == tar - 1) {
                    ans1 += j;
                }
                tmp /= 2;
            }
        }
        // cout << endl;
    }
    cout << min(ans1, ans2) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
1
10
28 19 47 52 75 99 62 85 23 74
*/
