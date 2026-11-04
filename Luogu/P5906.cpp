#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 39;

ll n, m, a[N], Unit;
ll lpos[N], rpos[N], ansl = 0, ansr = 0;
ll slpos[N], srpos[N];
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
    cin >> n;
    Unit = sqrt(n);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 离散化：sort + unique
    vector<ll> vals(a + 1, a + n + 1);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (ll i = 1; i <= n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
    }

    cin >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (ll i = 1, l = 1, r = 0, R = 0, lastBlock = -1; i <= m; i++) {
        if (q[i].l / Unit != lastBlock) {
            for (ll j = 1; j <= n; j++) {
                slpos[a[j]] = lpos[a[j]] = n + 1;
                srpos[a[j]] = rpos[a[j]] = 0;
            }
            R = min(n, (q[i].l / Unit + 1) * Unit - 1);
            l = R + 1;
            r = R;
            ansl = ansr = 0;
            lastBlock = q[i].l / Unit;
        }
        if (q[i].l / Unit == q[i].r / Unit) {
            for (ll j = q[i].l; j <= q[i].r; j++) {
                lpos[a[j]] = min(lpos[a[j]], j);
                rpos[a[j]] = max(rpos[a[j]], j);
                ansl = max(ansl, rpos[a[j]] - lpos[a[j]]);
            }
            ans[q[i].id] = ansl;
            ansl = 0;
            for (ll j = q[i].l; j <= q[i].r; j++) {
                lpos[a[j]] = slpos[a[j]];
                rpos[a[j]] = srpos[a[j]];
            }
            continue;
        }
        while (r < q[i].r) {
            r++;
            slpos[a[r]] = lpos[a[r]] = min(lpos[a[r]], r);
            srpos[a[r]] = rpos[a[r]] = max(rpos[a[r]], r);
            ansr = max(ansr, rpos[a[r]] - lpos[a[r]]);
        }
        while (l > q[i].l) {
            l--;
            lpos[a[l]] = min(lpos[a[l]], l);
            rpos[a[l]] = max(rpos[a[l]], l);
            ansl = max(ansl, rpos[a[l]] - lpos[a[l]]);
        }
        ans[q[i].id] = max(ansl, ansr);
        ansl = 0;
        while (l <= R) {
            lpos[a[l]] = slpos[a[l]];
            rpos[a[l]] = srpos[a[l]];
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