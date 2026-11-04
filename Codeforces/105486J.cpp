#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

bool cmp(PII a,PII b) {
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

void solve() {
    ll n, m, q, pm;
    cin >> n >> m >> q;
    pm = m;
    ll curlvl = -1;
    PII ans[m + 10];
    ll b[m + 10] = {};
    for (ll i = 1; i <= m; i++)
        ans[i] = {i, 0};
    for (ll i = 1, typ, id, lvl; i <= q; i++) {
        cin >> typ;
        if (typ == 1) {
            cin >> lvl;
            curlvl = lvl;
            m = pm;
        } else if (typ == 2) {
            cin >> id >> lvl;
            if (lvl == curlvl) {
                if (b[id] != curlvl) {
                    b[id] = curlvl;
                    ans[id].second += m;
                    m--;
                }
            }
        } else {
            cin >> id >> lvl;
            if (lvl == curlvl) {
                if (b[id] != curlvl) {
                    b[id] = curlvl;
                    ans[id].second += 0;
                }
            }
        }
    }
    sort(ans + 1, ans + 1 + pm, cmp);
    for (ll i = 1; i <= pm; i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
