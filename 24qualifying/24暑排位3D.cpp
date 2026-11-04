#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)
const ll N = 200000 + 50;

ll n, a[N], ans[N];
PII f[N];

struct Link {
    struct node {
        ll l, r, pre, nxt;
    } t[N * 4];

    ll num, front, back;

    ll push(ll l, ll r, ll p, ll n) {
        t[++num] = (node){l, r, p, n};
        t[n].pre = num;
        t[p].nxt = num;
        return num;
    }

    void del(ll pos) {
        ll npre = t[pos].pre;
        ll nnxt = t[pos].nxt;
        t[npre].nxt = nnxt;
        t[nnxt].pre = npre;
    }

    void init() {
        num = 0, front = 1, back = 2;
        t[++num] = (node){0, 0, front, back};
        t[++num] = (node){0, 0, front, back};
    }
} llist;

struct SGT {
    struct node {
        ll data;
    } t[N * 4];

    void pushup(ll root) {
        t[root].data = t[lson].data + t[rson].data;
    }

    void update(ll root, ll l, ll r, ll x, ll data) {
        if (x == l && x == r) {
            t[root].data += data;
            return;
        }
        if (x <= mid)
            update(lson, l,mid, x, data);
        if (x > mid)
            update(rson,mid + 1, r, x, data);
        pushup(root);
    }

    ll query(ll root, ll l, ll r, ll x, ll y) {
        if (x > y)
            return -1;
        if (x <= l && y >= r)
            return t[root].data;
        ll ans = 0;
        if (x <= mid)
            ans += query(lson, l,mid, x, y);
        if (y > mid)
            ans += query(rson,mid + 1, r, x, y);
        return ans;
    }

    void build(ll root, ll l, ll r) {
        if (l == r) {
            t[root].data = 0;
            return;
        }
        build(lson, l,mid);
        build(rson,mid + 1, r);
        pushup(root);
    }
} Tree;

bool cmp(PII x,PII y) {
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}

PII find(ll x, ll &pos) {
    ll l = 1, r = n;
    PII ans = {-1, -1};
    while (l <= r) {
        ll m = (l + r) / 2;
        if (f[m].first < x)
            l = m + 1;
        else if (f[m].first > x)
            r = m - 1;
        else if (f[m].second == -1)
            r = m - 1;
        else {
            ans = f[m];
            pos = m;
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = (PII){a[i], i};
    }
    Tree.build(1, 1, n);
    llist.init();
    llist.push(1, n, llist.front, llist.back);
    sort(f + 1, f + 1 + n, cmp);
    for (ll i = 1; i <= n; i++) {
        for (ll j = llist.back;;) {
            ll pos, sch = Tree.query(1, 1, n, 1, llist.t[j].r);
            PII cur = find(sch, pos);
            //cout << "sch = " << sch << "  order = " << cur.second << "  num = " << cur.first << "  find = " << sch <<
            if (cur.second != -1) {
                ll L = llist.t[j].l, R = llist.t[j].r, M = cur.second;
                ans[M] = i;
                //cout << i << endl;
                Tree.update(1, 1, n, M, i);
                f[pos].second = -1;
                if (M == R) {
                    llist.t[j].r -= 1;
                }
                if (M == L) {
                    llist.t[j].l += 1;
                }
                if (R < L) {
                    j = llist.t[j].pre;
                    llist.del(j);
                    break;
                }
                if (L < M && M < R) {
                    ll LP = llist.t[j].pre, LN = llist.t[j].nxt;
                    llist.del(j);
                    ll NP = llist.push(L, M - 1, LP, LN);
                    ll NN = llist.push(M + 1, R, NP, LN);
                    j = NP;
                    break;
                }
                break;
            }
            j = llist.t[j].pre;
        }
        //system("pause");
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
