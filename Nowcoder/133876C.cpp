#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 5e5 + 10, inf = 1e17;
const ll nx[] = {0, 0, 0, 1, -1};
const ll ny[] = {0, 1, -1, 0, 0};

ll n, m, q, l = 0, dad[N], ans[N], siz[N], val[N], dat[N];

ll find(ll x) {
    if (x == dad[x]) {
        return x;
    }
    ll ret = find(dad[x]);
    ans[x] = max(ans[dad[x]], dat[x]);
    return dad[x] = ret;
}

void merge(ll u, ll v) {
    u = find(u), v = find(v);
    dad[u] = v;
}

PII decode(ll x) {
    x--;
    return {x / m + 1, x % m + 1};
}

ll encode(PII x) { return (x.first - 1) * m + x.second; }

vector<ll> getSon(PII pos) {
    map<ll, ll> raw;
    vector<ll> ret;
    for (ll i = 1; i <= 4; i++) {
        ll x = pos.first + nx[i], y = pos.second + ny[i];
        if (x < 1 || x > n || y < 1 || y > m) {
            continue;
        }
        raw[find(encode({x, y}))]++;
    }
    for (auto [k, v] : raw) {
        if (val[k] == 0) {
            continue;
        }
        ret.push_back(k);
    }
    return ret;
}

void solve() {
    cin >> n >> m >> q;
    for (ll i = 1; i <= n * m; i++) {
        dad[i] = i;
        ans[i] = 0;
        siz[i] = 1;
        val[i] = 0;
        dat[i] = 0;
    }
    for (ll i = 1, op, x, y, v; i <= q; i++) {
        cin >> op >> x >> y;
        x ^= l, y ^= l;
        ll pos = encode({x, y});
        if (op == 1) {
            cin >> v;
            val[pos] = v;
            vector<ll> son = getSon({x, y});
            for (auto j : son) {
                siz[pos] += siz[j];
                ans[j] = dat[j] = max(0ll, v + 1 - siz[j]);
                merge(j, pos);
            }
            l = siz[pos] - 1;
            cout << l << endl;
        } else {
            find(pos);
            l = max(0ll, ans[pos] - val[pos]);
            cout << l << endl;
        }
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
