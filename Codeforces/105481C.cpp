#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10;

ll a[N], b[N], n;
vector<ll> e[N];

ll dfs(ll root, ll dad) {
    ll flag = 0, ret = 0;
    for (auto son: e[root]) {
        if (son != dad) {
            ret += dfs(son, root);
            flag = 1;
        }
    }
    if (flag == 0) {
        b[root] = 0;
        ret = a[root];
        a[root] = 0;
        return ret;
    }
    return a[root] = ret;
}

void solve() {
    cin >> n;
    for (ll i = 1, u, w; i <= n; i++) {
        cin >> u >> w;
        e[u].push_back(i);
        e[i].push_back(u);
        a[i] = b[i] = w;
    }
    b[0] = 0;
    dfs(0, -1);
    swap(b[0], b[n]);
    sort(a, a + 1 + n);
    sort(b, b + n);
    b[n] = 2200;
    for (ll i = 0; i <= n; i++) {
        if (a[i] > b[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

/*
5
 0 500
 1 700
 1 400
 2 100
 2 200

1
0 2201
 */
