#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100 + 10;

ll n, vis[N];
char s[N], ans[N];

void dfs(ll step) {
    if (step >= n) {
        for (ll i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << endl;
        return;
    }
    for (ll i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans[step] = s[i];
            dfs(step + 1);
            vis[i] = 0;
            ans[step] = 0;
        }
    }
}

int main() {
    cin >> s;
    n = strlen(s);
    dfs(0);
    return 0;
}