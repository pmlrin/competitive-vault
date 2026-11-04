#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)
const ll N = 5e5 + 10;

ll ac, dr, n, a[N], d[N], cnt[N], p[N], m;

struct Node {
    ll data, tag, pos;
};

struct SGT {
    Node t[N * 4];

    void pushdown(ll root, ll l, ll r) {
        ll tag = t[root].tag;
        if (t[root].tag == 0)
            return;
        t[lson].data += tag;
        t[rson].data += tag;
        t[lson].tag += tag;
        t[rson].tag += tag;
        t[root].tag = 0;
    }

    void pushup(ll root) {
        if (t[lson].data <= t[rson].data)
            t[root].pos = t[lson].pos;
        else
            t[root].pos = t[rson].pos;
        t[root].data = min(t[lson].data, t[rson].data);
    }

    void update(ll root, ll l, ll r, ll x, ll y, ll data) {
        if (x > y)
            return;
        if (x <= l && y >= r) {
            t[root].data += data;
            t[root].tag += data;
            return;
        }
        pushdown(root, l, r);
        if (x <= mid)
            update(lson, l,mid, x, y, data);
        if (y > mid)
            update(rson,mid + 1, r, x, y, data);
        pushup(root);
    }

    Node query(ll root, ll l, ll r) {
        //cout << l << " " << r << " " << t[root].data << endl;
        if (l == r)
            return t[root];
        pushdown(root, l, r);
        if (t[lson].data < 0)
            return query(lson, l,mid);
        if (t[rson].data < 0)
            return query(rson,mid + 1, r);
        return {n + 1, n + 1, n + 1};
    }

    void build(ll root, ll l, ll r, ll d[]) {
        if (l == r) {
            t[root].data = d[l];
            t[root].pos = l;
            return;
        }
        build(lson, l,mid, d);
        build(rson,mid + 1, r, d);
        pushup(root);
    }
} Tree;

ll calc(ll pa, ll pd) {
    return max(pa - ac, 0) + max(pd - dr, 0);
}

void solve() {
    cin >> ac >> dr >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        cin >> d[i];
    for (ll i = 1; i <= n; i++) {
        if (calc(a[i], d[i]) > N - 10)
            continue;
        cnt[calc(a[i], d[i])]++;
    }
    for (ll i = 1; i <= N - 10; i++) {
        cnt[i] += cnt[i - 1];
        p[i] = cnt[i - 1] - i;
        //if (i <= 100)
        //    cout << p[i] << " ";
    }
    Tree.build(1, 1, N - 10, p);
    cin >> m;
    for (ll i = 1, k, na, nd; i <= m; i++) {
        cin >> k >> na >> nd;
        Tree.update(1, 1, N - 10, calc(a[k], d[k]) + 1, N - 10, -1);
        //cout << calc(a[k], d[k]) + 1 << " ";
        //update(calc(a[k], d[k]), -1);
        a[k] = na, d[k] = nd;
        Tree.update(1, 1, N - 10, calc(a[k], d[k]) + 1, N - 10, 1);
        //cout << calc(a[k], d[k]) + 1 << " ";
        //update(calc(a[k], d[k]), 1);
        cout << Tree.query(1, 1, N - 10).pos - 1 << endl;
        //cout << find() << endl;
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
