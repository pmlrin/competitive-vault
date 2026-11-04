#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    string s;
    cin >> s;
    ll len = s.size();
    for (ll i = 0; i <= len - 1; i++) {
        s[i] = tolower(s[i]);
    }
    if (s == "xuewuzhijingqiyouhaoran") {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
    return;
}

int main() {
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
