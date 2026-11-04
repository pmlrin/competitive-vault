#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)
const ll N = 5e3 + 10, M = 5e5 + 10;
#define Bset bitset<M>

ll n, stk[N], ans[N];
vector<PII > a[M];

struct SGT {
    struct Node {
        vector<ll> tag;
    } t[N * 4];

    void update(ll root, ll l, ll r, ll x, ll y, ll data) {
        //if (root == 1)
        //    cout << x << " " << y << " " << data << endl;
        if (x <= l && y >= r) {
            t[root].tag.push_back(data);
            return;
        }
        if (x <= mid)
            update(lson, l,mid, x, y, data);
        if (y > mid)
            update(rson,mid + 1, r, x, y, data);
    }

    void solve(ll root, ll l, ll r, Bset sta) {
        for (auto i: t[root].tag) {
            sta = ((sta << i) | sta);
            sta[i] = 1;
        }
        if (l == r) {
            ans[l] = sta.count();
            return;
        }
        solve(lson, l,mid, sta);
        solve(rson,mid + 1, r, sta);
    }
} Tree;

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll op, x;
        cin >> op >> x;
        a[x].push_back({op, i});
    }
    for (ll i = 1; i <= M - 10; i++) {
        ll top = 0;
        if (a[i].empty())
            continue;
        for (auto [op,pos]: a[i]) {
            if (op == 1)
                stk[++top] = pos;
            else {
                Tree.update(1, 1, n + 1, stk[top--], pos - 1, i);
            }
        }
        for (ll j = 1; j <= top; j++)
            Tree.update(1, 1, n + 1, stk[j], n + 1, i);
    }
    Bset tmp;
    Tree.solve(1, 1, n + 1, tmp);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

/*
4
 1 100
 1 999
 1 10
 2 100
7
 1 1
 1 2
 1 1
 1 4
 1 5
 2 1
 2 4
 */
