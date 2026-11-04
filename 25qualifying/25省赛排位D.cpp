#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

ll n, m, du[N], st, maxd, eu[N], ev[N], index = 0, vis[N];
ll dad[N];
vector<ll> e[N];
queue<ll> q;

void add(ll x, ll y) {
    e[x].push_back(y);
    e[y].push_back(x);
    du[x] += 1;
    du[y] += 1;
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

void bfs() {
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        for (auto to: e[now]) {
            if (vis[to] == 0) {
                index += 1;
                eu[index] = now, ev[index] = to;
                q.push(to);
                vis[to] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll u, v;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        cin >> u >> v;
        add(u, v);
    }
    maxd = 0;
    for (ll i = 1; i <= n; i++) {
        dad[i] = i;
        if (du[i] > maxd) {
            maxd = du[i];
            st = i;
        }
    }
    for (auto i: e[st]) {
        index += 1;
        eu[index] = st, ev[index] = i;
        q.push(i);
        vis[i] = 1;
    }
    vis[st] = 1;
    bfs();
    for (ll i = 1; i <= index; i++)
        cout << eu[i] << " " << ev[i] << endl;
    return 0;
}

/*
1 3
1
 */
