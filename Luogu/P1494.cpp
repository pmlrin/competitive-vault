#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e4 + 10;

ll n, m, c[N], cnt[N], ans1[N], ans2[N], sum = 0, Unit;

struct Query {
    ll l, r, id;

    bool operator<(const Query &x) const {
        if (l / Unit != x.l / Unit)
            return l < x.l;
        if ((l / Unit) & 1)
            return r < x.r;
        return r > x.r;
    }
} q[N];

void add(ll pos) {
    sum += cnt[pos];
    cnt[pos]++;
}

void del(ll pos) {
    cnt[pos]--;
    sum -= cnt[pos];
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

void solve() {
    cin >> n >> m;
    Unit = n / sqrt(m);
    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (ll i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (ll i = 1, l = 1, r = 0; i <= m; i++) {
        if (q[i].l == q[i].r) { // 题目特判
            ans1[q[i].id] = 0, ans2[q[i].id] = 1;
            continue;
        }
        while (l > q[i].l)
            add(c[--l]);
        while (r < q[i].r)
            add(c[++r]);
        while (l < q[i].l)
            del(c[l++]);
        while (r > q[i].r)
            del(c[r--]);
        ans1[q[i].id] = sum;
        ans2[q[i].id] = (r - l + 1) * (r - l) / 2;
    }
    for (ll i = 1; i <= m; i++) {
        if (ans1[i] != 0) {
            ll g = gcd(ans1[i], ans2[i]);
            ans1[i] /= g, ans2[i] /= g;
        } else {
            ans2[i] = 1;
        }
        cout << ans1[i] << '/' << ans2[i] << '\n';
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