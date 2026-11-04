#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

ll n, m, r, p;
vector<ll> e[N];
ll a[N]; // 原树点权
ll b[N]; // 按 dfn 排列后的点权
ll fa[N], dep[N], sz[N], son[N];
ll top[N], dfn[N], rnk[N], timer = 0;

// 第一次 DFS：求父节点、深度、子树大小、重儿子
void dfs1(ll u, ll f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    sz[u] = 1;
    son[u] = 0;

    for (ll v : e[u]) {
        if (v == f)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}

// 第二次 DFS：分配 dfn，求 top
void dfs2(ll u, ll t) {
    top[u] = t;
    dfn[u] = ++timer;
    rnk[timer] = u;

    // 优先走重儿子
    if (son[u]) {
        dfs2(son[u], t);
    }

    // 再走轻儿子
    for (ll v : e[u]) {
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

// 线段树：区间加，区间求和
#define lson (root * 2)
#define rson ((root * 2) + 1)
#define mid ((l + r) / 2)

struct SGT {
    struct Node {
        ll data, tag;
    } t[N * 4];

    void pushdown(ll root, ll l, ll r) {
        ll tag = t[root].tag;
        if (t[root].tag == 0)
            return;
        t[lson].data += tag * (mid - l + 1);
        t[rson].data += tag * (r - mid);
        t[lson].tag += tag;
        t[rson].tag += tag;
        t[root].tag = 0;
        return;
    }

    void add(ll root, ll l, ll r, ll x, ll y, ll data) {
        if (x <= l && y >= r) {
            t[root].data += data * (r - l + 1);
            t[root].tag += data;
            return;
        }
        pushdown(root, l, r);
        if (x <= mid)
            add(lson, l, mid, x, y, data);
        if (y > mid)
            add(rson, mid + 1, r, x, y, data);
        t[root].data = t[lson].data + t[rson].data;
    }

    ll query(ll root, ll l, ll r, ll x, ll y) {
        if (x <= l && y >= r)
            return t[root].data;
        pushdown(root, l, r);
        ll ansl = 0, ansr = 0;
        if (x <= mid)
            ansl = query(lson, l, mid, x, y);
        if (y > mid)
            ansr = query(rson, mid + 1, r, x, y);
        return ansl + ansr;
    }

    void build(ll root, ll l, ll r, ll d[]) {
        if (l == r) {
            t[root].data = d[l];
            return;
        }
        build(lson, l, mid, d);
        build(rson, mid + 1, r, d);
        t[root].data = t[lson].data + t[rson].data;
        return;
    }
} Tree;

// 路径加
void path_add(ll u, ll v, ll k) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        Tree.add(1, 1, n, dfn[top[u]], dfn[u], k);
        u = fa[top[u]];
    }

    if (dep[u] > dep[v])
        swap(u, v);
    Tree.add(1, 1, n, dfn[u], dfn[v], k);
}

// 路径求和
ll path_sum(ll u, ll v) {
    ll res = 0;

    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        res += Tree.query(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }

    if (dep[u] > dep[v])
        swap(u, v);
    res += Tree.query(1, 1, n, dfn[u], dfn[v]);
    return res;
}

// 子树加
void subtree_add(ll u, ll k) {
    Tree.add(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, k);
}

// 子树求和
ll subtree_sum(ll u) { return Tree.query(1, 1, n, dfn[u], dfn[u] + sz[u] - 1); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> r >> p;

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, r);

    // 把原树点权放到按 dfn 排列的数组里
    for (ll i = 1; i <= n; i++) {
        b[dfn[i]] = a[i];
    }
    Tree.build(1, 1, n, b);

    while (m--) {
        ll op, u, v;
        ll k;
        cin >> op;

        if (op == 1) {
            // 路径加
            cin >> u >> v >> k;
            path_add(u, v, k);
        } else if (op == 2) {
            // 路径求和
            cin >> u >> v;
            cout << path_sum(u, v) % p << '\n';
        } else if (op == 3) {
            // 子树加
            cin >> u >> k;
            subtree_add(u, k);
        } else if (op == 4) {
            // 子树求和
            cin >> u;
            cout << subtree_sum(u) % p << '\n';
        }
    }

    return 0;
}