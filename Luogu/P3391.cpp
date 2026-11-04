#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 10;

struct Node {
    ll l, r;
    ll val;
    ll pri;
    ll sz;
    bool rev;
} t[N];

ll tot = 0, root = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll newNode(ll v) {
    ++tot;
    t[tot].l = t[tot].r = 0;
    t[tot].val = v;
    t[tot].pri = rng() & 0x7fffffff;
    t[tot].sz = 1;
    t[tot].rev = false;
    return tot;
}

void pushup(ll p) { t[p].sz = t[t[p].l].sz + t[t[p].r].sz + 1; }

void pushdown(ll p) {
    if (!t[p].rev)
        return;
    swap(t[p].l, t[p].r);
    if (t[p].l)
        t[t[p].l].rev ^= 1;
    if (t[p].r)
        t[t[p].r].rev ^= 1;
    t[p].rev = false;
}

void splitK(ll p, ll k, ll &a, ll &b) {
    if (!p) {
        a = b = 0;
        return;
    }
    pushdown(p);
    if (t[t[p].l].sz < k) {
        a = p;
        splitK(t[p].r, k - t[t[p].l].sz - 1, t[p].r, b);
    } else {
        b = p;
        splitK(t[p].l, k, a, t[p].l);
    }
    pushup(p);
}

ll merge(ll a, ll b) {
    if (!a || !b)
        return a ? a : b;
    if (t[a].pri > t[b].pri) {
        pushdown(a);
        t[a].r = merge(t[a].r, b);
        pushup(a);
        return a;
    } else {
        pushdown(b);
        t[b].l = merge(a, t[b].l);
        pushup(b);
        return b;
    }
}

// 如果要在任意位置 k 插入（1-indexed，插到第 k 个位置）
void insertAt(ll k, ll v) {
    ll a, b;
    splitK(root, k - 1, a, b);
    root = merge(merge(a, newNode(v)), b);
}

void reverse(ll l, ll r) {
    ll a, b, c;
    splitK(root, l - 1, a, b);
    splitK(b, r - l + 1, b, c);
    t[b].rev ^= 1;
    root = merge(merge(a, b), c);
}

void inorder(ll p) {
    if (!p)
        return;
    pushdown(p);
    inorder(t[p].l);
    cout << t[p].val << ' ';
    inorder(t[p].r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++) {
        root = merge(root, newNode(i)); // 每次接到末尾
    }
    while (m--) {
        ll l, r;
        cin >> l >> r;
        reverse(l, r);
    }

    inorder(root);
    cout << '\n';
    return 0;
}