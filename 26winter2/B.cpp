#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17;

ll n, d;
PII a[N];

bool cmp(PII a, PII b) { return a.first < b.first; }

void solve() {
    ll ans = 0;
    cin >> n >> d;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (ll i = 1; i <= n; i++) {
        a[i].second += a[i - 1].second;
    }
    ll R = 1;
    for (ll L = 1; L <= n; L++) {
        while (R < n && a[R].first - a[L].first < d) {
            R++;
        }
        if (a[R].first - a[L].first >= d) {
            R--;
        }
        ans = max(ans, a[R].second - a[L - 1].second);
    }
    cout << ans << endl;
    return;
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
