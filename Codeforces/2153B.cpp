#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll a, b, c, x, y, z;
    cin >> x >> y >> z;
    a = (x | z);
    b = (x | y);
    c = (y | z);
    if (((a & b) == x) && ((b & c) == y) && ((a & c) == z))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
