#include<bits/stdc++.h>
using namespace std;

namespace _yz {
    typedef long long ll;
    const ll N = 1000000 + 10;
    ll n, m, p, a[N];

    struct SGT {
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)

        struct node {
            ll d, atag, mtag;
        } t[N * 4];

        void pushup(ll root) {
            t[root].d = (t[lson].d + t[rson].d) % p;
        }

        void pushdown(ll root, ll l, ll r) {
            //规定：a[i]=mtag*a+atag
            ll mtag = t[root].mtag % p;
            ll atag = t[root].atag % p;
            t[lson].mtag = t[lson].mtag * mtag % p;
            t[rson].mtag = t[rson].mtag * mtag % p;
            t[lson].d = t[lson].d * mtag % p;
            t[rson].d = t[rson].d * mtag % p;
            t[lson].atag = (t[lson].atag * mtag + atag) % p;
            t[rson].atag = (t[rson].atag * mtag + atag) % p;
            t[lson].d = (t[lson].d + atag * (mid - l + 1)) % p;
            t[rson].d = (t[rson].d + atag * (r - mid)) % p;
            t[root].atag = 0;
            t[root].mtag = 1;
        }

        void build(ll root, ll l, ll r) {
            t[root].mtag = 1;
            t[root].atag = 0;
            if (l == r) {
                t[root].d = a[l] % p;
                return;
            }
            build(lson, l,mid);
            build(rson,mid + 1, r);
            pushup(root);
        }

        ll query(ll root, ll l, ll r, ll x, ll y) {
            if (x <= l && r <= y)
                return t[root].d % p;
            ll al = 0, ar = 0;
            pushdown(root, l, r);
            if (x <= mid)
                al = query(lson, l,mid, x, y);
            if (y > mid)
                ar = query(rson,mid + 1, r, x, y);
            return (al + ar) % p;
        }

        void aupdate(ll root, ll l, ll r, ll x, ll y, ll d) {
            if (x <= l && r <= y) {
                t[root].d = (t[root].d + d * (r - l + 1)) % p;
                t[root].atag = (t[root].atag + d) % p;
                return;
            }
            pushdown(root, l, r);
            if (x <= mid)
                aupdate(lson, l,mid, x, y, d);
            if (y > mid)
                aupdate(rson,mid + 1, r, x, y, d);
            pushup(root);
        }

        void mupdate(ll root, ll l, ll r, ll x, ll y, ll d) {
            if (x <= l && r <= y) {
                t[root].d = t[root].d * d % p;
                t[root].atag = t[root].atag * d % p;
                t[root].mtag = t[root].mtag * d % p;
                return;
            }
            pushdown(root, l, r);
            if (x <= mid)
                mupdate(lson, l,mid, x, y, d);
            if (y > mid)
                mupdate(rson,mid + 1, r, x, y, d);
            pushup(root);
        }
    } tree;

    void main() {
        ll type, l, r, d;
        scanf("%lld%lld%lld", &n, &m, &p);
        for (ll i = 1; i <= n; i++)
            scanf("%lld", a + i);
        tree.build(1, 1, n);
        for (ll i = 1; i <= m; i++) {
            scanf("%lld%lld%lld", &type, &l, &r);
            if (type == 1) {
                scanf("%lld", &d);
                tree.mupdate(1, 1, n, l, r, d);
            } else if (type == 2) {
                scanf("%lld", &d);
                tree.aupdate(1, 1, n, l, r, d);
            } else
                printf("%lld\n", tree.query(1, 1, n, l, r));
            /*printf("seq: ");
            for(ll j=1;j<=n;j++) printf("%lld ",tree.query(1,1,n,j,j));
            printf("\n");*/
        }
        return;
    }
}

int main() {
    _yz::main();
    return 0;
}
