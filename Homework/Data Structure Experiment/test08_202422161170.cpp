#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Graph {
    static const ll N = 20, inf = 1e17;
    ll n, e[N][N], dis[N];
    bool vis[N];

    Graph(ll n = 0) : n(n) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                e[i][j] = inf;
            }
        }
    }
    void add(ll a, ll b, ll c) { e[a][b] = e[b][a] = c; }
    void bfs(ll st) {
        for (ll i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        queue<ll> q;
        q.push(st);
        vis[st] = 1;
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            if (u != st) {
                cout << ",";
            }
            cout << u;
            for (ll v = 1; v <= n; v++) {
                if (!vis[v] && e[u][v] != inf) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    void __dfs(ll u, ll st) {
        if (u != st) {
            cout << ",";
        }
        cout << u;
        vis[u] = 1;
        for (ll v = 1; v <= n; v++) {
            if (!vis[v] && e[u][v] != inf) {
                __dfs(v, st);
            }
        }
    }
    void dfs(ll st) {
        for (ll i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        __dfs(st, st);
    }
    ll dij(ll st, ll ed) {
        for (ll i = 1; i <= n; i++) {
            vis[i] = 0;
            dis[i] = inf;
        }
        dis[st] = 0;
        for (ll i = 1; i <= n; i++) {
            ll mind = inf, node = 0;
            for (ll j = 1; j <= n; j++) {
                if (!vis[j] && mind > dis[j]) {
                    mind = dis[j];
                    node = j;
                }
            }
            if (node == 0) {
                break;
            }
            for (ll j = 1; j <= n; j++) {
                if (!vis[j]) {
                    dis[j] = min(dis[j], dis[node] + e[node][j]);
                }
            }
            vis[node] = 1;
        }
        if (!vis[ed]) {
            return 0;
        }
        return dis[ed];
    }
};

int main() {
    cout << "Ver1\n";
    cout << "input\n";
    ll n, m;
    scanf("%lld,%lld", &n, &m);
    Graph g(n);
    for (ll i = 1, a, b, c; i <= m; i++) {
        scanf("%lld,%lld,%lld", &a, &b, &c);
        g.add(a, b, c);
    }
    cout << "output\n";
    g.bfs(1);
    cout << "\n";
    g.dfs(1);
    cout << "\n";
    cout << g.dij(1, n) << "\n";
    cout << "end\n";
    system("pause");
    return 0;
}