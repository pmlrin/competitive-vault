#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N = 200005, M = 25, O = 4500005, mod = 998244353, inf = 1145141919810;
vector<PII > e[N * 2];
vector<int> val;
int n, m, k, spe[N], a[N];
int f[O], g[O], num[O];
int ans1 = -1, ans2;

void init(int now,int dad) {
    for (PII i: e[now]) {
        int to = i.first, v = spe[i.second];
        if (to == dad)
            continue;
        a[to] = (a[now] | v);
        init(to, now);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v;
    cin >> n >> m >> k;
    for (int i = 1; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }
    for (int i = 1; i <= m; i++) {
        cin >> u;
        spe[u] = (1ll << (i - 1));
    }
    a[1] = 0;
    init(1, 1);
    val.push_back(0);
    for (int i = 1; i <= k; i++) {
        cin >> u >> v;
        int tmp = (a[u] ^ a[v]);
        if (num[tmp] == 0) {
            val.push_back(tmp);
        }
        num[tmp]++;
    }
    g[0] = 1;
    k = val.size() - 1;
    for (int i = 1; i <= ((1ll << m) - 1); i++)
        f[i] = inf;
    for (int i = 1; i <= k; i++) {
        for (int j = ((1ll << m) - 1); j >= 0; j--) {
            if (f[j | val[i]] > f[j] + 1) {
                f[j | val[i]] = f[j] + 1;
                g[j | val[i]] = g[j] * num[val[i]] % mod;
            } else if (f[j | val[i]] == f[j] + 1) {
                g[j | val[i]] = (g[j | val[i]] + g[j] * num[val[i]]) % mod;
            }
        }
    }
    if (f[(1ll << m) - 1] >= inf)
        cout << "-1" << endl;
    else {
        ans1 = f[(1ll << m) - 1];
        ans2 = g[(1ll << m) - 1];
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}

/*
8 3 8
1 2
1 3
2 4
2 5
3 6
6 7
4 8
1 3 5
1 4
3 8
3 4
1 8
3 6
1 7
1 6
3 7

2 16
 */
