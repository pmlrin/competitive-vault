#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, inf = 1e17;

ll ans[N];

ll calc2(ll n) {
    ll d[100 + 10] = {};
    for (ll i = 1; i <= n; i++) {
        ans[i] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0, tmp = i; j <= 20; j++) {
            if (tmp % 2) {
                d[j]++;
            }
            tmp /= 2;
        }
    }
    for (ll i = 0; i <= 20; i++) {
        if ((1ll << i) > n) {
            break;
        }
        if (d[i] % 2 == 0 && i >= 1) {
            ans[(1ll << i)]++;
            d[i + 1]++;
        }
        if (d[i] % 2 == 1 && i == 0) {
            ans[(1ll << i)]++;
            d[i + 1]++;
        }
    }
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        if (ans[i]) {
            ret ^= (i * 2);
        } else
            ret ^= i;
    }
    return ret;
}

ll calc1(ll n) {
    ll d[100 + 10] = {};
    for (ll i = 1; i <= n; i++) {
        ans[i] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0, tmp = i; j <= 20; j++) {
            if (tmp % 2) {
                d[j]++;
            }
            tmp /= 2;
        }
    }
    for (ll i = 0; i <= 20; i++) {
        if ((1ll << i) > n) {
            break;
        }
        if (d[i] % 2 == 0) {
            ans[(1ll << i)]++;
            d[i + 1]++;
        }
    }
    ll ret = 0;
    for (ll i = 1; i <= n; i++) {
        if (ans[i]) {
            ret ^= (i * 2);
        } else
            ret ^= i;
    }
    return ret;
}

void solve() {
    ll n;
    cin >> n;
    ll jud1 = calc1(n), jud2 = calc2(n);
    if (jud1 > jud2) {
        calc1(n);
        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        calc2(n);
        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
