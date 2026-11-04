#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10;

ll n, m, c[N], cnt[N], ans[N], sum = 0, Unit;
ll qcnt = 0, mcnt = 0;
PII mod[N];

struct Query {
    ll l, r, t, id;
    bool operator<(const Query &x) const {
        if (l / Unit != x.l / Unit)
            return l < x.l;
        if (r / Unit != x.r / Unit) {
            if ((l / Unit) & 1)
                return r < x.r;
            return r > x.r;
        }
        if ((r / Unit) & 1)
            return t < x.t;
        return t > x.t;
    }
} quy[N];

void add(ll col) {
    if (cnt[col] == 0) {
        sum++;
    }
    cnt[col]++;
}

void del(ll col) {
    cnt[col]--;
    if (cnt[col] == 0) {
        sum--;
    }
}

void apply(ll t, ll l, ll r) {
    if (mod[t].first >= l && mod[t].first <= r) {
        add(mod[t].second);
        del(c[mod[t].first]);
    }
    swap(mod[t].second, c[mod[t].first]);
    // 下次遇到这个修改操作，肯定是回撤
    // 所以使用 swap，下次遇到自动做相反操作
}
void cancel(ll t, ll l, ll r) { // 这道题目 此函数与 apply 函数完全一样
    if (mod[t].first >= l && mod[t].first <= r) {
        add(mod[t].second);
        del(c[mod[t].first]);
    }
    swap(mod[t].second, c[mod[t].first]);
}

void solve() {
    cin >> n >> m;
    Unit = max(1ll, (ll)pow(n, 2.0 / 3.0));
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (ll i = 1; i <= m; i++) {
        char op;
        cin >> op;
        if (op == 'Q') {
            qcnt++;
            cin >> quy[qcnt].l >> quy[qcnt].r;
            quy[qcnt].id = qcnt;
            quy[qcnt].t = mcnt;
        } else {
            mcnt++;
            cin >> mod[mcnt].first >> mod[mcnt].second;
        }
    }
    sort(quy + 1, quy + 1 + qcnt);
    for (ll i = 1, l = 1, r = 0, t = 0; i <= qcnt; i++) {
        while (l > quy[i].l)
            add(c[--l]);
        while (r < quy[i].r)
            add(c[++r]);
        while (l < quy[i].l)
            del(c[l++]);
        while (r > quy[i].r)
            del(c[r--]);
        while (t < quy[i].t)
            apply(++t, l, r);
        while (t > quy[i].t)
            cancel(t--, l, r);
        ans[quy[i].id] = sum;
    }
    for (ll i = 1; i <= qcnt; i++) {
        cout << ans[i] << '\n';
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