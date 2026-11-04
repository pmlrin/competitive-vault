#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
const int N = 2e5 + 10;
const int inf = 1e9;

struct Data {
    int lmax, rmax, ans;
};

int a[N];

Data dfs(int l, int r) {
    if (l == r) {
        return {max(0, a[l]), max(0, a[r]), max(0, a[l])};
    }
    int mid = (l + r) / 2;
    int lmax = 0, rmax = 0;
    for (int i = l, tmp = 0; i <= r; i++) {
        tmp += a[i];
        lmax = max(lmax, tmp);
    }
    for (int i = r, tmp = 0; i >= l; i--) {
        tmp += a[i];
        rmax = max(rmax, tmp);
    }
    Data lres = dfs(l, mid), rres = dfs(mid + 1, r);
    return {lmax, rmax, max({lres.ans, rres.ans, lres.rmax + rres.lmax})};
}

void solve() {
    int n, flag = 0, ans = -inf;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 0) {
            flag = 1;
        }
        ans = max(ans, a[i]);
    }
    if (flag)
        cout << dfs(1, n).ans << "\n";
    else
        cout << ans << "\n";
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