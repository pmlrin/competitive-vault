#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll a1, b1, ha1, hb1;
    cin >> a1 >> b1 >> ha1 >> hb1;
    __int128_t a = a1, b = b1, ha = ha1, hb = hb1, t1, t2, t;
    t1 = (hb / a) - (hb % a == 0);
    t2 = (ha / b) - (ha % b == 0);
    t = min(t1, t2);
    hb -= a * t;
    ha -= b * t;
    if (hb <= a * 4 && ha > b * 4) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
