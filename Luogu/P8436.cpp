#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10;

ll n, m;
ll dfn[N], low[N], stk[N], num = 0, top = 0, scc = 0, bel[N];
vector<PII> e[N];
vector<ll> ans[N];

void tarjan(ll u, ll last) {
    dfn[u] = low[u] = (++num);
    stk[++top] = u;
    for (auto [v, id] : e[u]) {
        if (id == (last ^ 1))
            continue;
        if (!dfn[v])
            tarjan(v, id), low[u] = min(low[u], low[v]);
        else
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        scc++;
        do {
            ll tmp = stk[top];
            bel[tmp] = scc;
            ans[scc].push_back(tmp);
        } while (u != stk[top--]);
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back({v, i * 2});
        e[v].push_back({u, i * 2 + 1});
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