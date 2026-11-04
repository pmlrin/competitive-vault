#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 4e5 + 10, inf = 1e17;

#define ll long long
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

    void update(ll root, ll l, ll r, ll x, ll y, ll data) {
        if (x <= l && y >= r) {
            t[root].data += data * (r - l + 1);
            t[root].tag += data;
            return;
        }
        pushdown(root, l, r);
        if (x <= mid)
            update(lson, l, mid, x, y, data);
        if (y > mid)
            update(rson, mid + 1, r, x, y, data);
        t[root].data = t[lson].data + t[rson].data;
    }

    ll query(ll root, ll l, ll r, ll x) {
        if (x == 0) {
            return 0;
        }
        if (x == l && x == r) {
            return t[root].data;
        }
        pushdown(root, l, r);
        if (x <= mid)
            return query(lson, l, mid, x);
        else
            return query(rson, mid + 1, r, x);
    }

    void build(ll root, ll l, ll r, ll d[]) {
        if (l == r) {
            t[root].data = d[l];
            return;
        }
        t[root].tag = 0;
        build(lson, l, mid, d);
        build(rson, mid + 1, r, d);
        t[root].data = t[lson].data + t[rson].data;
        return;
    }
} Tree;


void solve() {
    ll n;
    cin >> n;
    string stu;
    ll a[n + 10] = {}, c[n + 10] = {}, b[n + 10] = {}, last = -1;
    cin >> stu;
    stu = "1" + stu;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] + b[i - 1];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (ll i = 2; i <= n; i++) {
        if (c[i] < c[i - 1]) {
            cout << "No" << endl;
            return;
        }
    }
    Tree.build(1, 1, n, b);
    ll pre = c[1] - 1;
    for (ll i = 1; i <= n; i++) {
        if (c[i] != pre) {
            if (last != -1) {
                Tree.update(1, 1, n, last, n, -inf);
            }
            ll tmp = c[i] - Tree.query(1, 1, n, i);
            Tree.update(1, 1, n, i, n, tmp);
            ll bi1 = Tree.query(1, 1, n, i - 1);
            ll bi = Tree.query(1, 1, n, i);
            if (stu[i] == '1' && bi - bi1 != a[i]) {
                if (last == -1) {
                    cout << "No" << endl;
                    return;
                }
                Tree.update(1, 1, n, last, last,
                            Tree.query(1, 1, n, last + 1) - a[last + 1] - Tree.query(1, 1, n, last));
                last = -1;
            }
        } else if (stu[i] == '0') {
            last = i;
        }
        pre = c[i];
    }
    if (last != -1) {
        Tree.update(1, 1, n, last, n, -inf);
    }
    pre = c[1] - 1;
    for (ll i = 1; i <= n; i++) {
        if (Tree.query(1, 1, n, i) > c[i]) {
            cout << "No" << endl;
            return;
        }
        if (c[i] != pre && Tree.query(1, 1, n, i) != c[i]) {
            cout << "No" << endl;
            return;
        }
        pre = c[i];
    }
    cout << "Yes" << endl;
    for (ll i = 1; i <= n; i++) {
        cout << Tree.query(1, 1, n, i) - Tree.query(1, 1, n, i - 1) << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
1
6
001111
0 0 2 -3 3 -6
-5 -2 0 0 0 0
*/
