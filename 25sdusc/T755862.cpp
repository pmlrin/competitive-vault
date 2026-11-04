#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;

void solve1() {
    ll n, ans = 0;
    string s;
    cin >> n >> s;
    for (auto i : s) {
        if (i == 'L')
            ans--;
        else
            ans++;
    }
    cout << max({abs(ans), abs(ans - 2), abs(ans + 2)}) << endl;
}

void solve2() {
    ll n, ans = 0, f1 = 0, f2 = 0;
    string s;
    cin >> n >> s;
    for (auto i : s) {
        if (i == 'L') {
            ans--;
            f1 = 1;
        } else {
            ans++;
            f2 = 1;
        }
    }
    cout << max({abs(ans), abs(ans - 2) * f2, abs(ans + 2) * f1}) << endl;
}

void solve3() {
    ll n, ans = 0, len;
    string s;
    cin >> n >> s;
    len = s.size();
    for (ll i = 0; i <= n; i++) {
        ll tmp = 0;
        for (ll j = 1; j <= len; j++) {
            if (s[j - 1] == 'L') {
                if (i == j) {
                    tmp++;
                } else {
                    tmp--;
                }
            } else {
                if (i == j) {
                    tmp--;
                } else {
                    tmp++;
                }
            }
        }
        ans = max(ans, abs(tmp));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve3();
    }
    return 0;
}