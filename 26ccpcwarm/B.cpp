#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

ll ksm(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b % 2) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ret;
}

ll inv(ll a, ll mod) { return ksm(a, mod - 2, mod); }

void solve() {
    ll a, b, p, y;
    cin >> p >> y;
    cout << "? 0" << endl;
    cin >> b;
    cout << "? 1" << endl;
    cin >> a;
    a = ((a - b) % p + p) % p;
    y = ((y - b) % p + p) % p;
    ll inva = inv(a, p);
    y = y * inva % p;
    cout << "! " << y << endl;
}

int main() {
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
