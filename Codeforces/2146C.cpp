#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10;

ll n, ans[N];
string s;

void solve() {
    ll flag = 0;
    cin >> n >> s;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0')
            flag++;
        else {
            if (flag == 1)
                break;
            flag = 0;
        }
    }
    if (flag == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (ll i = 1; i <= n; i++)
        ans[i] = i;
    s = '1' + s + '1';
    ll l = 0, r = 0;
    for (ll i = 1; i <= n; i++) {
        if (s[i] == '0' && s[i - 1] == '1')
            l = i;
        if (s[i] == '0' && s[i + 1] == '1')
            r = i;
        if (l && r) {
            for (ll j = l; j <= (l + r) / 2; j++)
                swap(ans[j], ans[r - j + l]);
            l = r = 0;
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
