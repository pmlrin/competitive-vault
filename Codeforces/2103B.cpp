#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 150 + 50;

ll n, b[N], ans, cur, cha;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        s = '0' + s;
        ans = cha = 0;
        cur = '0';
        for (ll i = 0; i <= n; i++) {
            ans += 1;
            if (s[i] != cur) {
                ans += 1;
                cha += 1;
                cur = s[i];
            }
        }
        if (cha >= 3)
            ans -= 2;
        else if (cha == 2) {
            ans -= 1;
        } else {
            ans -= 0;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}

/*
3
3
010
3
100
3
101

4
4
4

011
 */
