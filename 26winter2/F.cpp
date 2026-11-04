#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17;

ll n, a[N], vis[N];
vector<ll> e[N];
queue<ll> q;

ll bfs() {
    ll cur = 1;
    q.push(1);
    vis[1] = 1;

    if (a[1] != 1) {
        return 0;
    }
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        set<ll> s;
        for (auto to : e[now]) {
            if (vis[to]) {
                continue;
            }
            s.insert(to);
        }
        ll len = s.size();
        for (ll i = cur + 1; i <= cur + len; i++) {
            if (s.count(a[i]) >= 1) {
                q.push(a[i]);
                vis[a[i]] = vis[now] + 1;
                s.erase(a[i]);
            } else {
                return 0;
            }
        }
        cur += len;
    }
    return 1;
}

void solve() {
    cin >> n;
    for (ll i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (bfs()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
/*
4
1 2
1 3
2 4
1 3 2 4
 */
