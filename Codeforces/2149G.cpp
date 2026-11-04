#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root * 2)
#define rson (root * 2 + 1)
#define mid ((l + r) / 2)
const ll N = 200000 + 50;

ll n, q, a[N];
vector<ll> f[N];
map<ll, ll> rnk, raw;

struct node {
    ll maxn[3]{};
    ll mnum[3]{};

    node() {
        for (ll i = 1; i <= 2; i++) {
            maxn[i] = 0;
            mnum[i] = 0;
        }
    }
};

struct SGT {
    node t[N * 4];

    void debug(node x) {
        cout << x.maxn[1] << ": " << x.mnum[1] << endl;
        cout << x.maxn[2] << ": " << x.mnum[2] << endl;
    }

    node merge(node p1, node p2) {
        //cout << "p1" << endl;
        //debug(p1);
        //cout << "p2" << endl;
        //debug(p2);
        for (ll i = 1; i <= 2; i++) {
            if (p2.mnum[i] <= 0)
                continue;
            if (p1.maxn[1] == p2.maxn[i] && p1.mnum[1] > 0) {
                p1.mnum[1] += p2.mnum[i];
            } else if (p1.maxn[2] == p2.maxn[i] && p1.mnum[2] > 0) {
                p1.mnum[2] += p2.mnum[i];
            } else if (p1.mnum[1] == 0) {
                p1.maxn[1] = p2.maxn[i];
                p1.mnum[1] = p2.mnum[i];
            } else if (p1.mnum[2] == 0) {
                p1.maxn[2] = p2.maxn[i];
                p1.mnum[2] = p2.mnum[i];
            } else {
                ll dec = min({p1.mnum[1], p1.mnum[2], p2.mnum[i]});
                p1.mnum[1] -= dec;
                p1.mnum[2] -= dec;
                p2.mnum[i] -= dec;
                if (p1.mnum[1] == 0) {
                    p1.maxn[1] = p2.maxn[i];
                    p1.mnum[1] = p2.mnum[i];
                } else if (p1.mnum[2] == 0) {
                    p1.maxn[2] = p2.maxn[i];
                    p1.mnum[2] = p2.mnum[i];
                }
            }
        }
        if (p1.maxn[1] > p1.maxn[2]) {
            swap(p1.maxn[1], p1.maxn[2]);
            swap(p1.mnum[1], p1.mnum[2]);
        }
        //cout << "pans" << endl;
        //debug(p1);
        return p1;
    }

    void pushup(ll root) {
        t[root] = merge(t[lson], t[rson]);
    }

    void build(ll root, ll l, ll r) {
        if (l == r) {
            t[root].maxn[1] = 0;
            t[root].maxn[2] = a[l];
            t[root].mnum[1] = 0;
            t[root].mnum[2] = 1;
            return;
        }
        build(lson, l,mid);
        build(rson,mid + 1, r);
        pushup(root);
    }

    node query(ll root, ll l, ll r, ll x, ll y) {
        if (x <= l && r <= y) {
            return t[root];
        }
        node ansl, ansr;
        if (x <= mid)
            ansl = query(lson, l,mid, x, y);
        if (y > mid)
            ansr = query(rson,mid + 1, r, x, y);
        return merge(ansl, ansr);
    }
} Tree;

ll frequ(ll x, ll l, ll r) {
    return upper_bound(f[x].begin(), f[x].end(), r) - lower_bound(f[x].begin(), f[x].end(), l);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        rnk.clear();
        raw.clear();
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            rnk[a[i]] = i;
            f[i].clear();
        }
        ll index = 0;
        for (auto [key,val]: rnk) {
            rnk[key] = ++index;
            raw[index] = key;
        }
        for (ll i = 1; i <= n; i++) {
            a[i] = rnk[a[i]];
            f[a[i]].push_back(i);
        }
        Tree.build(1, 1, n);
        for (ll i = 1; i <= q; i++) {
            ll l, r, flag = 1;
            cin >> l >> r;
            node ans = Tree.query(1, 1, n, l, r);
            if (frequ(ans.maxn[1], l, r) > (r - l + 1) / 3 && ans.mnum[1] > 0) {
                cout << raw[ans.maxn[1]] << " ";
                flag = 0;
            }
            if (frequ(ans.maxn[2], l, r) > (r - l + 1) / 3 && ans.mnum[2] > 0) {
                cout << raw[ans.maxn[2]] << " ";
                flag = 0;
            }
            if (flag)
                cout << -1 << " ";
            cout << endl;
        }
    }
    return 0;
}

/*
1
4 1
1 1 2 2
1 4
 */
