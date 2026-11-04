#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double
#define ls (2*n)
#define rs (2*n+1)
#define mid ((l+r)>>1)

//线段树
const int N = 100005;
const int inf = 1145141919810;

double a[N];

struct SGT {
    struct node {
        double sx, sx2, lz;
    } t[4 * N];

    void push_down(int n, int l, int r) {
        t[ls].lz += t[n].lz;
        t[rs].lz += t[n].lz;
        t[ls].sx2 += 2 * t[n].lz * t[ls].sx + t[n].lz * t[n].lz * (mid - l + 1);
        t[rs].sx2 += 2 * t[n].lz * t[rs].sx + t[n].lz * t[n].lz * (r - mid);
        t[ls].sx += t[n].lz * (mid - l + 1);
        t[rs].sx += t[n].lz * (r - mid);
        t[n].lz = 0;
    }

    void push_up(int n, int l, int r) {
        t[n].sx = t[ls].sx + t[rs].sx;
        t[n].sx2 = t[ls].sx2 + t[rs].sx2;
    }

    void build(int n, int l, int r) {
        t[n].lz = 0;
        if (l == r) {
            t[n].sx = a[r];
            t[n].sx2 = a[r] * a[r];
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        push_up(n, l, r);
    }

    void update(int n, int l, int r, int x, int y, double k) {
        if (x <= l && y >= r) {
            t[n].lz += k;
            t[n].sx2 += 2 * k * t[n].sx + k * k * (r - l + 1);
            t[n].sx += k * (r - l + 1);
            return;
        }
        push_down(n, l, r);
        if (x <= mid) {
            update(ls, l, mid, x, y, k);
        }
        if (y > mid) {
            update(rs, mid + 1, r, x, y, k);
        }
        push_up(n, l, r);
    }

    double search1(int n, int l, int r, int x, int y) {
        if (x <= l && y >= r) {
            return t[n].sx;
        }
        push_down(n, l, r);
        double ans = 0;
        if (x <= mid) {
            ans += search1(ls, l, mid, x, y);
        }
        if (y > mid) {
            ans += search1(rs, mid + 1, r, x, y);
        }
        return ans;
    }

    double search2(int n, int l, int r, int x, int y) {
        if (x <= l && y >= r) {
            return t[n].sx2;
        }
        push_down(n, l, r);
        double ans = 0;
        if (x <= mid) {
            ans += search2(ls, l, mid, x, y);
        }
        if (y > mid) {
            ans += search2(rs, mid + 1, r, x, y);
        }
        return ans;
    }

    double search(int n, int l, int r, int x, int y) {
        double x2 = search1(n, l, r, x, y) / (y - x + 1);
        return search2(n, l, r, x, y) / (y - x + 1) - x2 * x2;
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
    cout << fixed << setprecision(4);
    while (m--) {
        int opt;
        cin >> opt;
        int l, r;
        double x;
        if (opt == 1) {
            cin >> l >> r >> x;
            t.update(1ll, 1ll, n, l, r, x);
        } else if (opt == 2) {
            cin >> l >> r;
            cout << t.search1(1ll, 1ll, n, l, r) / (r - l + 1) << endl;
        } else {
            cin >> l >> r;
            cout << t.search(1ll, 1ll, n, l, r) << endl;
        }
    }
    return 0;
}
