#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ls (2*n)
#define rs (2*n+1)
#define mid ((l+r)>>1)

//线段树
const int N = 1000;

int gcd(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int a[N];

struct SGT {
    struct node {
        int g;
    } t[4 * N];

    void push_down(int n, int l, int r) {

    }

    void build(int n, int l, int r) {
        if (l == r) {
            t[n].g = a[r];
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        t[n].g = gcd(t[ls].g, t[rs].g);
    }

    int search(int n, int l, int r, int x, int y) {
        if (x <= l && y >= r) {
            return t[n].g;
        }
        int g1 = -1, g2 = -1;
        if (x <= mid) {
            g1 = search(ls, l, mid, x, y);
        }
        if (y > mid) {
            g2 = search(rs, mid + 1, r, x, y);
        }
        return gcd(g1, g2);
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
        int l, r;
        cin >> l >> r;
        cout << t.search(1ll, 1ll, n, l, r) << endl;
    }
    return 0;
}
