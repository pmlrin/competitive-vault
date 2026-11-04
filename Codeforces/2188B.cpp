#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0, inf = 1145141919810;

void solve() {
    ll n, cnt = 0;
    string s;
    cin >> n >> s;
    s = " " + s;
    if (n == 1) {
        cout << 1 << endl;
    } else if (n == 2) {
        cout << 1 << endl;
    } else if (n == 3) {
        if (s == " 000" || s == " 010")
            cout << 1 << endl;
        else if (s == " 101")
            cout << 2 << endl;
        else if (s == " 001" || s == " 100")
            cout << 2 << endl;
        else {
        }
    } else {
        if (s[1] == '0' && s[2] == '0' && s[3] == '1')
            s[1] = '1';
        if (s[1] == '0' && s[2] == '0' && s[3] == '0')
            s[2] = '1';
        ll pos1 = 1;
        while (1) {
            while (pos1 <= n && s[pos1] == '0')
                pos1++;
            if (pos1 > n)
                break;
            if (pos1 + 4 <= n) {
                if (s[pos1 + 1] == '0' && s[pos1 + 2] == '0' && s[pos1 + 3] == '0' && s[pos1 + 4] == '0') {
                    s[pos1 + 3] = '1';
                    pos1++;
                    continue;
                }
            }
            if (pos1 + 3 <= n) {
                if (s[pos1 + 1] == '0' && s[pos1 + 2] == '0' && s[pos1 + 3] == '0') {
                    s[pos1 + 2] = '1';
                    pos1++;
                    continue;
                }
            }
            pos1++;
        }
        if (s[n - 2] == '1' && s[n - 1] == '0' && s[n - 0] == '0')
            s[n - 0] = '1';
        if (s[n - 2] == '0' && s[n - 1] == '0' && s[n - 0] == '0')
            s[n - 1] = '1';
        for (ll i = 1; i <= n; i++) {
            if (s[i] == '1')
                cnt++;
        }
        //cout << s << endl;
        cout << cnt << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
1
5
00100
 */
