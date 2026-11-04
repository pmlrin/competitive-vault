#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10, inf = 1145141919810;

vector<ll> e[N];
ll a[N], d[N], cnt[N], big[N], siz[N], ans;
ll dfn[N], L[N], R[N], index;
ll n, m;

ll dfs(ll root, ll dad) {
    ll curb = 0;
    d[root] = d[dad] + 1;
    siz[root]++;
    dfn[++index] = root;
    L[root] = index;
    for (auto son: e[root]) {
        if (son == dad)
            continue;
        siz[root] += dfs(son, root);
        if (siz[son] > curb) {
            curb = siz[son];
            big[root] = son;
        }
        ans += (siz[son] - 1) * siz[son] / 2 * d[root];
    }
    R[root] = index;
    ans -= (siz[root] - 1) * siz[root] / 2 * d[root];
    return siz[root];
}

void dsu(ll root, ll dad, ll keep) {
    for (auto son: e[root]) {
        if (son == dad || son == big[root])
            continue;
        dsu(son, root, 0);
    }
    if (big[root])
        dsu(big[root], root, 1);
    for (auto son: e[root]) {
        if (son == dad || son == big[root])
            continue;
        for (ll i = L[son]; i <= R[son]; i++) {
            ans += cnt[d[dfn[i]]] * (d[dfn[i]] - d[root]);
        }
        for (ll i = L[son]; i <= R[son]; i++) {
            cnt[d[dfn[i]]]++;
        }
    }
    cnt[d[root]]++;
    if (keep == 0) {
        for (ll i = L[root]; i <= R[root]; i++) {
            cnt[d[dfn[i]]]--;
        }
    }
}

void calc() {
    sort(d + 1, d + 1 + n);
    for (ll i = 1; i <= n; i++) {
        ans += (n - i) * d[i];
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 1; i < n; i++)
        a[i] = i + 1;
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        a[u] = max(a[u], v);
    }
    ans = 0;
    index = 0;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        cnt[i] = 0;
        big[i] = 0;
        siz[i] = 0;
        d[i] = 0;
        dfn[i] = 0;
        L[i] = R[i] = 0;
    }
    for (ll i = 1; i < n; i++) {
        e[i].push_back(a[i]);
        e[a[i]].push_back(i);
    }
    // phrase 1
    dfs(n, n);
    // phrase 2
    dsu(n, n, 1);
    // phrase 3
    calc();
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
