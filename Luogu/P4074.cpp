#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

ll n, m, q, v[N], w[N], c[N];
ll st[N], ed[N], dfn[N], timer = 0;
ll col[N], cnt[N], ans[N], vis[N], Unit, qcnt = 0, mcnt = 0, sum = 0;
ll f[L + 5][N], dep[N];
vector<ll> e[N];
PII mod[N];

struct Query {
    ll l, r, t, id, extra;
    bool operator<(const Query &x) const {
        if (l / Unit != x.l / Unit)
            return l < x.l;
        if (r / Unit != x.r / Unit) {
            if ((l / Unit) & 1)
                return r < x.r;
            return r > x.r;
        }
        if ((r / Unit) & 1)
            return t < x.t;
        return t > x.t;
    }
} quy[N];

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
        sum += v[col[pos]] * w[cnt[col[pos]]];
    } else {
        sum -= v[col[pos]] * w[cnt[col[pos]]];
        cnt[col[pos]]--;
    }
    vis[dfn[pos]] ^= 1;
}

void toggle(ll pos, ll l, ll r) {
    ll x = mod[pos].first, y = mod[pos].second;
    if (l <= st[x] && st[x] <= r) {
        update(st[x]);
    }
    if (l <= ed[x] && ed[x] <= r) {
        update(ed[x]);
    }
    swap(col[st[x]], mod[pos].second);
    mod[pos].second = y;
    swap(col[ed[x]], mod[pos].second);
    if (l <= st[x] && st[x] <= r) {
        update(st[x]);
    }
    if (l <= ed[x] && ed[x] <= r) {
        update(ed[x]);
    }
}

void solve() {
    cin >> n >> m >> q;
    Unit = max(1ll, (ll)pow(n, 2.0 / 3.0));
    for (ll i = 1; i <= m; i++) {
        cin >> v[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (ll i = 1, a, b; i <= n - 1; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1, 1);
    for (ll i = 1; i <= L; i++) {
        for (ll j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    for (ll i = 1; i <= n * 2; i++) {
        col[i] = c[dfn[i]];
    }
    for (ll i = 1, x, y, type, lca; i <= q; i++) {
        cin >> type >> x >> y;
        if (type == 0) {
            mod[++mcnt] = {x, y};
        } else {
            quy[++qcnt].t = mcnt;
            quy[qcnt].id = qcnt;
            if (st[x] > st[y]) {
                swap(x, y);
            }
            lca = LCA(x, y);
            if (lca == x) {
                quy[qcnt].l = st[x];
                quy[qcnt].r = st[y];
            } else {
                quy[qcnt].l = ed[x];
                quy[qcnt].r = st[y];
                quy[qcnt].extra = st[lca];
            }
        }
    }
    sort(quy + 1, quy + 1 + qcnt);
    for (ll i = 1, l = 1, r = 0, t = 0; i <= qcnt; i++) {
        while (l > quy[i].l)
            update(--l);
        while (r < quy[i].r)
            update(++r);
        while (l < quy[i].l)
            update(l++);
        while (r > quy[i].r)
            update(r--);
        while (t < quy[i].t)
            toggle(++t, l, r);
        while (t > quy[i].t)
            toggle(t--, l, r);
        if (quy[i].extra) {
            update(quy[i].extra);
        }
        ans[quy[i].id] = sum;
        if (quy[i].extra) {
            update(quy[i].extra);
        }
    }
    for (ll i = 1; i <= qcnt; i++) {
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
