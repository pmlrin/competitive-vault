#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll inf = 1145141919810;

void solve() {
    ll n, ans = 0;
    cin >> n;
    ll a[n + 10][5], b[n + 10], cnt[5] = {}, typ[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        ll jud = max({a[i][1], a[i][2], a[i][3]});
        ans += jud;
        if (jud == a[i][1]) {
            cnt[1]++;
            typ[i] = 1;
        } else if (jud == a[i][2]) {
            cnt[2]++;
            typ[i] = 2;
        } else {
            cnt[3]++;
            typ[i] = 3;
        }
    }
    ll A, B, C;
    if (cnt[1] > n / 2) {
        A = 1, B = 2, C = 3;
    } else if (cnt[2] > n / 2) {
        A = 2, B = 1, C = 3;
    } else if (cnt[3] > n / 2) {
        A = 3, B = 2, C = 1;
    } else {
        cout << ans << endl;
        return;
    }
    for (ll i = 1; i <= n; i++) {
        if (typ[i] == A) {
            b[i] = min(a[i][A] - a[i][B], a[i][A] - a[i][C]);
        } else {
            b[i] = inf;
        }
    }
    sort(b + 1, b + 1 + n);
    for (ll i = 1, p = cnt[A]; p > n / 2; i++, p--) {
        ans -= b[i];
    }
    cout << ans << endl;
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
