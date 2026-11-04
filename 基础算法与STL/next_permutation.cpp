#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<string> v(3);
    v[0] = "S", v[1] = "D", v[2] = "U";
    do {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    cout << "---\n";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << "\n";
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