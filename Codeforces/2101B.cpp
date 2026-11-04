#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson ((root*2)+1)
#define mid ((l+r)/2)
const ll N = 200000 + 50;

ll n, a[N], t[N], a2[N], pos[N], at[N];

struct SGT {
    ll t[N * 4];

    void update(ll root, ll l, ll r, ll pos, ll data) {
        if (l == r) {
            t[root] += data;
            return;
        }
        if (pos <= mid)
            update(lson, l,mid, pos, data);
        if (pos > mid)
            update(rson,mid + 1, r, pos, data);
        t[root] = t[lson] + t[rson];
    }

    ll query(ll root, ll l, ll r, ll x, ll y) {
        if (x <= l && y >= r)
            return t[root];
        ll ansl = 0, ansr = 0;
        if (x <= mid)
            ansl = query(lson, l,mid, x, y);
        if (y > mid)
            ansr = query(rson,mid + 1, r, x, y);
        return ansl + ansr;
    }

    void build(ll root, ll l, ll r) {
        if (l == r) {
            t[root] = 0;
            return;
        }
        build(lson, l,mid);
        build(rson,mid + 1, r);
        t[root] = t[lson] + t[rson];
    }
} Tree1, Tree2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll ans1 = 0, ans2 = 0;
        cin >> n;
        Tree1.build(1, 1, n);
        Tree2.build(1, 1, n);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (ll i = 1; i <= n; i += 2) {
            a2[i / 2 + 1] = a[i];
            ans1 += Tree1.query(1, 1, n, a[i] + 1, n);
            Tree1.update(1, 1, n, a[i], 1);
        }
        sort(a2 + 1, a2 + 1 + (n + 1) / 2);
        for (ll i = 1; i <= (n + 1) / 2; i++) {
            t[a2[i]] = i * 2 - 1;
        }
        for (ll i = 2; i <= n; i += 2) {
            a2[i / 2] = a[i];
            ans2 += Tree2.query(1, 1, n, a[i] + 1, n);
            Tree2.update(1, 1, n, a[i], 1);
        }
        sort(a2 + 1, a2 + 1 + n / 2);
        for (ll i = 1; i <= n / 2; i++) {
            t[a2[i]] = i * 2; // 排名
        }
        for (ll i = 1; i <= n; i++) {
            at[t[i]] = i; // 数字
        }
        //cout << ans1 << " " << ans2 << endl;
        if (((ans1 - ans2) % 2 + 2) % 2)
            swap(at[n], at[n - 2]);
        for (ll i = 1; i <= n; i++)
            cout << at[i] << " ";
        cout << endl;
    }
    return 0;
}

/*
4
5
5 4 3 1 2
6
4 6 5 3 1 2
5
4 5 3 1 2
7
3 7 2 6 1 4 5

1
5
1 3 4 2 5

1 2 5 3 4
 */
