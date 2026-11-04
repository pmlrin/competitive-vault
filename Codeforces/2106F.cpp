#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, a[N];
string s;

ll top(ll cur, ll absi) {
    return absi * (cur - 1) - (absi - 1) * absi / 2;
}

ll bot(ll cur, ll absi) {
    return absi * n - top(cur, absi) - absi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll m = 0, cur = 0, ans = 1;
        cin >> n >> s;
        if (n == 1 && s == "0") {
            cout << 0 << endl;
            continue;
        }
        s = '$' + s + '$';
        for (ll i = 1; i <= n + 1; i++) {
            if (s[i] != s[i - 1]) {
                if (i != 1) {
                    if (s[i - 1] == '1')
                        cur = -cur;
                    a[++m] = cur;
                }
                cur = 1;
            } else {
                cur++;
            }
        }
        cur = 0;
        for (ll i = 1; i <= m; i++) {
            ll absi = abs(a[i]), t, b;
            cur += absi;
            t = top(cur, absi);
            b = bot(cur, absi);
            //cout << t << " " << b << endl;
            if (a[i] > 0) {
                ans = max(ans, t);
                ans = max(ans, b);
                if (i - 1 >= 1) {
                    ans = max(ans, t + 1);
                    if (a[i - 1] == -1 && i - 2 >= 1) {
                        ans = max(ans, t + 1 + bot(cur - a[i] - 1, a[i - 2]));
                        //cout << bot(cur - 1 - a[i - 2], a[i - 2]) << endl;
                    }
                }
                if (i + 1 <= m) {
                    ans = max(ans, b + 1);
                    if (a[i + 1] == -1 && i + 2 <= m) {
                        ans = max(ans, b + 1 + top(cur + 1 + a[i + 2], a[i + 2]));
                        //cout << top(cur + 1 + a[i + 2], a[i + 2]) << endl;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1
4
0010

0011001
1111001
1001001
1010001
1011101
1011011
1011000

11010
00010
01110
01000
01011
 */
