#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e9 + 10;

ll a[N] = {}, len[N] = {}, ans = 0;
PII pos[N];
map<ll, ll> bat;
vector<ll> sta[N];
vector<ll> run;

void solve() {
    ll n, m;
    cin >> n >> m;
    bat.clear();
    ans = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        len[i] = 0;
        sta[i].clear();
    }
    for (ll i = 1, t1, t2; i <= m; i++) {
        cin >> t1 >> t2;
        sta[t2].push_back(t1);
        pos[i] = {t1, t2};
    }
    pos[0] = {0, 0};
    for (ll i = 1; i <= n; i++) {
        sta[i].push_back(inf + i);
        len[i]++;
        bat[sta[i][0]] = a[i];
    }
    for (ll i = 1; i <= m; i++) {
        ll dis = pos[i].first - pos[i - 1].first;
        run.clear();
        for (auto [key, val]: bat) {
            if (dis >= val) {
                dis -= val;
                ans += val;
                run.push_back(key);
            } else {
                bat[key] -= dis;
                ans += dis;
                dis = 0;
                break;
            }
        }
        if (dis >= 1) {
            cout << ans << endl;
            return;
        }
        for (auto key: run) {
            bat.erase(key);
        }
        len[pos[i].second]++;
        if (bat.count(pos[i].first)) {
            bat.erase(pos[i].first);
        }
        bat[sta[pos[i].second][len[pos[i].second] - 1]] = a[pos[i].second];
    }
    for (auto [key, val]: bat) {
        ans += val;
    }
    cout << ans << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
