#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cout << i << " ";
    std::cout << '\n';

    for (int i = 2; i <= n; i *= 2) {
        std::cout << i << " " << i / 2 << '\n';
    }
    for (int i = 3; i <= n; i++) {
        if ((i & (i - 1)) == 0)
            continue;
        int flg = 0;
        for (int j = 1; j <= n; j *= 2) {
            if (!(i & j)) {
                std::cout << i << " " << j << '\n';
                flg = 1;
                break;
            }
        }
        if (!flg)
            std::cout << 1 << " " << i << '\n';
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}