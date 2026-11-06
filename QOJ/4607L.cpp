#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define PII pair<int, int>
void solve() {
    int s1, s2, t1, t2;
    string s;
    cin >> s1 >> s2 >> t1 >> t2;
    cin >> s;
    int a[s.length() + 10] = {};
    // string cp = a;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            a[i + 1] = 1;
        } else if (s[i] == 'D') {
            a[i + 1] = -1;
        } else if (s[i] == 'L') {
            a[i + 1] = -2;
        } else {
            a[i + 1] = 2;
        }
    }
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i + 1]) {

        } else {
            b.push_back(a[i]);
        }
    }
    // 1
    if (s1 == t1 && s2 == t2) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    // 2
    if (s1 == t1 || s2 == t2) {
        // return;
    }
    // 3
    int dx = t1 - s1;
    int dy = t2 - s2;
    int tar1;
    int tar2;
    if (dx > 0) {
        tar1 = 2;
    } else {
        tar1 = -2;
    }
    if (dy > 0) {
        tar2 = 1;
    } else {
        tar2 = -1;
    }
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < b.size(); i++) {
        if (tar1 == b[i] && (i == b.size() || b[i + 1] != -tar1)) {
            if (pos1 == -1) {
                pos1 = i;
            }
        }
        if (tar2 == b[i] && (i == b.size() || b[i + 1] != -tar2)) {
            if (pos2 == -1) {
                pos2 = i;
            }
        }
    }
    if (pos1 == -1 || pos2 == -1) {
        cout << "NO" << endl;
        return;
    }
    vector<PII> ans;
    map<int, PII> nex;
    nex[1] = {0, 1};
    nex[-1] = {0, -1};
    nex[2] = {1, 0};
    nex[-2] = {-1, 0};
    if (pos1 > pos2) {
        swap(pos1, pos2);
    }
    //
    int x, y;
    int mx, my;
    if (nex[b[pos1]].first == 0) {
        x = s1;
        y = t2 + nex[b[pos1]].second;
        mx = s1;
        my = t2;
    } else {
        y = s2;
        x = t1 + nex[b[pos1]].first;
        mx = s2;
        my = t1;
    }
    ans.push_back({x, y});
    ans.push_back({t1 + nex[b[pos2]].first, t2 + nex[b[pos2]].second});
    //
    x = s1, y = s2;
    set<PII> vis;
    int dycfx = 0;
    for (int i = 0; i < b.size(); i++) {
        if (i == pos1) {
            x = mx, y = my;
            continue;
        }
        if (i == pos2) {
            x = t1, y = t2;
            continue;
        }
        if (i < pos1) {
            if (b[i] != b[pos1]) {
                int tty = y + nex[b[i]].second;
                int ttx = x + nex[b[i]].first;
                if (!vis.count({ttx, tty})) {
                    vis.insert({ttx, tty});
                    ans.push_back({ttx, tty});
                }
            }
        } else if (i < pos2) {
            if (b[i] == b[pos2]) {
            } else if (b[i] + b[pos2] == 0) {
                if (dycfx != 0)
                    continue;
                dycfx = 1;
                int tty = y + nex[b[i]].second;
                int ttx = x + nex[b[i]].first;
                if (!vis.count({ttx, tty})) {
                    vis.insert({ttx, tty});
                    ans.push_back({ttx, tty});
                }
            }
        } else {
                }
    }
}

int main() {
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
