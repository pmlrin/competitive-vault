#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10, inf = 1e17;

ll n, k, x, a[N];

vector<ll> check(ll dis) {
    vector<ll> ret;
    a[0] = -dis, a[n + 1] = x + dis;
    for (ll i = 0; i <= n; i++) {
        ll base = 0;
        while (a[i] + base + dis * 2 <= a[i + 1] && ret.size() < k) {
            if (ret.empty() || a[i] + dis + base != *ret.rbegin()) {
                ret.push_back(a[i] + dis + base);
            }
            base++;
        }
    }
    return ret;
}

void solve() {
    cin >> n >> k >> x;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll l = 0, r = x;
    vector<ll> ans, tmp;
    while (l <= r) {
        ll mid = (l + r) / 2;
        tmp = check(mid);
        if (tmp.size() < k) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans = tmp;
        }
    }
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << endl;
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
