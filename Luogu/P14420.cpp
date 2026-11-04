#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 39;

ll n, m, Unit;
PII a[N];
ll cnt[N], scnt[N], ansl = 0, ansr = 0;
ll ans[N];

struct Query {
    ll l, r, id;
    bool operator<(const Query &x) const {
        if (l / Unit != x.l / Unit)
            return l < x.l;
        return r < x.r;
    }
} q[N];

void solve() {
    ll index = 0;
    cin >> n >> m;
    Unit = sqrt(n);

    vector<ll> vals;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i].first;
        vals.push_back(a[i].first);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (ll i = 1; i <= n; i++) {
        a[i].second = lower_bound(vals.begin(), vals.end(), a[i].first) -
                      vals.begin() + 1;
    }

    for (ll i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (ll i = 1, l = 1, r = 0, R = 0, lastBlock = -1; i <= m; i++) {
        if (q[i].l / Unit != lastBlock) {
            for (ll j = 1; j <= n; j++) {
                scnt[a[j].second] = 0;
                cnt[a[j].second] = 0;
            }
            R = min(n, (q[i].l / Unit + 1) * Unit - 1);
            l = R + 1;
            r = R;
            ansl = ansr = 0;
            lastBlock = q[i].l / Unit;
        }
        if (q[i].l / Unit == q[i].r / Unit) {
            for (ll j = q[i].l; j <= q[i].r; j++) {
                cnt[a[j].second]++;
                ansl = max(ansl, cnt[a[j].second] * a[j].first);
            }
            ans[q[i].id] = ansl;
            ansl = 0;
            for (ll j = q[i].l; j <= q[i].r; j++) {
                cnt[a[j].second] = 0;
            }
            continue;
        }
        while (r < q[i].r) {
            r++;
            scnt[a[r].second]++;
            cnt[a[r].second]++;
            ansr = max(ansr, cnt[a[r].second] * a[r].first);
        }
        while (l > q[i].l) {
            l--;
            cnt[a[l].second]++;
            ansl = max(ansl, cnt[a[l].second] * a[l].first);
        }
        ans[q[i].id] = max(ansl, ansr);
        ansl = 0;
        while (l <= R) {
            cnt[a[l].second] = scnt[a[l].second];
            l++;
        }
    }
    for (ll i = 1; i <= m; i++) {
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