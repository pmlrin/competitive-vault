#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<int,int>

ll n, m, q;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll sx, sy, ex, ey, g;
    cin >> n >> m >> q;
    g = gcd(n, m);
    for (ll i = 1; i <= q; i++) {
        ll sty = -1, ety = -1;
        cin >> sx >> sy >> ex >> ey;
        if (sx == 1) {
            sty = (sy - 1) / (n / g);
        } else {
            sty = (sy - 1) / (m / g);
        }
        if (ex == 1) {
            ety = (ey - 1) / (n / g);
        } else {
            ety = (ey - 1) / (m / g);
        }
        if (sty == ety)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
