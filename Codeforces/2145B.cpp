#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 50;

ll n, k;
char ans[N];
string s;

void solve() {
    cin >> n >> k >> s;
    ll l = 0, r = n + 1, opt2 = 0;
    for (ll i = 0; i <= k - 1; i++) {
        if (s[i] == '0')
            l++;
        else if (s[i] == '1')
            r--;
        else
            opt2++;
    }
    for (ll i = 1; i <= n; i++)
        ans[i] = 0;
    for (ll i = 1; i <= l; i++)
        ans[i] = '-';
    for (ll i = r; i <= n; i++)
        ans[i] = '-';
    for (ll i = min(l + 1, n); i <= l + opt2; i++) {
        if (ans[i] != '-')
            ans[i] = '?';
    }
    for (ll i = max(r - opt2, 1ll); i <= r - 1; i++) {
        if (ans[i] != '-')
            ans[i] = '?';
    }
    for (ll i = 1; i <= n; i++)
        if (ans[i] != '-' && ans[i] != '?')
            ans[i] = '+';
    ll flag = 0;
    for (ll i = 1; i <= n; i++) {
        if (ans[i] == '?')
            flag++;
    }
    if (flag <= opt2) {
        for (ll i = 1; i <= n; i++) {
            if (ans[i] == '?')
                ans[i] = '-';
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i];
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
