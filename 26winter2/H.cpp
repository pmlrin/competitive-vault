#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10, inf = 1e17;

ll n, m, c[N];
ll a[N], b[N];

struct Data {
    ll l, r, id, ans;
};

ll lb(ll x) { return x & (-x); }
void update(ll x, ll data) {
    while (x <= n) {
        c[x] ^= data;
        x += lb(x);
    }
}
ll query(ll x) {
    ll ans = 0;
    while (x >= 1) {
        ans ^= c[x];
        x -= lb(x);
    }
    return ans;
}

bool cmp1(Data a, Data b) {
    if (a.l == b.l) {
        return a.r < b.r;
    }
    return a.l < b.l;
}

bool cmp2(Data a, Data b) { return a.id < b.id; }

ll getans(ll l, ll r) {
    ll r1 = (b[n - l + 1] ^ b[n - r]);
    ll r2 = (query(n - l + 1) ^ query(n - r));
    return (r1 ^ r2);
}

void solve() {
    cin >> n;
    unordered_map<ll, vector<ll>> pos;
    unordered_map<ll, ll> head;
    for (ll i = n; i >= 1; i--) {
        cin >> a[i];
    }
    cin >> m;
    Data q[m + 10];
    for (ll i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m, cmp1);
    ll cur = 1;
    unordered_map<ll, ll> init;
    for (ll i = n; i >= 1; i--) {
        if (init.count(a[i]) >= 1) {
            pos[a[i]].push_back(i);
            head[a[i]] = 0;
            continue;
        }
        update(i, a[i]);
        init[a[i]] = 1;
    }
    for (ll i = 1; i <= n; i++) {
        b[i] = (b[i - 1] ^ a[i]);
    }
    for (ll i = 1; i <= m; i++) {
        while (cur < q[i].l) {
            // cout << " " << a[n - cur + 1] << endl;
            if (head[a[n - cur + 1]] < pos[a[n - cur + 1]].size()) {
                // cout << "  " << pos[a[n - cur + 1]][head[a[n - cur + 1]]]
                //     << endl;
                update(pos[a[n - cur + 1]][head[a[n - cur + 1]]],
                       a[n - cur + 1]);
                head[a[n - cur + 1]]++;
            }
            cur++;
        }
        q[i].ans = getans(q[i].l, q[i].r);
    }
    sort(q + 1, q + 1 + m, cmp2);
    for (ll i = 1; i <= m; i++) {
        cout << q[i].ans << endl;
    }
    return;
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
