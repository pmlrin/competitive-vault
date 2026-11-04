#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10;

ll n, sgn[N];
vector<ll> e[N];
ll ocnt;
PII opt[N * 3];

ll dfs(ll root, ll dad) {
    if (root == n)
        return sgn[root] = 1;
    ll ret = 0;
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        ret = max(ret, dfs(son, root));
    }
    return sgn[root] = ret;
}

void dfs2(ll root, ll dad) {
    if (root == n)
        return;
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        if (sgn[son] == 1) {
            opt[++ocnt] = {1, 0};
            opt[++ocnt] = {2, root};
            dfs2(son, root);
        }
    }
}

void solve() {
    cin >> n;
    ocnt = 0;
    for (ll i = 1; i <= n; i++) {
        sgn[i] = 0;
        e[i].clear();
    }
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    sgn[1] = dfs(1, 1);
    for (ll i = 1; i <= n; i++) {
        if (sgn[i] == 0) {
            opt[++ocnt] = {2, i};
        }
    }
    dfs2(1, 1);
    cout << ocnt << endl;
    for (ll i = 1; i <= ocnt; i++) {
        if (opt[i].first == 1)
            cout << 1 << endl;
        else
            cout << 2 << " " << opt[i].second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
