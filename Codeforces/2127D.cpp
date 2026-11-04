#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, mod = 1000000000 + 7, inf = 1145141919810;

ll n, m, du[N], dis[N], ans, fac[N], p1, p2;
vector<ll> e[N];

void add(ll x, ll y) {
    e[x].push_back(y);
    e[y].push_back(x);
    du[x]++, du[y]++;
}

void dfs(ll root, ll dad) {
    for (auto son: e[root]) {
        if (son != dad) {
            dis[son] = dis[root] + 1;
            dfs(son, root);
        }
    }
}

void find(ll root, ll dad) {
    //cout << "root: " << root << endl;
    if ((root == p1 || root == p2) && p1 == p2) {
        ans = ans * fac[du[root]] % mod;
    } else if ((root == p1 || root == p2) && p1 != p2) {
        ans = ans * fac[du[root] - 1] % mod;
    } else {
        ans = ans * fac[du[root] - 2] % mod;
    }
    for (auto son: e[root]) {
        //cout << son << " " << dad << " " << du[son] << endl;
        if (son != dad && du[son] >= 2) {
            //cout << "ok" << endl;
            find(son, root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    fac[0] = 1;
    for (ll i = 1; i <= N - 10; i++)
        fac[i] = fac[i - 1] * i % mod;
    cin >> T;
    while (T--) {
        ll u, v, tmp;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) {
            e[i].clear();
            du[i] = 0;
        }
        ans = 0;
        for (ll i = 1; i <= m; i++) {
            cin >> u >> v;
            add(u, v);
        }
        if (n != m + 1) {
            cout << 0 << endl;
            continue;
        }
        if (n == 2) {
            cout << 2 << endl;
            continue;
        }
        dis[1] = 1;
        dfs(1, 1);
        tmp = 1, p1 = 1;
        for (ll i = 1; i <= n; i++) {
            if (tmp < dis[i]) {
                tmp = dis[i];
                p1 = i;
            }
        }
        p1 = e[p1][0];

        dis[p1] = 1;
        dfs(p1, p1);
        tmp = 1, p2 = p1;
        for (ll i = 1; i <= n; i++) {
            if (tmp < dis[i]) {
                tmp = dis[i];
                p2 = i;
            }
        }
        p2 = e[p2][0];

        tmp = 0;
        for (ll i = 1; i <= n; i++) {
            if (du[i] >= 2)
                tmp++;
        }
        /*cout << p1 << " " << p2 << endl;
        cout << tmp << endl;
        cout << dis[p2] << endl;
        for (ll i = 1; i <= n; i++)
            cout << du[i] << " ";
        cout << endl;*/
        if (tmp != dis[p2]) {
            cout << 0 << endl;
            continue;
        }

        ans = 2;
        if (tmp >= 2)
            ans = 4;
        find(p1, p1);
        cout << ans << endl;
    }
    return 0;
}

/*
1
7 6
1 2
3 2
4 2
4 5
4 6
6 7
 */
