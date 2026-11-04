#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e3 + 10, inf = 1e17;

vector<ll> e[N];
ll siz[N], n;
set<ll> ans;

void dfs(ll root, ll dad) {
    map<ll, ll> tmp;
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        dfs(son, root);
        siz[root] += siz[son];
        vector<ll> add;
        if (!tmp.empty()) {
            for (auto [k, v]: tmp) {
                if (tmp.count(k) >= 1) {
                    add.push_back(k + siz[son]);
                }
            }
            for (auto i: add) {
                tmp[i] = 1;
            }
        }
        tmp[siz[son]] = 1;
    }
    for (auto [k, v]: tmp) {
        if (k == siz[root] && root == 1) {
            break;
        }
        if (1 <= k && k <= siz[root]) {
            ans.insert(k);
            ans.insert(n - k - 1);
        }
    }
    siz[root] += 1;
}

void solve() {
    cin >> n;
    for (ll i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1);
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i << " " << n - i - 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6
 */
