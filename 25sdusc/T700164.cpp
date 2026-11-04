#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    string s, ans = "lishucai";
    cin >> s;
    for (ll i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    if (s == ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
