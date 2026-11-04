#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 500 + 50, M = 200000 + 50, inf = 1145141919810;

struct node {
    ll x, y, dis;
};

struct CompareMin {
    bool operator()(const node &a, const node &b) const {
        return a.dis > b.dis;
    }
};

const ll nx[] = {0, 0, 0, 1, -1};
const ll ny[] = {0, 1, -1, 0, 0};
ll n, m, qu, a[N][N], t[N][N], ans[N * N], vis[N][N], dis[N][N];
priority_queue<node, vector<node>, CompareMin> q;
PII que[M];

void dij() {
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            dis[i][j] = inf;
    for (ll i = 1; i <= m; i++) {
        dis[1][i] = a[1][i];
        q.push((node){1, i, dis[1][i]});
    }
    while (!q.empty()) {
        node now = q.top();
        q.pop();
        if (vis[now.x][now.y])
            continue;
        vis[now.x][now.y] = 1;
        for (ll i = 1; i <= 4; i++) {
            ll tox = now.x + nx[i], toy = now.y + ny[i];
            if (tox < 1 || tox > n || toy < 1 || toy > m)
                continue;
            if (vis[tox][toy])
                continue;
            if (dis[tox][toy] > max(a[tox][toy], dis[now.x][now.y])) {
                dis[tox][toy] = max(a[tox][toy], dis[now.x][now.y]);
                q.push((node){tox, toy, dis[tox][toy]});
            }
        }
    }
}

bool cmp(PII x,PII y) {
    return x.first < y.first;
}

bool rec(PII x,PII y) {
    return x.second < y.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> qu;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    dij();
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            ans[(i - 1) * m + j] = dis[i][j];
            //cout << dis[i][j] << " ";
        }
        //cout << endl;
    }
    sort(ans + 1, ans + 1 + n * m);
    for (ll i = 1; i <= qu; i++) {
        cin >> que[i].first;
        que[i].second = i;
    }
    sort(que + 1, que + 1 + qu, cmp);
    for (ll i = 1, pos = 1; i <= qu; i++) {
        while (ans[pos] <= que[i].first && pos <= n * m)
            pos++;
        que[i].first = pos - 1;
    }
    sort(que + 1, que + 1 + qu, rec);
    for (ll i = 1; i <= qu; i++)
        cout << que[i].first << endl;
    return 0;
}
