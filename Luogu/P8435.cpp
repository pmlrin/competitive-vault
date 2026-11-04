#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10;

ll n, m;
ll dfn[N], low[N], stk[N], num = 0, top = 0, scc = 0, bel[N];
vector<ll> e[N], ans[N];

void tarjan(ll u, ll fa) {
    ll sons = 0;
    dfn[u] = low[u] = (++num);
    stk[++top] = u;
    for (auto v : e[u]) {
        if (!dfn[v]) {
            sons++;
            tarjan(v, u), low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                scc++;
                while (stk[top + 1] != v) {
                    bel[stk[top]] = scc;
                    ans[scc].push_back(stk[top--]);
                }
                ans[scc].push_back(u);
            }
        } else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (fa == 0 && sons == 0) {
        ans[++scc].push_back(u); // 特判单点
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }
    cout << scc << endl;
    for (ll i = 1; i <= scc; i++) {
        cout << ans[i].size() << " ";
        for (auto j : ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}