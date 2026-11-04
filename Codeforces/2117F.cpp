#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, mod = 1000000000 + 7;

ll n, d[N], lmin, lmax, lroot, is0;
vector<ll> e[N];

void add(ll x, ll y) {
    e[x].push_back(y);
    e[y].push_back(x);
}

ll dfs(ll root, ll dad) {
    ll flag = 0, t1, t2;
    for (auto son: e[root]) {
        if (son != dad) {
            flag += 1;
            dfs(son, root);
            if (flag == 1)
                t1 = d[son] + 1;
            if (flag == 2)
                t2 = d[son] + 1;
        }
    }
    if (flag == 0) {
        d[root] = 1;
        is0 += 1;
    }
    if (flag == 1) {
        d[root] = t1;
    }
    if (flag == 2) {
        lmin = min(t1, t2) - 1;
        lmax = max(t1, t2) - 1;
        d[root] = 1;
    }
    if (root == 1)
        lroot = d[root];
    return 0;
}

ll qpow(ll a, ll x) {
    ll ret = 1;
    while (x) {
        if (x % 2)
            ret = ret * a % mod;
        x /= 2;
        a = a * a % mod;
    }
    return ret % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll u, v, ans;
        cin >> n;
        is0 = 0;
        for (ll i = 1; i <= n; i++)
            e[i].clear();
        for (ll i = 1; i <= n - 1; i++) {
            cin >> u >> v;
            add(u, v);
        }
        dfs(1, 1);
        //cout << lmin << " " << lmax << " " << lroot << endl;
        if (is0 >= 3) {
            cout << 0 << endl;
            continue;
        }
        ans = qpow(2, lroot);
        if (is0 == 1) {
            cout << ans << endl;
            continue;
        }
        if (lmin == lmax)
            ans = ans * 2 % mod;
        else {
            ans = ans * (qpow(2, lmax - lmin) + qpow(2, lmax - lmin - 1)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
1
7
1 2
2 3
3 4
3 5
4 6
6 7
 */
