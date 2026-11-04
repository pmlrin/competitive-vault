#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e6 + 10;
const ll ADD = 1, DEL = -1, QUE = 2;

struct Data {
    ll id, pos, type, val, ansid;
} e[N], tmp[N];

struct Opt {
    char type;
    ll x, y;
} op[N];

ll n, m, cnt = 0, a[N], ans[N], bef[N], t[N];
set<ll> col[N];

ll lb(ll x) { return x & -x; }
void update(ll x, ll v) {
    x++;
    for (; x <= N - 10; x += lb(x)) {
        t[x] += v;
    }
}
ll query(ll x) {
    ll ret = 0;
    x++;
    for (; x >= 1; x -= lb(x)) {
        ret += t[x];
    }
    return ret;
}

void CDQ(ll l, ll r) {
    if (l == r)
        return;

    ll mid = (l + r) >> 1;

    CDQ(l, mid);
    CDQ(mid + 1, r);

    // 此时 e[l..mid] 和 e[mid+1..r] 都已经按 pos 有序
    // 下面像归并排序一样合并，同时统计左半对右半的贡献
    ll i = l, j = mid + 1, t = l;
    ll update_i = l - 1; // 记录已经加入树状数组的左半元素位置，用于清空

    while (i <= mid && j <= r) {
        if (e[i].pos <= e[j].pos) {
            // 左半元素 pos 更小，加入树状数组，并放入 tmp
            if (e[i].type != QUE) {
                update(e[i].val, e[i].type);
                update_i = i;
            }
            tmp[t++] = e[i++];
        } else {
            // 右半元素 pos 更小，此时左半中 pos <= e[j].pos
            // 的已经全部加入树状数组
            if (e[j].type == QUE) {
                ans[e[j].ansid] += query(e[j].val);
            }
            tmp[t++] = e[j++];
        }
    }

    // 左半剩余元素直接放入 tmp，不再加入树状数组
    while (i <= mid) {
        tmp[t++] = e[i++];
    }

    // 右半剩余元素：此时所有左半元素都已经加入树状数组，直接查询
    while (j <= r) {
        if (e[j].type == QUE) {
            ans[e[j].ansid] += query(e[j].val);
        }
        tmp[t++] = e[j++];
    }

    // 清空树状数组：只清空刚才加入过的左半元素
    for (ll p = l; p <= update_i; p++) {
        if (e[p].type != QUE) {
            update(e[p].val, -e[p].type);
        }
    }

    // 将归并后的结果复制回 e 数组
    for (ll i = l; i <= r; i++) {
        e[i] = tmp[i];
    }
}

void solve() {
    ll index = 0, ansindex = 0;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= m; i++) {
        cin >> op[i].type >> op[i].x >> op[i].y;
    }

    vector<ll> vals(a + 1, a + 1 + n);
    for (ll i = 1; i <= m; i++) {
        if (op[i].type == 'R') {
            vals.push_back(op[i].y);
        }
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    auto get_id = [&](int x) {
        return int(lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };
    for (int i = 1; i <= n; i++) {
        a[i] = get_id(a[i]);
    }
    for (ll i = 1; i <= m; i++) {
        if (op[i].type == 'R') {
            op[i].y = get_id(op[i].y);
        }
    }

    for (ll i = 1; i <= vals.size(); i++) {
        col[i].insert(0);
        col[i].insert(n + 1);
    }
    for (ll i = 1; i <= n; i++) {
        col[a[i]].insert(i);
    }

    ll tmp[vals.size() + 10] = {};
    for (ll i = 1; i <= n; i++) {
        bef[i] = tmp[a[i]];
        tmp[a[i]] = i;
    }

    for (ll i = 1; i <= n; i++) {
        e[++cnt] = (Data){++index, i, ADD, bef[i], ansindex};
    }
    for (ll i = 1; i <= m; i++) {
        if (op[i].type == 'Q') {
            e[++cnt] = (Data){++index, op[i].y, QUE, op[i].x - 1, ++ansindex};
            ans[ansindex] -= op[i].x - 1;
        } else {
            ll pre, nxt;
            nxt = *next(col[a[op[i].x]].find(op[i].x));
            if (nxt <= n) {
                e[++cnt] = (Data){++index, nxt, DEL, bef[nxt], ansindex};
                bef[nxt] = bef[op[i].x];
                e[++cnt] = (Data){++index, nxt, ADD, bef[nxt], ansindex};
            }
            col[a[op[i].x]].erase(op[i].x);
            e[++cnt] = (Data){++index, op[i].x, DEL, bef[op[i].x], ansindex};
            a[op[i].x] = op[i].y;
            col[a[op[i].x]].insert(op[i].x);
            pre = *prev(col[a[op[i].x]].find(op[i].x));
            nxt = *next(col[a[op[i].x]].find(op[i].x));
            bef[op[i].x] = pre;
            e[++cnt] = (Data){++index, op[i].x, ADD, bef[op[i].x], ansindex};
            if (nxt <= n) {
                e[++cnt] = (Data){++index, nxt, DEL, bef[nxt], ansindex};
                bef[nxt] = op[i].x;
                e[++cnt] = (Data){++index, nxt, ADD, bef[nxt], ansindex};
            }
        }
    }
    CDQ(1, cnt);
    for (ll i = 1; i <= ansindex; i++) {
        cout << ans[i] << endl;
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