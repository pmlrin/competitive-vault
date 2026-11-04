#include <bits/stdc++.h>
using namespace std;
int read() {
    char c = getchar();
    while ((c < '0' || c > '9') && (c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
        c = getchar();
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return -1;
    int res = 0;
    while (c >= '0' && c <= '9') {
        res = res * 10 + (c ^ 48);
        c = getchar();
    }
    return res;
}
struct number {
    unsigned long long a[101];
    number() { memset(a, 0, sizeof(a)); }
    number(unsigned long long x) {
        memset(a, 0, sizeof(a));
        a[0] = x;
    }
    number operator+(const number &x) const {
        number res;
        __uint128_t t = 0;
        for (int i = 0; i <= 100; i++) {
            res.a[i] = a[i] + x.a[i] + t;
            t = (t + a[i] + x.a[i]) >> 64;
        }
        return res;
    }
    bool operator<(const number &x) const {
        for (int i = 100; i >= 0; i--)
            if (a[i] != x.a[i])
                return a[i] < x.a[i];
        return false;
    }
    bool operator>(const number &x) const {
        for (int i = 100; i >= 0; i--)
            if (a[i] != x.a[i])
                return a[i] > x.a[i];
        return false;
    }
    bool operator==(const number &x) const {
        for (int i = 100; i >= 0; i--)
            if (a[i] != x.a[i])
                return false;
        return true;
    }
};
void work() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<bool> vis(n + 1, false);
    vector<map<int, vector<int>>> rules(n + 1);
    vector<pair<int, pair<int, int>>> edges;
    vector<number> len(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        if (v == -1) {
            vis[u] = true;
            len[u] = 1;
        } else {
            int w = read();
            rules[v][w].push_back(u);
            rules[w][v].push_back(u);
            edges.push_back(make_pair(u, make_pair(v, w)));
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (vis[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &i : rules[u])
            if (vis[i.first]) {
                if (i.first != u)
                    rules[i.first].erase(u);
                for (auto j : i.second)
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
            }
    }
    if (!vis[1]) {
        puts("-1");
        return;
    }
    for (auto &i : rules)
        i.clear();
    vector<int> cnt(n + 1, 0);
    bool ok = false;
    for (auto &i : edges)
        if (vis[i.first] && vis[i.second.first] && vis[i.second.second]) {
            rules[i.second.first][i.second.second].push_back(i.first);
            if (i.second.first != i.second.second)
                rules[i.second.second][i.second.first].push_back(i.first);
            cnt[i.first]++;
        }
    for (int i = 1; i <= n; i++)
        if (vis[i] && !cnt[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 1)
            ok = true;
        for (auto &i : rules[u])
            if (!cnt[i.first]) {
                number tmp = len[u] + len[i.first];
                if (i.first != u)
                    rules[i.first].erase(u);
                for (auto j : i.second) {
                    len[j] = max(len[j], tmp);
                    if (!--cnt[j])
                        q.push(j);
                }
            }
    }
    if (cnt[1])
        puts("-1");
    else
        printf("%llu\n", len[1].a[0]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--)
        work();
    return 0;
}
/*
1
3 4
1->2
2->3
3->2
2->a
*/