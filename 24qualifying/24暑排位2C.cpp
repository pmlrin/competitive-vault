#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

const ll N = 200005;
const ll inf = 1145141919810;
ll n, m, k, p[N], ans1 = 0, ans2 = 0;
ll dis[N], cnt[N], vis[N], in[N];
vector<ll> e[N];

struct CompareMin {
    bool operator()(const PII &a, const PII &b) const {
        return a.second > b.second;
    }
};

priority_queue<PII, vector<PII >, CompareMin> q;
queue<ll> q2;

void add(ll u, ll v) {
    e[u].push_back(v);
}

void dij(ll st) {
    for (ll i = 1; i <= n; i++)
        dis[i] = inf;
    dis[st] = 0;
    q.push({st, 0});
    while (!q.empty()) {
        ll now = q.top().first;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (auto to: e[now]) {
            if (dis[to] > dis[now] + 1) {
                dis[to] = dis[now] + 1;
                q.push({to, dis[to]});
            }
        }
    }
}

void bfs(ll st) {
    in[st] = 0;
    cnt[st] = 1;
    for (ll i = 1; i <= n; i++) {
        vis[i] = 0;
        for (auto j: e[i]) {
            if (dis[j] == dis[i] + 1)
                in[j]++;
        }
    }
    q2.push(st);
    while (!q2.empty()) {
        ll now = q2.front();
        q2.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (auto to: e[now]) {
            if (dis[to] == dis[now] + 1) {
                cnt[to] += 1;
                in[to]--;
                if (in[to] == 0)
                    q2.push(to);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (ll i = 1; i <= m; i++) {
        ll u, v;
        cin >> u >> v;
        add(v, u);
    }
    cin >> k;
    for (ll i = 1; i <= k; i++)
        cin >> p[i];
    dij(p[k]);
    bfs(p[k]);
    for (int i = 2; i <= k; i++) {
        if (dis[p[i - 1]] - 1 == dis[p[i]]) {
            if (cnt[p[i - 1]] > 1)
                ans2++;
        } else {
            ans1++;
            ans2++;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
