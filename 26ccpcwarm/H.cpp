#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

void solve() {
    ll n, x, y, dis = -1;
    cin >> n;
    ll lenx[n + 10] = {}, leny[n + 10] = {}, cntx[n + 10] = {},
                cnty[n + 10] = {};
    for (ll i = 1, tmp; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> tmp;
        if (dis < tmp) {
            dis = tmp;
            x = i;
        }
    }
    dis = -1;
    for (ll i = 1, tmp; i <= n; i++) {
        cout << "? " << x << " " << i << endl;
        cin >> tmp;
        lenx[i] = tmp;
        cntx[tmp]++;
        if (dis < tmp) {
            dis = tmp;
            y = i;
        }
    }
    for (ll i = 1, tmp; i <= n; i++) {
        cout << "? " << y << " " << i << endl;
        cin >> tmp;
        leny[i] = tmp;
        cnty[tmp]++;
    }
    ll centx[n + 10] = {}, centy[n + 10] = {}, Lx = 0, Ly = 0, LLx = 0;
    for (ll i = 1; i <= n; i++) {
        if (cntx[lenx[i]] == 1) {
            centx[lenx[i]] = i;
            Lx++;
        }
        if (cnty[leny[i]] == 1) {
            centy[leny[i]] = i;
            Ly++;
        }
    }
    cout << "!" << endl;
    if (Lx == n) {
        for (ll i = 0; i <= n - 2; i++) {
            cout << centx[i] << " " << centx[i + 1] << endl;
        }
    } else {
        for (ll i = 0; i <= n; i++) {
            if (centx[i] == 0) {
                Lx = i;
                break;
            }
        }
        for (ll i = 0; i <= n; i++) {
            if (centy[i] == 0) {
                Ly = i;
                break;
            }
        }
        for (ll i = 0; i <= Lx - 2; i++) {
            cout << centx[i] << " " << centx[i + 1] << endl;
        }
        for (ll i = 0; i <= Ly - 2; i++) {
            cout << centy[i] << " " << centy[i + 1] << endl;
        }
        for (ll i = 1; i <= n; i++) {
            if (cntx[lenx[i]] == 2 && cnty[leny[i]] == 2) {
                centx[lenx[i]] = i;
                LLx = max(LLx, lenx[i]);
            }
        }
        for (ll i = Lx - 1; i <= LLx - 1; i++) {
            cout << centx[i] << " " << centx[i + 1] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
/*
5
0
1
2
3
2
3
2
1
0
3
0
1
2
3
2
*/