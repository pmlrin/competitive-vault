#include<bits/stdc++.h>
using namespace std;

namespace _yz {
#define ll long long
    const ll N = 500005, inf = 2147483647;
    ll m, n, a[N];

    struct SGT {
        /* 区间包含情况
            --------------|----------|--------------
            右端点最大和     区间和     左端点最大和
            |  -----   | 最大子段和
        */
#define ll long long
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)

        struct Node {
            ll left, right, sum, maxn;
        } t[N << 3];

        void pushup(ll root) {
            Node L = t[lson], R = t[rson], ret;
            ret.left = max(L.left, L.sum + R.left);
            ret.right = max(R.right, R.sum + L.right);
            ret.sum = L.sum + R.sum;
            ret.maxn = max(L.maxn, max(R.maxn, L.right + R.left));
            t[root] = ret;
        }

        void update(ll root,ll l,ll r,ll x,ll d) {
            if (l == r) {
                t[root] = (Node){d, d, d, d};
                return;
            }
            if (x <= mid)
                update(lson, l,mid, x, d);
            if (x > mid)
                update(rson,mid + 1, r, x, d);
            pushup(root);
        }

        Node query(ll root,ll l,ll r,ll x,ll y) {
            Node ret;
            if (x <= l && y >= r)
                return t[root];
            if (y <= mid)
                return query(lson, l,mid, x, y);
            else if (x > mid)
                return query(rson,mid + 1, r, x, y);
            else {
                Node L = query(lson, l,mid, x, y);
                Node R = query(rson,mid + 1, r, x, y);
                ret.left = max(L.left, L.sum + R.left);
                ret.right = max(R.right, R.sum + L.right);
                ret.maxn = max(L.maxn, max(R.maxn, L.right + R.left));
                ret.sum = L.sum + R.sum;
            }
            return ret;
        }

        void build(ll root,ll l,ll r,ll d[]) {
            if (l == r) {
                t[root] = (Node){d[l], d[l], d[l], d[l]};
                return;
            }
            build(lson, l,mid, d);
            build(rson,mid + 1, r, d);
            pushup(root);
            return;
        }
    } Tree;

    void yzmain() {
        ll t1, t2, t3;
        scanf("%lld%lld", &n, &m);
        for (ll i = 1; i <= n; i++)
            scanf("%lld", a + i);
        Tree.build(1, 1, n, a);
        for (ll i = 1; i <= m; i++) {
            scanf("%lld%lld%lld", &t1, &t2, &t3);
            if (t1 == 2)
                Tree.update(1, 1, n, t2, t3);
            else {
                if (t2 > t3)
                    swap(t2, t3);
                printf("%lld\n", Tree.query(1, 1, n, t2, t3).maxn);
            }
        }
        return;
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    _yz::yzmain();
    return 0;
}