#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x0, y0, R;
    cin >> x0 >> y0 >> R;
    cout << x0 << " " << y0 + R << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}