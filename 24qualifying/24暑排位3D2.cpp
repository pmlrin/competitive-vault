#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)
const ll N = 200000 + 50, inf = 1145141919810;

ll n, a[N], ans[N];

struct Node {
    ll data, tag, pos;
};

struct SGT {
    Node t[N * 4];

    void pushup(ll root) {
        if (t[lson].data < t[rson].data) {
            t[root].data = t[lson].data;
            t[root].pos = t[lson].pos;
        } else {
            t[root].data = t[rson].data;
            t[root].pos = t[rson].pos;
        }
    }

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

    void update(ll root, ll l, ll r, ll x, ll y, ll data) {
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

    void build(ll root, ll l, ll r) {
        if (l == r) {
            t[root].data = a[l];
            t[root].pos = l;
            return;
        }
        build(lson, l,mid);
        build(rson,mid + 1, r);
        pushup(root);
    }
} Tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    Tree.build(1, 1, n);
    for (ll i = 1; i <= n; i++) {
        Node cur = Tree.t[1];
        assert(cur.data==0);
        ans[cur.pos] = i;
        Tree.update(1, 1, n, cur.pos, n, -i);
        Tree.update(1, 1, n, cur.pos, cur.pos, inf);
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}

/*
5
0 1 1 8 1
1 4 3 5 2

-1 0 0 7 0
-1 0 0 7 -2
-1 0 -3 4 -5
-1 -4 -7 0 -9


5
0 1 4 8 1
1 3 4 5 2

1<2
2<3
3<4
5<4


5
0 2 2 0 3
2 5 4 1 3


5
0 2 5 5 0
2 3 5 4 1

1<2
2<3
4<3
5<1
2<4

5
0 1 1 3 3
1 5 2 4 3

1 3 2 5 4

1<2
3<2
3<4
5<4


5
0 0 1 1 6
5 1 3 2 4

0 -1 0 0 5
0 -1 0 -2 3
0 -1 -3 -5 0


9
0 1 1 3 3 6 6 6 15
1 9 2 8 3 7 5 4 6
 */
