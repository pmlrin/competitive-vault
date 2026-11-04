#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ls (2*n)
#define rs (2*n+1)
#define mid ((l+r)>>1)

//线段树
const int N = 1000005;
const int inf = 111111145141919810;

int a[N];

struct SGT {
    struct node {
        int mmax, cover, add;
    } t[4 * N];

    void push_down(int n, int l, int r) {
        if (t[n].cover != inf) {
            t[ls].cover = t[n].cover;
            t[rs].cover = t[n].cover;
            t[ls].add = 0;
            t[rs].add = 0;
            t[ls].mmax = t[n].cover;
            t[rs].mmax = t[n].cover;
            t[n].cover = inf;
        }
        t[ls].add += t[n].add;
        t[rs].add += t[n].add;
        t[ls].mmax += t[n].add;
        t[rs].mmax += t[n].add;
        t[n].add = 0;
    }

    void build(int n, int l, int r) {
        t[n].cover = inf;
        t[n].add = 0;
        if (l == r) {
            t[n].mmax = a[r];
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        t[n].mmax = max(t[ls].mmax, t[rs].mmax);
    }

    void update1(int n, int l, int r, int x, int y, int k) {
        if (x <= l && y >= r) {
            t[n].cover = k;
            t[n].add = 0;
            t[n].mmax = k;
            return;
        }
        push_down(n, l, r);
        if (x <= mid) {
            update1(ls, l, mid, x, y, k);
        }
        if (y > mid) {
            update1(rs, mid + 1, r, x, y, k);
        }
        t[n].mmax = max(t[ls].mmax, t[rs].mmax);
    }

    void update2(int n, int l, int r, int x, int y, int k) {
        if (x <= l && y >= r) {
            t[n].add += k;
            t[n].mmax += k;
            return;
        }
        push_down(n, l, r);
        if (x <= mid) {
            update2(ls, l, mid, x, y, k);
        }
        if (y > mid) {
            update2(rs, mid + 1, r, x, y, k);
        }
        t[n].mmax = max(t[ls].mmax, t[rs].mmax);
    }

    int search(int n, int l, int r, int x, int y) {
        if (x <= l && y >= r) {
            return t[n].mmax;
        }
        push_down(n, l, r);
        int ans = -inf;
        if (x <= mid) {
            ans = max(ans, search(ls, l, mid, x, y));
        }
        if (y > mid) {
            ans = max(ans, search(rs, mid + 1, r, x, y));
        }
        return ans;
    }

} t;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    t.build(1ll, 1ll, n);
    while (m--) {
        int opt;
        cin >> opt;
        int l, r, x;
        if (opt == 1) {
            cin >> l >> r >> x;
            t.update1(1ll, 1ll, n, l, r, x);
        } else if (opt == 2) {
            cin >> l >> r >> x;
            t.update2(1ll, 1ll, n, l, r, x);
        } else {
            cin >> l >> r;
            cout << t.search(1ll, 1ll, n, l, r) << endl;
        }
    }
    return 0;
}
