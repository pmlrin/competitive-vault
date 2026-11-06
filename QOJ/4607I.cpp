#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int, int>
void solve1() {
    int n, m;
    cin >> n >> m;
    vector<int> e[n + 5];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int ans[n + 1];
    int vis[n + 1] = {};
    int num = 1;
    for (int ind = 1; ind <= n; ind++) {
        if (vis[ind] == 1)
            continue;
        vis[ind] = 1;
        queue<int> q;
        q.push(ind);
        ans[ind] = num++;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int c : e[x]) {
                if (vis[c] == 1)
                    continue;
                vis[c] = 1;
                q.push(c);
                ans[c] = num++;
            }
            num++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

void solve2() {
    int n;
    cin >> n;
    int a[n + 5];
    int dian[2 * n + 5] = {};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dian[a[i]] = i;
    }
    vector<PII> ans;
    queue<int> q;
    int num = 1;
    while (num <= 2 * n) {
        q.push(dian[num++]);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            while (dian[num] != 0) {
                q.push(dian[num]);
                ans.push_back({x, dian[num]});
                num++;
            }
            num++;
        }
    }
    cout << ans.size() << '\n';

    for (auto [t1, t2] : ans) {
        cout << t1 << ' ' << t2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    if (s == "cat") {
        ll T = 1;
        cin >> T;
        while (T--) {
            solve1();
        }
    } else {
        ll T = 1;
        cin >> T;
        while (T--) {
            solve2();
        }
    }
    return 0;
}
/*

cat
4
1 0
4 3
1 2
4 3
2 3
7 2
6 4
7 1
10 7
10 9
7 9
10 5
4 8
3 7
4 10
1 2


dog
4
1
1
4
1 2 4 6
7
1 5 7 9 13 10 2
10
1 2 5 13 12 19 6 16 8 10


*/