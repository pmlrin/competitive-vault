#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

auto cmp = [](const PII &a, const PII &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
};

void solve() {
    ll n, ans = 0;
    cin >> n;
    ll d[n + 10] = {}, vis[n + 10] = {};
    multiset<PII, decltype(cmp)> s(cmp);
    vector<ll> e[n + 10];
    for (ll i = 1, x; i <= n; i++) {
        cin >> x;
        if (i == x) {
            vis[i] = 1;
            continue;
        }
        d[i]++, d[x]++;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            s.insert({i, d[i]});
        }
    }
    while (!s.empty()) {
        auto [id, du] = *s.begin();
        s.erase({id, du});
        // cout << id << " " << du << endl;
        // cout << "size = " << s.size() << endl;
        ans++;
        vector<PII> del, upd;
        del.push_back({id, du});
        vis[id] = 1;
        for (auto u : e[id]) {
            if (!vis[u]) {
                del.push_back({u, d[u]});
                vis[u] = 1;
            }
        }
        for (auto [u, t] : del) {
            for (auto v : e[u]) {
                if (!vis[v]) {
                    upd.push_back({v, d[v]});
                    d[v]--;
                }
            }
        }

        for (auto [u, t] : upd) {
            // cout << u << " ";
            s.erase({u, t});
            s.insert({u, d[u]});
        }
        // cout << endl;
        for (auto [u, t] : del) {
            // cout << u << " ";
            s.erase({u, t});
        }
        // cout << endl;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
