#include <bits/stdc++.h>
using namespace std;
#define int long long


// map<string,int> m;

vector<string> m;

string s;

void solve() {
    int n;
    cin >> n;
    int f = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int flag = 0, mlen = m.size();
        for (int j = 0; j < mlen; j++) {
            if (m[j] == s) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;
        int slen = s.size();
        for (int j = 0; j < slen - 2; j++) {
            if (s[j] == 'b' && s[j + 1] == 'i' && s[j + 2] == 'e') {
                cout << s << endl;
                f = 1;
                m.push_back(s);
                break;
            }
        }
    }
    if (f == 0) {
        cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
        // cout << endl;
    }
    return 0;
}

/**
8
1
biebie
1
adwlknafdoaihfawofd
3
ap
ql
biebie
0
2
pbpbpbpbpbpbpbpb
bbbbbbbbbbie
0
3
abie
bbie
cbie
0
 */
