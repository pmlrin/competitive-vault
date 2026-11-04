#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

ll n, m, t[N];
ll st[N], ed[N], dfn[N], timer = 0;
ll col[N], cnt[N], ans[N], vis[N], Unit;
ll f[L + 5][N], dep[N];
vector<ll> e[N];

struct Query {
    ll l, r, id, col, extra;
    bool operator<(const Query &x) const {
        if (l / Unit != x.l / Unit)
            return l < x.l;
        if ((l / Unit) & 1)
            return r < x.r;
        return r > x.r;
    }
} q[N];

void dfs(ll root, ll dad) {
    dfn[++timer] = root;
    st[root] = timer;
    f[0][root] = dad;
    dep[root] = dep[dad] + 1;
    for (auto son : e[root]) {
        if (son == dad) {
            continue;
        }
        dfs(son, root);
    }
    dfn[++timer] = root;
    ed[root] = timer;
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

void update(ll pos) {
    if (vis[dfn[pos]] == 0) {
        cnt[col[pos]]++;
    } else {
        cnt[col[pos]]--;
    }
    vis[dfn[pos]] ^= 1;
}

void solve() {
    cin >> n >> m;
    Unit = sqrt(n);
    for (ll i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 1);
    for (ll i = 1; i <= L; i++) {
        for (ll j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    for (ll i = 1; i <= n * 2; i++) {
        col[i] = t[dfn[i]];
    }
    for (ll i = 1, l, r, lca; i <= m; i++) {
        cin >> l >> r >> q[i].col;
        if (st[l] > st[r]) {
            swap(l, r);
        }
        lca = LCA(l, r);
        if (lca == l) {
            q[i].l = st[l];
            q[i].r = st[r];
        } else {
            q[i].l = ed[l];
            q[i].r = st[r];
            q[i].extra = st[lca];
        }
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (ll i = 1, l = 1, r = 0; i <= m; i++) {
        while (l > q[i].l)
            update(--l);
        while (r < q[i].r)
            update(++r);
        while (l < q[i].l)
            update(l++);
        while (r > q[i].r)
            update(r--);
        if (q[i].extra) {
            update(q[i].extra);
        }
        /*cout << "[" << q[i].l << ", " << q[i].r << "] " << q[i].extra << " "
             << q[i].col << endl;*/
        ans[q[i].id] = (cnt[q[i].col] >= 1);
        if (q[i].extra) {
            update(q[i].extra);
        }
    }
    for (ll i = 1; i <= m; i++) {
        cout << ans[i];
    }
    cout << endl;
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