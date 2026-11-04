#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 4e4 + 10, M = 2e4 + 10;

ll n, k, siz[N], vis[N], ans = 0;
vector<PII> e[N];

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
    map<ll, ll> pre;
    for (auto [son, w] : e[cent]) {
        if (vis[son]) {
            continue;
        }
        vector<ll> cur;
        getInfo(son, cent, w, cur);
        sort(cur.begin(), cur.end());
        ll R = cur.size() - 1;
        for (auto [key, val] : pre) {
            while (R >= 0 && key + cur[R] > k) {
                R--;
            }
            if (R < 0) {
                break;
            }
            ans += (R + 1) * val;
        }
        for (auto dis : cur) {
            pre[dis]++;
            if (dis <= k) {
                ans++;
            }
        }
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
    cin >> n;
    for (ll i = 1, u, v, w; i <= n - 1; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    cin >> k;
    calcAns(1);
    cout << ans << endl;
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