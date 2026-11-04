#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 2e6 + 10;

struct Node {
    ll l, r; // 左右儿子编号
    ll val;  // 权值（BST 关键字）
    ll pri;  // 随机优先级（堆关键字）
    ll sz;   // 子树大小
} t[N];

ll tot = 0, root = 0;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// 新建一个值为 v 的结点，返回它的编号
ll newNode(ll v) {
    ++tot;
    t[tot].l = t[tot].r = 0;
    t[tot].val = v;
    t[tot].pri = rng() & 0x7fffffff;
    t[tot].sz = 1;
    return tot;
}

// 用左右儿子的信息更新当前结点 p 的子树大小
void pushup(ll p) { t[p].sz = t[t[p].l].sz + t[t[p].r].sz + 1; }

// ============ 核心操作一：split（按值分裂） ============
// 把以 p 为根的子树拆成两棵：
//   a 中所有结点的 val <= v
//   b 中所有结点的 val >  v
// p: 当前子树根,  v: 分界值,  a/b: 输出参数
void split(ll p, ll v, ll &a, ll &b) {
    if (!p) {
        a = b = 0;
        return;
    } // 空树，两边都空
    if (t[p].val <= v) { // 根 <= v，根属于 a
        a = p;
        split(t[p].r, v, t[p].r, b); // 但右子树里可能还有 > v 的，继续拆
    } else {                         // 根 > v，根属于 b
        b = p;
        split(t[p].l, v, a, t[p].l); // 但左子树里可能还有 <= v 的，继续拆
    }
    pushup(p); // 更新子树大小
}

// ============ 核心操作二：splitK（按大小分裂） ============
// 把以 p 为根的子树按中序遍历前 k 个和后 size-k 个拆开
// a 接收前 k 个，b 接收剩下的（主要用于区间操作，如文艺平衡树）
void splitK(ll p, ll k, ll &a, ll &b) {
    if (!p) {
        a = b = 0;
        return;
    }
    if (t[t[p].l].sz < k) { // 左子树大小 < k，说明根和一部分右子树属于 a
        a = p;
        splitK(t[p].r, k - t[t[p].l].sz - 1, t[p].r, b);
    } else { // 左子树已经够 k 个，根和右子树都属于 b
        b = p;
        splitK(t[p].l, k, a, t[p].l);
    }
    pushup(p);
}

// ============ 核心操作三：merge（合并） ============
// 把 a、b 两棵树合并成一棵，前提：a 中所有值都小于 b 中所有值
// 做法：比较两个根的 pri，谁大谁当新根，然后递归合并
ll merge(ll a, ll b) {
    if (!a || !b)
        return a ? a : b;          // 有一边空，直接返回另一边
    if (t[a].pri > t[b].pri) {     // a 的优先级大，a 当根
        t[a].r = merge(t[a].r, b); // b 整体去和 a 的右子树合并
        pushup(a);
        return a;
    } else {                       // b 的优先级大，b 当根
        t[b].l = merge(a, t[b].l); // a 整体去和 b 的左子树合并
        pushup(b);
        return b;
    }
}

// ============ 六大操作：全部用 split / merge 拼出来 ============

// 1. 插入 v
void insert(ll v) {
    ll a, b;
    split(root, v, a, b); // a: <= v, b: > v
    root = merge(merge(a, newNode(v)), b);
}

// 2. 删除一个 v
void erase(ll v) {
    ll a, b, c;
    split(root, v, a, b);      // a: <= v, b: > v
    split(a, v - 1, a, c);     // a: < v,  c: == v
    c = merge(t[c].l, t[c].r); // 丢掉 c 的根节点（即删掉一个 v）
    root = merge(merge(a, c), b);
}

// 3. 查询 v 的排名（比 v 小的个数 + 1）
ll getRank(ll v) {
    ll a, b;
    split(root, v - 1, a, b); // a: < v
    ll ans = t[a].sz + 1;
    root = merge(a, b);
    return ans;
}

// 4. 查询第 k 小（不需要 split，直接在树上走，像 BST 上找第 k 小）
ll kth(ll k) {
    ll p = root;
    while (p) {
        ll ls = t[t[p].l].sz;
        if (k <= ls)
            p = t[p].l; // 在左子树
        else if (k == ls + 1)
            return t[p].val; // 就是根
        else {
            k -= ls + 1;
            p = t[p].r;
        } // 在右子树
    }
    return -1;
}

// 5. 前驱（小于 v 的最大值）
ll getPre(ll v) {
    ll a, b;
    split(root, v - 1, a, b); // a: < v
    ll p = a;
    while (t[p].r)
        p = t[p].r; // 一直往右走就是最大值
    ll ans = t[p].val;
    root = merge(a, b);
    return ans;
}

// 6. 后继（大于 v 的最小值）
ll getNxt(ll v) {
    ll a, b;
    split(root, v, a, b); // b: > v
    ll p = b;
    while (t[p].l)
        p = t[p].l; // 一直往左走就是最小值
    ll ans = t[p].val;
    root = merge(a, b);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m, last = 0, ans = 0;
    cin >> n >> m;
    for (ll i = 1, a; i <= n; i++) {
        cin >> a;
        insert(a);
    }
    while (m--) {
        ll op, x;
        cin >> op >> x;
        x ^= last;
        if (op == 1) {
            insert(x);
        } else if (op == 2) {
            erase(x);
        } else if (op == 3) {
            last = getRank(x);
            ans ^= last;
        } else if (op == 4) {
            last = kth(x);
            ans ^= last;
        } else if (op == 5) {
            last = getPre(x);
            ans ^= last;
        } else {
            last = getNxt(x);
            ans ^= last;
        }
    }
    cout << ans << endl;
    return 0;
}