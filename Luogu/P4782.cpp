#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 3e6 + 39;

ll n, m;
ll dfn[N], low[N], ins[N], stk[N], num = 0, top = 0, scc = 0, bel[N];
ll val[N];
vector<ll> e[N];

void tarjan(ll u) {
    dfn[u] = low[u] = (++num);
    ins[u] = 1, stk[++top] = u;
    for (auto v : e[u]) {
        if (!dfn[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        scc++;
        do {
            ll tmp = stk[top];
            bel[tmp] = scc;
            ins[tmp] = 0;
        } while (u != stk[top--]);
    }
}

// 节点：2*i 表示 x_i=true，2*i+1 表示 x_i=false
// 添加子句：(x_i == vi) OR (x_j == vj)
void add(ll i, ll vi, ll j, ll vj) {
    int u = 2 * i + (vi ? 0 : 1); // vi=true -> 2*i, false -> 2*i+1
    int v = 2 * j + (vj ? 0 : 1);

    // (u OR v) <=> (!u -> v) AND (!v -> u)
    e[u ^ 1].push_back(v);
    e[v ^ 1].push_back(u);
}

void solve() {
    ll ans = 1;
    cin >> n >> m;
    for (ll i = 1, x, a, y, b; i <= m; i++) {
        cin >> x >> a >> y >> b;
        add(x, a, y, b);
    }
    for (ll i = 2; i <= 2 * n + 1; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (bel[2 * i] == bel[2 * i + 1]) {
            ans = 0;
            break;
        }
        // 本 Tarjan 实现中：bel 编号越小，SCC 在缩点 DAG 中越靠后
        // 选择拓扑序靠后的文字为真，所以真节点编号小则 x_i 为真
        val[i] = (bel[2 * i] < bel[2 * i + 1]);
    }
    if (ans == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << "POSSIBLE\n";
        for (ll i = 1; i <= n; i++) {
            cout << val[i] << " ";
        }
        cout << '\n';
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