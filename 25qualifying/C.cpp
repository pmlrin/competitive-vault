#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> e[200005 + 1];
int dis[200005];

int aans = 0;

void dfs1(int x, int f) {
    int ans = 11451419199010;
    for (int c: e[x]) {
        if (c == f)
            continue;
        dfs1(c, x);
        ans = min(ans, dis[c] + 1);
    }
    if (ans == 11451419199010) {
        ans = 0;
    }
    dis[x] = ans;
}

void dfs2(int x, int f, int cnt, int out) {
    if (dis[x] == 0) {
        if (out == 0)
            cnt--;
        aans = max(aans, cnt);
    }
    if (out == 0) {
        // zou!
        out = dis[x];
    }
    out--;
    if (out == 0) {
        cnt++;
    }
    for (int c: e[x]) {
        if (c == f)
            continue;
        dfs2(c, x, cnt, out);
    }
}


void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        e[p].push_back(i);
    }
    dfs1(1, -1);
    dfs2(1, -1, 1, 0);
    cout << aans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
        cout << endl;
    }
}
/*
11 1 1 2 4 2 1 7 8 9 10

*/
