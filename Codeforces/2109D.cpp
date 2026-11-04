#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

struct CompareMin {
    bool operator()(const PII &a, const PII &b) const {
        return a.second > b.second;
    }
};

priority_queue<PII, vector<PII >, CompareMin> q;

ll n, m, l, A[N], dis[N][2], vis[N][2];
vector<ll> e[N * 4];

void add(ll x, ll y) {
    e[x].push_back(y);
    e[y].push_back(x);
}

void dij() {
    for (ll i = 1; i <= n; i++) {
        dis[i][0] = dis[i][1] = inf;
        vis[i][0] = vis[i][1] = 0;
    }
    dis[1][0] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        ll now = q.top().first, now1, now2;
        q.pop();
        if (now < N)
            now1 = now, now2 = 0;
        else
            now1 = now - N, now2 = 1;
        if (vis[now1][now2])
            continue;
        vis[now1][now2] = 1;
        for (auto to: e[now1]) {
            if (dis[to][now2 ^ 1] > dis[now1][now2] + 1) {
                dis[to][now2 ^ 1] = dis[now1][now2] + 1;
                q.push({to + (now2 ^ 1) * N, dis[to][now2 ^ 1]});
            }
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
        ll u, v, sum = 0, min1 = inf, sum0 = -inf, sum1 = -inf;
        cin >> n >> m >> l;
        for (ll i = 1; i <= n; i++)
            e[i].clear();
        for (ll i = 1; i <= l; i++) {
            cin >> A[i];
            sum += A[i];
            if (A[i] % 2)
                min1 = min(min1, A[i]);
        }
        for (ll i = 1; i <= m; i++) {
            cin >> u >> v;
            add(u, v);
        }
        if (sum % 2) {
            sum1 = sum;
            if (min1 != inf)
                sum0 = sum - min1;
        } else {
            sum0 = sum;
            if (min1 != inf)
                sum1 = sum - min1;
        }
        dij();
        for (ll i = 1; i <= n; i++) {
            if (i == 1)
                cout << 1;
            else if (dis[i][0] <= sum0 || dis[i][1] <= sum1)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}
