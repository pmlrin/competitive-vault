#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define ls t[n].l
#define rs t[n].r
#define mid ((l+r)>>1)

const int N = 200005;
int a[N];

struct SGT {
    int id = 2;

    struct node {
        int sum, lz, l, r;
    } t[4 * N];

    void push_down(int n, int l, int r) {
        if (!ls)
            ls = id++;
        if (!rs)
            rs = id++;
        t[n].lz %= 2;
        t[ls].lz += t[n].lz;
        t[rs].lz += t[n].lz;
        if (t[n].lz == 1)
            t[ls].sum = mid - l + 1 - t[ls].sum;
        if (t[n].lz == 1)
            t[rs].sum = r - mid - t[rs].sum;
        t[n].lz = 0;
    }

    void build(int &n, int l, int r) {
        if (!n)
            n = id++;
        t[n].lz = 0;
        if (l == r) {
            t[n].sum = a[r];
            return;
        }
        build(ls, l,mid);
        build(rs,mid + 1, r);
        t[n].sum = t[ls].sum + t[rs].sum;
    }

    void update(int &n, int l, int r, int x, int y, int k) {
        if (!n)
            n = id++;
        if (x <= l && y >= r) {
            t[n].lz += k;
            t[n].lz %= 2;
            t[n].sum = r - l + 1 - t[n].sum;
            return;
        }
        push_down(n, l, r);
        if (x <= mid) {
            update(ls, l,mid, x, y, k);
        }
        if (y > mid) {
            update(rs,mid + 1, r, x, y, k);
        }
        t[n].sum = t[ls].sum + t[rs].sum;
        return;
    }

    int search(int &n, int l, int r, int x, int y) {
        if (!n)
            n = id++;
        if (x <= l && y >= r) {
            return t[n].sum;
        }
        push_down(n, l, r);
        int ans = 0;
        if (x <= mid) {
            ans += search(ls, l,mid, x, y);
        }
        if (y > mid) {
            ans += search(rs,mid + 1, r, x, y);
        }
        return ans;
    }
} t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        a[i + 1] = s[i] - '0';
    int root = 1;
    t.build(root, 1ll, n);
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 0) {
            t.update(root, 1ll, n, l, r, 1);
        } else {
            cout << t.search(root, 1ll, n, l, r) << endl;
        }
    }
    return 0;
}

/*

10 7
1011101001
0 2 4
1 1 5
0 3 7
1 1 10
1 2 6
0 1 4
1 2 6



 */
