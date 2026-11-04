#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return;
    } else {
        ll ans = 0;
        vector<ll> sa, sb;
        sa.clear();
        sb.clear();
        while (a) {
            sa.push_back(a % 2);
            a /= 2;
        }
        while (b) {
            sb.push_back(b % 2);
            b /= 2;
        }
        if (sa.size() < sb.size()) {
            cout << -1 << endl;
            return;
        }
        while (sa.size() > sb.size())
            sb.push_back(0);
        ll len = sa.size();
        cout << 2 << endl;
        for (ll i = 0; i <= sa.size() - 1; i++) {
            if (sa[i] == 0) {
                ans += (1ll << i);
            }
        }
        cout << ans << " ";
        ans = 0;
        for (ll i = 0; i <= sa.size() - 1; i++) {
            if (sb[i] == 0) {
                ans += (1ll << i);
            }
        }
        cout << ans << endl;
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
10
01

01

11


0011
0101

0110


1101
0110

1011
0110


100000
011111

110000
011111

101111

100
110

101
110

101
111

 */
