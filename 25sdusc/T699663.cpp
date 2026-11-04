#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e6 + 10, inf = 1e17;

ll a[N], vis[N], vism[N], n, bit = 0, maxa = 0;
vector<ll> raw[N];
vector<PII> e;
queue<ll> q;

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        raw[a[i]].push_back(i);
        maxa = max(maxa, a[i]);
    }
    if (n == 1) {
        cout << a[1] << endl;
        return;
    }
    while ((1ll << bit) <= maxa) {
        bit++;
    }
    bit = ((1ll << (bit + (bit == 0))) - 1);
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        ll mask = (bit ^ (a[now]));
        if (vism[mask]) {
            continue;
        }
        vism[mask] = 1;
        for (ll i = mask;; i = i - 1 & mask) {
            if (i > n) {
                continue;
            }
            for (auto j : raw[i]) {
                if (!vis[j]) {
                    vis[j] = 1;
                    e.push_back({now, j});
                    q.push(j);
                }
            }
            raw[i].clear();
            if (i == 0) {
                break;
            }
        }
    }
    if (e.size() != n - 1) {
        cout << -1 << endl;
        return;
    }
    for (ll i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (auto [u, v] : e) {
        cout << u << " " << v << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
