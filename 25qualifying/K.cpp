#include <bits/stdc++.h>
using namespace std;
#define int long long

int r, c, k;
string s1, s2;

void solve() {
    int ans = 1;
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++) {
        int f1 = 0, f2 = 0;
        cin >> s1 >> s2;
        for (int j = 1; j <= c; j++) {
            if (s1[j - 1] == '-')
                f1 = 1;
        }
        for (int j = 1; j <= k; j++) {
            if (s2[j - 1] == '*')
                f2 = 1;
        }
        if (f1 == 1 && f2 == 1)
            ans = 0;
    }
    if (ans == 1)
        cout << "Y" << endl;
    else
        cout << "N" << endl;
}

signed main() {
    int t;
    t = 1;
    while (t--) {
        solve();
        cout << endl;
    }
}
