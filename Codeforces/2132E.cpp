#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, m, q, a[N], b[N], usa[N * 2], usb[N * 2];
PII p[N * 2];

bool cmpPII(PII x,PII y) {
    return x.first > y.first;
}

bool cmpll(ll x, ll y) {
    return x > y;
}

ll finda(ll x) {
    ll l = 1, r = n + m, ret = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (usa[mid] < x)
            l = mid + 1;
        else if (usa[mid] == x) {
            ret = mid;
            r = mid - 1;
        } else
            r = mid - 1;
    }
    return ret;
}

ll findb(ll x) {
    ll l = 1, r = n + m, ret = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (usb[mid] < x)
            l = mid + 1;
        else if (usb[mid] == x) {
            ret = mid;
            r = mid - 1;
        } else
            r = mid - 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll x, y, z;
        cin >> n >> m >> q;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            p[i] = (PII){a[i], 1};
        }
        for (ll i = 1; i <= m; i++) {
            cin >> b[i];
            p[n + i] = (PII){b[i], 0};
        }
        sort(p + 1, p + n + m + 1, cmpPII);
        sort(a + 1, a + 1 + n, cmpll);
        sort(b + 1, b + 1 + m, cmpll);
        for (ll i = 1; i <= n + m; i++) {
            usa[i] = p[i].second;
            usb[i] = p[i].second ^ 1;
        }
        for (ll i = 1; i <= n + m; i++) {
            p[i].first = p[i - 1].first + p[i].first;
            usa[i] = usa[i - 1] + usa[i];
            usb[i] = usb[i - 1] + usb[i];
        }
        for (ll i = 1; i <= n; i++)
            a[i] = a[i - 1] + a[i];
        for (ll i = 1; i <= m; i++)
            b[i] = b[i - 1] + b[i];
        for (ll i = 1; i <= q; i++) {
            ll tx, ty;
            cin >> x >> y >> z;
            if (x + y < z) {
                cout << 0 << endl;
                continue;
            }
            tx = usa[z], ty = usb[z];
            if (tx <= x && ty <= y) {
                cout << p[z].first << endl;
            } else if (tx > x && ty <= y) {
                ll z1 = finda(x);
                ll ua = usa[z1], ub = usb[z1], add = z - ua - ub;
                cout << p[z1].first + b[ub + add] - b[ub] << endl;
            } else if (tx <= x && ty > y) {
                ll z1 = findb(y);
                ll ua = usa[z1], ub = usb[z1], add = z - ua - ub;
                cout << p[z1].first + a[ua + add] - a[ua] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
