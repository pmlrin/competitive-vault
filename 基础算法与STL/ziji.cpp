#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> v;
    for (int i = 1; i <= 3; i++) {
        v.push_back(i);
    }
    for (int i = 0; i <= (1 << 3) - 1; i++) {
        vector<int> out;
        for (int j = 0, t = i; t; j++, t /= 2) {
            if (t % 2) {
                out.push_back(v[j]);
            }
        }
        for (auto j : out) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}