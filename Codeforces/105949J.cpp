#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10, inf = 1e17;

ll n, S[N], C[N], SC[N], PC[N], ans;
string a;
vector<ll> e[N];

void dfs(ll root, ll dad) {
    for (auto son: e[root]) {
        if (son == dad) {
            continue;
        }
        dfs(son, root);
        if (a[son] == 'S') {
            S[root]++;
        }
        if (a[son] == 'C') {
            C[root]++;
            SC[root] += S[son];
        }
        if (a[son] == 'P') {
            PC[root] += C[son];
        }
    }
}

void dfs2(ll root, ll dad) {
    for (auto son: e[root]) {
        if (son == dad) {
            if (a[dad] == 'C') {
                C[root]++;
            }
            if (a[dad] == 'S') {
                S[root]++;
            }
            continue;
        }
        dfs2(son, root);
    }
}

void dfs3(ll root, ll dad) {
    for (auto son: e[root]) {
        if (son == dad) {
            continue;
        }
        dfs3(son, root);
    }
    if (a[root] == 'C') {
        ll dSC = 0, dPC = 0;
        if (a[dad] == 'C') {
            dSC += S[dad];
        }
        if (a[dad] == 'P') {
            dPC += C[dad] - 1;
        }
        ans += (SC[root] + dSC) * (PC[root] + dPC);
    }
}

void solve() {
    cin >> n >> a;
    a = " " + a;
    ans = 0;
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        S[i] = C[i] = SC[i] = PC[i] = 0;
    }
    for (ll i = 1, u, v; i <= n - 1; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    dfs3(1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    // T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
