#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
#define lson (root * 2)
#define rson ((root * 2) + 1)
#define mid ((l + r) / 2)
const ll N = 150000 + 50, M = 1000000 + 50;

ll n, a[N], b[M], num[M], nxt[N], cur[M], ans, anl, anr, R[M];

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
        t[root].data = max(t[lson].data, t[rson].data);
        if (t[root].data == t[lson].data)
            t[root].pos = t[lson].pos;
        else
            t[root].pos = t[rson].pos;
    }

    void update(ll root, ll l, ll r, ll x, ll y, ll data) {
        if (x <= l && y >= r) {
            t[root].data += data;
            t[root].tag += data;
            return;
        }
        pushdown(root, l, r);
        if (x <= mid)
            update(lson, l, mid, x, y, data);
        if (y > mid)
            update(rson, mid + 1, r, x, y, data);
        pushup(root);
    }

    Node query(ll root, ll l, ll r, ll x, ll y) {
        if (x <= l && y >= r)
            return t[root];
        pushdown(root, l, r);
        Node ansl = {-1, -1, -1}, ansr = {-1, -1, -1};
        if (x <= mid)
            ansl = query(lson, l, mid, x, y);
        if (y > mid)
            ansr = query(rson, mid + 1, r, x, y);
        if (ansl.data > ansr.data)
            return ansl;
        return ansr;
    }

    void build(ll root, ll l, ll r) {
        if (l == r) {
            t[root].data = 0;
            t[root].pos = l;
            return;
        }
        t[root].data = 0;
        t[root].tag = 0;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(root);
    }
} Tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(num, 0, sizeof(num));
        memset(cur, 0, sizeof(cur));
        memset(nxt, 0, sizeof(nxt));
        memset(R, 0, sizeof(R));
        ans = 0;
        anl = 2;
        anr = 3;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            num[a[i]]++;
        }
        memset(b, 0, sizeof(b));
        for (ll i = n; i >= 1; i--) {
            b[a[i]]++;
            if (cur[a[i]])
                nxt[i] = cur[a[i]];
            cur[a[i]] = i;
            if (b[a[i]] == 1 && num[a[i]] >= 3)
                R[a[i]] = i;
        }
        Tree.build(1, 1, n);
        memset(b, 0, sizeof(b));
        for (ll i = 1; i <= n - 2; i++) {
            b[a[i]]++;
            if (num[a[i]] >= 3) {
                if (b[a[i]] == 1) {
                    Tree.update(1, 1, n, nxt[i] + 1, R[a[i]], 1);
                } else if (b[a[i]] >= 2 && b[a[i]] <= num[a[i]] - 1) {
                    Tree.update(1, 1, n, i + 1, nxt[i], -1);
                }
            }
            Node tmp = Tree.query(1, 1, n, i + 2, n);
            if (ans < tmp.data) {
                ans = tmp.data;
                anl = i + 1;
                anr = tmp.pos;
            }
        }
        cout << ans << endl << anl << " " << anr << endl;
    }
    return 0;
}

/*
1
9
1 1 1 1 1 1 1 1 1
 */
