#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<ll,ll>
const ll N = 3e3 + 10;

void solve() {
    ll n, m;
    cin >> n >> m;
    PII ran[m + 10];
    vector<ll> stat[n + 10] = {};
    ll ncnt[n + 10] = {};
    ll ans[n + 10] = {};
    for (ll i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        ran[i].first = l;
        ran[i].second = r;
        for (ll j = l; j <= r; j++) {
            ncnt[j]++;
            stat[j].push_back(i);
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (ncnt[i] == m) {
            ans[i] = 0;
            for (ll j = 1; j <= i - 1; j++) {
                ans[j] = j;
            }
            for (ll j = i + 1; j <= n; j++) {
                ans[j] = j - 1;
            }
            for (ll j = 1; j <= n; j++) {
                cout << ans[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    for (ll i = 1; i <= n - 1; i++) {
        ll j = i + 1, flag1 = 0, flag2 = 0;
        map<ll, ll> b;
        for (auto k: stat[i])
            b[k]++;
        for (auto k: stat[j])
            b[k]--;
        for (auto [k,v]: b) {
            if (v == 1)
                flag1 = 1;
            if (v == -1)
                flag2 = 1;
        }
        if (flag1 + flag2 <= 1) {
            if (flag1 == 1) {
                ans[j] = 0;
                ans[i] = 1;
            } else {
                ans[i] = 0;
                ans[j] = 1;
            }
            for (ll k = 1; k <= i - 1; k++)
                ans[k] = k + 1;
            for (ll k = j + 1; k <= n; k++)
                ans[k] = k - 1;
            for (ll k = 1; k <= n; k++) {
                cout << ans[k] << " ";
            }
            cout << endl;
            return;
        }
    }
    ans[1] = 0;
    ans[n] = 1;
    for (ll k = 2; k <= n - 1; k++)
        ans[k] = k;
    for (ll k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout << endl;
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

 */
