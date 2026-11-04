#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n, kmax;
    cin >> n >> kmax;
    string s[kmax + 10];
    cin >> s[0] >> s[kmax + 1];
    for (ll i = 0; i <= kmax; i++) {
        if (s[i] == s[kmax + 1]) {
            cout << i << endl;
            for (ll j = 1; j <= i; j++) {
                cout << s[j] << endl;
            }
            return;
        }
        if (i >= kmax) {
            cout << -1 << endl;
            return;
        }
        //cout << s[i] << endl;
        ll p[n + 10] = {}, cur = n - 1;
        for (ll j = n - 1; j >= 0; j--) {
            while (cur >= 1 && (s[i][cur] != s[kmax + 1][j] || cur > j)) {
                cur--;
            }
            p[j] = cur;
            if (j >= 1 && cur >= 1 && s[i][cur - 1] == s[kmax + 1][j - 1]) {
                cur--;
            }
        }
        for (ll j = 0; j <= n - 1; j++) {
            if (p[j] == j)
                s[i + 1].push_back(s[i][j]);
            else
                s[i + 1].push_back(s[i][j - 1]);
        }
    }
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
2
10 3
vzvylxxmsy
vvvvvllxxx
8 10
abcdaaaa
aaaaabcd
*/
