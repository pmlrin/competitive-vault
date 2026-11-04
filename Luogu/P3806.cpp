#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e4 + 10, M = 1e7 + 10;

ll n, m, siz[N], vis[N], ans[N], que[N];
vector<PII> e[N];
bitset<M> b;

void getSiz(ll root, ll dad) {
    siz[root] = 1;
    for (auto [son, w] : e[root]) {
        if (son == dad || vis[son]) {
            continue;
        }
        getSiz(son, root);
        siz[root] += siz[son];
    }
}

ll getCent(ll root, ll dad, ll tal) {
    for (auto [son, w] : e[root]) {
        if (son == dad || vis[son]) {
            continue;
        }
        if (siz[son] > tal / 2) {
            return getCent(son, root, tal);
        }
    }
    return root;
}

void getInfo(ll root, ll dad, ll dis, vector<ll> &ret) {
    if (dis > M - 10) {
        return;
    }
    ret.push_back(dis);
    for (auto [son, w] : e[root]) {
        if (son == dad || vis[son]) {
            continue;
        }
        getInfo(son, root, dis + w, ret);
    }
}

void calcAns(ll root) {
    getSiz(root, root);
    ll cent = getCent(root, root, siz[root]);
    vector<ll> pre;
    pre.push_back(0);
    b[0] = 1;
    for (auto [son, w] : e[cent]) {
        if (vis[son]) {
            continue;
        }
        vector<ll> cur;
        getInfo(son, cent, w, cur);
        for (auto dis : cur) {
            for (ll i = 1; i <= m; i++) {
                if (que[i] >= dis && b[que[i] - dis]) {
                    ans[i] = 1;
                }
            }
        }
        for (auto dis : cur) {
            if (!b[dis]) {
                pre.push_back(dis);
                b[dis] = 1;
            }
        }
    }
    for (auto dis : pre) {
        b[dis] = 0;
    }
    pre.clear();
    vis[cent] = 1;
    for (auto [son, w] : e[cent]) {
        if (vis[son]) {
            continue;
        }
        calcAns(son);
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 1, u, v, w; i <= n - 1; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for (ll i = 1; i <= m; i++) {
        cin >> que[i];
    }
    calcAns(1);
    for (ll i = 1; i <= m; i++) {
        if (ans[i]) {
            cout << "AYE" << endl;
        } else {
            cout << "NAY" << endl;
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