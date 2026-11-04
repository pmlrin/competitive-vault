#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

void fill26(ll x, ll y, ll f, ll **a) {
    for (ll i = y; i <= y + 2; i++)
        a[x][i] = f;
    for (ll i = y + 3; i <= y + 5; i++)
        a[x][i] = f + 1;
    a[x + 1][y] = f;
    a[x + 1][y + 5] = f + 1;
    for (ll i = y + 1; i <= y + 4; i++)
        a[x + 1][i] = f + 2;
}

void fill14(ll x, ll y, ll f, ll **a) {
    for (ll i = y; i <= y + 3; i++)
        a[x][i] = f;
}

void solve() {
    ll n, m, sflag = 0;
    cin >> n >> m;
    if ((n == 2 && m == 2) || (n * m % 4 != 0)) {
        cout << "NO" << endl;
        return;
    }
    if (n % 4 == 0) {
        swap(n, m);
        sflag = 1;
    } else if (n > m && m % 4 != 0) {
        swap(n, m);
        sflag = 1;
    }
    ll a[n + 10][m + 10];
    ll *p[n + 10];
    for (ll i = 1; i <= n; i++)
        p[i] = a[i];
    if (m % 4 == 0) {
        ll cur = 0;
        for (ll i = 1; i <= m; i += 4) {
            for (ll j = 1; j <= n; j++) {
                fill14(j, i, ++cur, p);
            }
        }
    } else {
        ll cur = 1;
        for (ll j = 1; j <= n; j += 2) {
            fill26(j, 1, cur, p);
            cur += 3;
        }
        for (ll i = 7; i <= m; i += 4) {
            for (ll j = 1; j <= n; j++) {
                fill14(j, i, cur++, p);
            }
        }
    }
    cout << "YES" << endl;
    if (sflag == 1) {
        for (ll j = 1; j <= m; j++) {
            for (ll i = 1; i <= n; i++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
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

/*
5
 2 3
 2 4
 6 8
 6 10
 10 6

1
6 6
 */
