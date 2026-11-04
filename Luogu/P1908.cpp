#include<bits/stdc++.h>
using namespace std;

namespace _sort {
    const int N = 500000 + 10;
    int n, a[N], b[N];
    long long ans = 0;

    void Sort(int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) / 2;
        int p1 = l, p2 = mid + 1, pos = l;
        Sort(l, mid);
        Sort(mid + 1, r);
        while (p1 <= mid && p2 <= r) {
            if (a[p1] <= a[p2])
                b[pos++] = a[p1++];
            else
                b[pos++] = a[p2++], ans += mid - p1 + 1;
        }
        while (p1 <= mid)
            b[pos++] = a[p1++];
        while (p2 <= r)
            b[pos++] = a[p2++];
        for (int i = l; i <= r; i++)
            a[i] = b[i];
    }

    void yzmain() {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);
        Sort(1, n);
        printf("%lld\n", ans);
        return;
    }
}

namespace _tree {
    const int N = 500000 + 10;

    struct data {
        int val, pos, rnk;
    } a[N];

    int n, t[N], p = 0;
    long long ans = 0;
    int lb(int x) { return x & -x; }

    int query(int x) {
        int ret = 0;
        while (x >= 1)
            ret += t[x], x -= lb(x);
        return ret;
    }

    void update(int x, int y) {
        while (x <= n)
            t[x] += y, x += lb(x);
    }

    void yzmain() {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i].val), a[i].pos = i; //Begin of 离散化
        sort(a + 1, a + 1 + n, [](data a, data b)-> bool { return a.val < b.val; });
        for (int i = 1; i <= n; i++) {
            if (a[i].val != a[i - 1].val)
                p++; //保证 val 相同的数，rnk 也相同。
            a[i].rnk = p;
        }
        sort(a + 1, a + 1 + n, [](data a, data b)-> bool { return a.pos < b.pos; }); //End of 离散化
        for (int i = n; i >= 1; i--)
            ans += query(a[i].rnk - 1), update(a[i].rnk, 1);
        printf("%lld\n", ans);
        return;
    }
}

namespace _ActiveTree {
    typedef long long ll;
    const ll N = 35 * 500000 + 10, M = 1000000000;
    ll cnt = 0;

    struct SGT {
        struct node {
            int lson, rson, data;
        } t[N];

#define lson t[root].lson
#define rson t[root].rson
#define mid ((l+r)/2)

        ll update(ll root, ll l, ll r, ll pos, ll data) {
            if (root == 0)
                root = ++cnt;
            if (l == r && r == pos) {
                t[root].data += data;
                return root;
            }
            if (pos <= mid)
                lson = update(lson, l,mid, pos, data);
            else
                rson = update(rson,mid + 1, r, pos, data);
            t[root].data = t[lson].data + t[rson].data;
            return root;
        }

        ll query(ll root, ll l, ll r, ll x, ll y) {
            ll ret = 0;
            if (root == 0)
                return 0;
            if (x <= l && r <= y)
                return t[root].data;
            if (x <= mid)
                ret += query(lson, l,mid, x, y);
            if (y >= mid + 1)
                ret += query(rson,mid + 1, r, x, y);
            return ret;
        }
    } Tree;

    ll n, a, ans = 0, root;

    void yzmain() {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a);
            ans += Tree.query(root, 1, M, a + 1, M);
            root = Tree.update(root, 1, M, a, 1);
        }
        printf("%lld\n", ans);
        return;
    }
}

int main() {
    _ActiveTree::yzmain();
    return 0;
}
