#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int p[N], sz[N];

int find(int x) {
    while (x != p[x]) {
        x = p[x] = p[p[x]];
    }
    return x;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        p[i] = i, sz[i] = 1;
    //    vector<int> e[n + 1];
    // map<int, vector<int>> e;
    vector<PII> e(2 * n + 10);
    vector<int> all;
    for (int i = 0; i < n; i++) {
        auto &[a, b] = e[i];
        cin >> a >> b;
        all.emplace_back(a), all.emplace_back(b);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto &[a, b]: e) {
        a = lower_bound(all.begin(), all.end(), a) - all.begin() + 1;
        b = lower_bound(all.begin(), all.end(), b) - all.begin() + 1;
    }
    for (int i = 0; i < n; i++) {
        auto [a, b] = e[i];
        int pa = find(a), pb = find(b);
        if (pa == pb)
            continue;
        sz[pa] += sz[pb];
        p[pb] = pa;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int pp = find(i);
        ans = max(ans, sz[pp]);
    }
    cout << ans << endl;
    /*  for (int i = 0; i < n; i++) {/*
          int x, y;
          cin >> x >> y;
          e[x].push_back(y);
          e[y].push_back(x);
      }
      int ans = 0;
      map<int, int> b;
      for (int i = 1; i <= n; i++) {
          if (b[i] == 1)
              continue;
          int cnt = 1;
          queue<int> q;
          q.push(i);
          b[i] = 1;
          while (!q.empty()) {
              int x = q.front();
              q.pop();
              for (int c: e[x]) {
                  if (b[c] == 1)
                      continue;
                  q.push(c);
                  b[c] = 1;
                  cnt++;
              }
          }
          ans = max(ans, cnt);
      }*/
    // cout << ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
/*
2
2
1073741824 1073741825
1073741825 1073741824
5
1 2
2 3
1 3
4 5
4 5

 */
