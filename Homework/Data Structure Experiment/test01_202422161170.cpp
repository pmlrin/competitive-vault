#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

ll n, a[N], vis[N], ans[N];

void dfs(ll step) {
    if (step > n) {
        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << ",\n"[i == n];
        }
        return;
    }
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans[step] = a[i];
            dfs(step + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    cout << "Ver1\n";
    cout << "input\n";
    for (ll i = 1;; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            break;
        }
        n = i;
    }
    cout << "output\n";
    dfs(1);
    cout << "end\n";
    system("pause");
    return 0;
}