#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, ans = 0;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    ll nxt1[n + 10];
    for (ll i = 1; i <= n / 2; i++) {
        swap(s[i], s[n - i + 1]);
    }
    ll cur = n + 1;
    for (ll i = n; i >= 1; i--) {
        if (s[i] == '1') {
            cur = i;
        }
        nxt1[i] = cur - i;
    }
    /*cout << s << endl;
    for (ll i = 1; i <= n; i++) {
        cout << nxt1[i] << " ";
    }*/
    // cout << endl;
    for (ll i = 1; i <= n; i++) {
        ll num = 0;
        for (ll j = i, base = 0; j <= n; j++, base++) {
            if ((s[j] - '0') == 1 && base >= 19) {
                break;
            }
            num = num + ((ll) (s[j] - '0') << base);
            if (num > n) {
                break;
            }
            if (num == base + 1) {
                ans++;
                continue;
            }
            if (base >= 19) {
                if (base + 1 <= num && num <= base + nxt1[j]) {
                    ans++;
                }
                break;
            }
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
10000111
 */
