#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10;

struct Data {
    ll a, b, c, cnt, ans;
} e[N], tmp[N];

bool cmp(const Data &x, const Data &y) {
    if (x.a != y.a)
        return x.a < y.a;
    if (x.b != y.b)
        return x.b < y.b;
    return x.c < y.c;
}

ll n, m, k, t[N], res[N];

ll lb(ll x) { return x & -x; }

ll query(ll x) {
    ll ret = 0;
    for (; x >= 1; x -= lb(x)) {
        ret += t[x];
    }
    return ret;
}

void update(ll x, ll d) {
    for (; x <= k; x += lb(x)) {
        t[x] += d;
    }
}

void CDQ(ll l, ll r) {
    if (l == r)
        return;

    ll mid = (l + r) >> 1;

    // 先递归左右
    CDQ(l, mid);
    CDQ(mid + 1, r);

    // 此时 e[l..mid] 和 e[mid+1..r] 都已经按 b 有序
    // 下面像归并排序一样合并，同时统计左半对右半的贡献
    ll i = l, j = mid + 1, t = l;
    ll update_i = l - 1; // 记录已经加入树状数组的左半元素位置，用于清空

    while (i <= mid && j <= r) {
        if (e[i].b <= e[j].b) {
            // 左半元素 b 更小，加入树状数组，并放入 tmp
            update(e[i].c, e[i].cnt);
            update_i = i;
            tmp[t++] = e[i++];
        } else {
            // 右半元素 b 更小，此时左半中 b <= e[j].b 的已经全部加入树状数组
            e[j].ans += query(e[j].c);
            tmp[t++] = e[j++];
        }
    }

    // 左半剩余元素直接放入 tmp，不再加入树状数组
    while (i <= mid) {
        tmp[t++] = e[i++];
    }

    // 右半剩余元素：此时所有左半元素都已经加入树状数组，直接查询
    while (j <= r) {
        e[j].ans += query(e[j].c);
        tmp[t++] = e[j++];
    }

    // 清空树状数组：只清空刚才加入过的左半元素
    for (ll p = l; p <= update_i; p++) {
        update(e[p].c, -e[p].cnt);
    }

    // 把归并结果复制回去
    for (ll p = l; p <= r; p++) {
        e[p] = tmp[p];
    }
}

void solve() {
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c;
        e[i].cnt = 1;
        e[i].ans = 0;
    }
    sort(e + 1, e + 1 + n, cmp);
    for (ll i = 1; i <= n; i++) {
        if (i == 1 || e[i].a != e[i - 1].a || e[i].b != e[i - 1].b ||
            e[i].c != e[i - 1].c) {
            e[++m] = e[i];
        } else {
            e[m].cnt++;
        }
    }
    CDQ(1, m);
    for (ll i = 1; i <= m; i++) {
        ll d = e[i].ans + e[i].cnt - 1;
        res[d] += e[i].cnt;
    }

    for (ll i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}