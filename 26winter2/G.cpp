#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

ll n, t;
string s1, s2, s3;

char dif(char a, char b) {
    for (char i = 'a'; i <= 'z'; i++) {
        if (i != a && i != b) {
            return i;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> t >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    s3 = s1;
    vector<ll> eq;
    ll b[n + 10] = {};
    for (ll i = 1; i <= n; i++) {
        if (s1[i] == s2[i]) {
            eq.push_back(i);
            b[i] = 1;
        } else {
            s3[i] = dif(s1[i], s2[i]);
        }
    }
    ll curt = n - eq.size();
    if (curt == t) {
        for (ll i = 1; i <= n; i++) {
            cout << s3[i];
        }
        cout << endl;
        return;
    } else if (curt < t) {
        for (ll i = 0; i < eq.size(); i++) {
            curt++;
            s3[eq[i]] = dif(s1[eq[i]], s2[eq[i]]);
            if (curt == t) {
                for (ll i = 1; i <= n; i++) {
                    cout << s3[i];
                }
                cout << endl;
                return;
            }
        }
    } else {
        ll sta = 0;
        for (ll i = 1; i <= n; i++) {
            if (b[i]) {
                continue;
            }
            if (sta == 0) {
                s3[i] = s1[i];
            } else {
                s3[i] = s2[i];
                curt--;
            }
            if (curt == t) {
                for (ll i = 1; i <= n; i++) {
                    cout << s3[i];
                }
                cout << endl;
                return;
            }
            sta ^= 1;
        }
    }
    cout << -1 << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
/*
6 1
aaabcd
aaaefg
*/