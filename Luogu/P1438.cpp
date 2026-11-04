#include<bits/stdc++.h>
using namespace std;

namespace _yz {
    const int N = 500005;

    struct SGT {
        long long idata[N], n, index = 0;

        struct Node {
            Node *lson, *rson;
            long long data, tag;
        } node[N << 3], *root = &node[0];

        void pushdown(Node *tree, int l, int r) {
            if (tree->tag == 0)
                return;
            int mid = (l + r) / 2;
            tree->lson->data += tree->tag * (mid - l + 1);
            tree->rson->data += tree->tag * (r - mid);
            tree->lson->tag += tree->tag;
            tree->rson->tag += tree->tag;
            tree->tag = 0;
            return;
        }

        void update(Node *tree, int l, int r, int x, int y, long long ndata) {
            if (x <= l && y >= r) {
                tree->data += ndata * (r - l + 1);
                tree->tag += ndata;
                return;
            }
            int mid = (l + r) / 2;
            pushdown(tree, l, r);
            if (x <= mid)
                update(tree->lson, l, mid, x, y, ndata);
            if (y > mid)
                update(tree->rson, mid + 1, r, x, y, ndata);
            tree->data = tree->lson->data + tree->rson->data;
        }

        long long query(Node *tree, int l, int r, int x, int y) {
            if (x <= l && y >= r)
                return tree->data;
            pushdown(tree, l, r);
            int mid = (l + r) / 2;
            long long ansl = 0, ansr = 0;
            if (x <= mid)
                ansl = query(tree->lson, l, mid, x, y);
            if (y > mid)
                ansr = query(tree->rson, mid + 1, r, x, y);
            return ansl + ansr;
        }

        void build(Node *tree, int l, int r) {
            if (l == r) {
                tree->data = idata[l];
                return;
            }
            int mid = (l + r) / 2;
            tree->lson = &node[++index];
            tree->rson = &node[++index];
            build(tree->lson, l, mid);
            build(tree->rson, mid + 1, r);
            tree->data = tree->lson->data + tree->rson->data;
            return;
        }

        void init(int cnt, long long data[]) {
            for (int i = 1; i <= cnt; i++)
                idata[i] = data[i];
            n = cnt;
            build(root, 1, n);
            return;
        }
    } Tree;

    long long n, m, a[N], b[N];

    void yzmain() {
        int t1, t2, t3, t4, t5;
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld", a + i);
        for (int i = 1; i <= n; i++)
            b[i] = a[i] - a[i - 1];
        Tree.init(n, b);
        for (int i = 1; i <= m; i++) {
            scanf("%d", &t1);
            if (t1 == 1) {
                scanf("%d%d%d%d", &t2, &t3, &t4, &t5);
                Tree.update(Tree.root, 1, Tree.n, t2, t2, t4);
                if (t2 != t3)
                    Tree.update(Tree.root, 1, Tree.n, t2 + 1, t3, t5);
                if (t3 < n)
                    Tree.update(Tree.root, 1, Tree.n, t3 + 1, t3 + 1, -(t4 + t5 * (t3 - t2)));
            } else {
                scanf("%d", &t2);
                printf("%lld\n", Tree.query(Tree.root, 1, Tree.n, 1, t2));
            }
        }
        return;
    }
}

int main() {
    //freopen("P1438_1.in","r",stdin);
    //freopen("out.txt","w",stdout);
    _yz::yzmain();
    return 0;
}
