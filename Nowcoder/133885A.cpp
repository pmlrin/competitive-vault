#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;
const double pi = 3.14159265;

void solve() {
    ll sx, sy, ax, ay, bx, by;
    cin >> sx >> sy >> ax >> ay >> bx >> by;
    if (sx > 0) {
        sx *= -1;
        ax *= -1;
        bx *= -1;
    }
    sx *= -1;
    double l = sqrt(ax * ax + ay * ay);
    double a = atan2(sy, sx);
    double u = atan2(ay, ax);
    double v = atan2(by, bx);
    // cout << a << " " << u << " " << v << endl;
    double mx = fabs(l * sin(u + a) / sin(a)),
           mn = fabs(l * sin(v + a) / sin(a));
    if (mn > mx) {
        swap(mx, mn);
    }
    if (v > u) {
        swap(u, v);
    }
    if (u + a > pi / 2 && pi / 2 > v + a) {
        mx = fabs(l / sin(a));
    }
    if (u + a > pi && pi > v + a) {
        mn = 0;
    }
    cout << fixed << setprecision(8) << mn << " " << mx << endl;
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
