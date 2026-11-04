#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17;

vector<PII> e[N];
vector<ll> ans;
ll n, m, cur[N], in[N], out[N], vis[N * 2], st = 0, ed = 0;

bool cmp(PII a, PII b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

void dfs(ll now) {
    for (ll &i = cur[now]; i < e[now].size(); i++) {
        if (!vis[e[now][i].second]) {
            vis[e[now][i].second] = 1;
            dfs(e[now][i].first);
        }
    }
    ans.push_back(now);
}

void solve() {
    cin >> n >> m;
    for (ll i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back({v, i});
        in[v]++;
        out[u]++;
    }
    for (ll i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end(), cmp);
        if (abs(in[i] - out[i]) > 1) {
            cout << "No" << endl;
            return;
        }
        if (out[i] - in[i] == 1) {
            if (st) {
                cout << "No" << endl;
                return;
            }
            st = i;
        }
        if (in[i] - out[i] == 1) {
            if (ed) {
                cout << "No" << endl;
                return;
            }
            ed = i;
        }
    }
    if (!st) {
        st = 1;
    }
    dfs(st);
    if (ans.size() != m + 1) {
        cout << "No" << endl;
        return;
    }
    for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
