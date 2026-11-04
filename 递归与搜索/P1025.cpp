#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, ans = 0, cnt = 0;

void dfs(ll n, ll k, ll pre) {
    cnt++;
    if (n == 0 && k == 0) {
        ans++;
        cout << cnt << endl;
        return;
    }
    if (n <= 0 && k >= 1) {
        return;
    }
    if (n >= 1 && k <= 0) {
        return;
    }
    for (ll i = pre; i <= n; i++) {
        if (n - i < k - 1) {
            continue;
        }
        dfs(n - i, k - 1, i);
    }
}

int main() {
    cin >> n >> k;
    dfs(n, k, 1);
    cout << ans << endl;
    return 0;
}