#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, L = 20;

ll n, cnt = 0, root[N];
vector<ll> e[N];

struct SGT {
    struct node {
        int lson, rson, data, mx;
    } t[N * 60];

    void pushup(ll root, ll lson, ll rson) {
        if (t[lson].data < t[rson].data) {
            t[root].data = t[rson].data;
            t[root].mx = t[rson].mx;
        } else {
            t[root].data = t[lson].data;
            t[root].mx = t[lson].mx;
        }
        if (t[root].data == 0) {
            t[root].mx = 0;
        }
    }

    ll update(ll root, ll l, ll r, ll pos, ll data) {
        if (root == 0)
            root = ++cnt; // 开辟新节点
        if (l == r) {
            t[root].data += data;
            t[root].mx = l;
            return root;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            t[root].lson = update(t[root].lson, l, mid, pos, data);
        else
            t[root].rson = update(t[root].rson, mid + 1, r, pos, data);
        pushup(root, t[root].lson, t[root].rson);
        return root; // 返回地址
    }

    ll merge(ll ra, ll rb, ll l, ll r) {
        if (ra == 0) {
            return rb;
        }
        if (rb == 0) {
            return ra;
        }
        if (l == r) {
            t[ra].data += t[rb].data;
            if (t[ra].data == 0) {
                t[ra].mx = 0;
            } else {
                t[ra].mx = l;
            }
            return ra;
        }
        ll mid = (l + r) / 2;
        t[ra].lson = merge(t[ra].lson, t[rb].lson, l, mid);
        t[ra].rson = merge(t[ra].rson, t[rb].rson, mid + 1, r);
        pushup(ra, t[ra].lson, t[ra].rson);
        return ra;
    }

} Tree;

ll dep[N], f[L + 3][N], ans[N];

void dfs(ll root, ll dad) {
    for (auto son : e[root]) {
        if (dad == son)
            continue;
        dep[son] = dep[root] + 1;
        f[0][son] = root;
        dfs(son, root);
    }
}

void finit() {
    for (ll i = 1; i <= L; i++)
        for (ll j = 1; j <= n; j++)
            f[i][j] = f[i - 1][f[i - 1][j]];
}

ll LCA(ll x, ll y) {
    if (dep[x] < dep[y])
        swap(x, y);
    for (ll i = L; i >= 0; i--) {
        if (dep[f[i][x]] < dep[y])
            continue;
        x = f[i][x];
    }
    if (x == y)
        return x;
    for (ll i = L; i >= 0; i--) {
        if (f[i][x] == f[i][y])
            continue;
        x = f[i][x], y = f[i][y];
    }
    return f[0][x];
}

void calc(ll rt, ll dad) {
    for (auto son : e[rt]) {
        if (son == dad) {
            continue;
        }
        calc(son, rt);
        root[rt] = Tree.merge(root[rt], root[son], 1, N);
    }
    ans[rt] = Tree.t[root[rt]].mx;
}

void solve() {
    ll m;
    cin >> n >> m;
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    f[0][1] = 1;
    dfs(1, 0);
    finit();
    for (ll i = 1, u, v, w, lca, flca; i <= m; i++) {
        cin >> u >> v >> w;
        lca = LCA(u, v);
        flca = f[0][lca];
        root[u] = Tree.update(root[u], 1, N, w, 1);
        root[v] = Tree.update(root[v], 1, N, w, 1);
        root[lca] = Tree.update(root[lca], 1, N, w, -1);
        if (lca != 1) {
            root[f[0][lca]] = Tree.update(root[f[0][lca]], 1, N, w, -1);
        }
    }
    calc(1, 1);
    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << endl;
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