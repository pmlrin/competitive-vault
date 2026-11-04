#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

struct edge {
    ll u, v, len, id;
} g[N];

ll n, m, dmax[N], emax[N];
ll dad[N];
vector<PII > e[N];
vector<edge> ge[N];

bool cmp(edge x, edge y) {
    return x.len < y.len;
}

bool recmp(edge x, edge y) {
    return x.id < y.id;
}

void add(ll x, ll y, ll len) {
    e[x].push_back({y, len});
    e[y].push_back({x, len});
}

void gadd(ll x, ll y, ll len, ll id) {
    ge[x].push_back({x, y, len, id});
    ge[y].push_back({y, x, len, id});
}

ll find(ll x) {
    while (x != dad[x]) {
        x = dad[x] = dad[dad[x]];
    }
    return x;
}

void merge(ll x, ll y) {
    x = find(x), y = find(y);
    dad[x] = y;
}

ll check(ll x, ll y) {
    x = find(x), y = find(y);
    if (x == y)
        return 1;
    return 0;
}

void dfs(ll root, ll dad) {
    for (auto son: e[root]) {
        if (son.first != dad) {
            dmax[son.first] = max(dmax[root], son.second);
            dfs(son.first, root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll u, v, len, ans = inf;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            ge[i].clear();
            e[i].clear();
        }
        for (ll i = 1; i <= m; i++) {
            cin >> u >> v >> len;
            g[i] = (edge){u, v, len, i};
            gadd(u, v, len, i);
        }
        for (ll i = 1; i <= n; i++)
            dad[i] = i;
        for (ll i = 1; i <= m; i++)
            emax[i] = inf;
        sort(g + 1, g + 1 + m, cmp);
        ll test = 0;
        for (ll i = 1; i <= m; i++) {
            if (check(g[i].u, g[i].v) == 0) {
                add(g[i].u, g[i].v, g[i].len);
                merge(g[i].u, g[i].v);
                test++;
            }
        }
        //cout << test << endl;
        dmax[1] = 0;
        dfs(1, 1);
        sort(g + 1, g + 1 + m, recmp);
        for (ll from = 1; from <= n; from++) {
            for (auto to: ge[from]) {
                emax[to.id] = min(emax[to.id], dmax[from]);
            }
        }
        for (ll i = 1; i <= m; i++)
            emax[i] = max(emax[i], g[i].len);
        /*for (ll i = 1; i <= n; i++)
            cout << dmax[i] << " ";
        cout << endl;*/
        for (ll i = 1; i <= m; i++) {
            ans = min(ans, g[i].len + max(dmax[n], emax[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
