#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == x && b == y) {
        cout << "Yes" << endl;
    } else if (a == x && (b | y) == y) {
        cout << "Yes" << endl;
    } else if (b == y && (a & x) == x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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
