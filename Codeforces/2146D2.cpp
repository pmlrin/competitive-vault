#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 10, M = 50;

ll QL, QR, a[N];

ll dfs(ll L, ll R) {
    //cout << L << " " << R << endl;
    ll bL[M] = {}, bR[M] = {};
    ll tL = L, tR = R, lL, lR;
    for (lL = 1; tL; lL++) {
        bL[lL] = tL % 2;
        tL /= 2;
    }
    for (lR = 1; tR; lR++) {
        bR[lR] = tR % 2;
        tR /= 2;
    }

    ll dif = lR;
    while (bL[dif] == bR[dif] && dif >= 1)
        dif--;
    if (dif <= 0) {
        a[L - QL + 1] = L;
        return L;
    }
    ll T = 0;
    for (ll i = dif; i <= lR; i++)
        T += (bR[i] << (i - 1));
    //cout << T << endl;
    //system("pause");
    ll lenl = T - L, lenr = R - T + 1;
    if (lenl <= lenr) {
        for (ll i = 1; i <= lenl; i++) {
            a[L + i - 1 - QL + 1] = T + lenl - i;
            a[T + lenl - i - QL + 1] = L + i - 1;
        }
        return (T | (T - 1)) * 2 * lenl + (lenl != lenr ? dfs(T + lenl, R) : 0);
    } else {
        for (ll i = 1; i <= lenr; i++) {
            a[R - i + 1 - QL + 1] = T - lenr + i - 1;
            a[T - lenr + i - 1 - QL + 1] = R - i + 1;
        }
        return (T | (T - 1)) * 2 * lenr + dfs(L, T - lenr - 1);
    }
}

void solve() {
    cin >> QL >> QR;
    cout << dfs(QL, QR) << endl;
    for (ll i = QL; i <= QR; i++)
        cout << a[i - QL + 1] << " ";
    cout << endl;
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
1
3 6
 */
