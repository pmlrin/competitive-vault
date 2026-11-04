#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n, k, flag = 0, cnt = 0;
    string s;
    cin >> n >> k >> s;
    ll ans[n + 10];
    for (ll i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            if (flag == 0) {
                ans[i] = 1;
                flag = 1;
                cnt++;
                continue;
            }
            ll addf = 1;
            for (ll j = i - 1; j >= max(1ll, i - k + 1); j--) {
                if (s[j - 1] == '1') {
                    addf = 0;
                    break;
                }
            }
            if (addf == 1) {
                ans[i] = 1;
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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
