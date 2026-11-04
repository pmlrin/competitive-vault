#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;
const ll N = 1000 + 50, inf = 1145141919810;

ll n, ans[N], quy[25][N], ret[N], b[N], len[25];

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ans[i] = inf;
    }

    ll index = 0;
    for (ll i = 1; i <= n; i *= 2) {
        index++;
        ll cur = 0;
        for (ll j = 1; j <= n; j++) {
            cur++;
            if (cur > i * 2)
                cur = 1;
            if (cur <= i)
                quy[index][++len[index]] = j;
        }
    }

    for (ll i = 1; i <= n; i *= 2) {
        index++;
        ll cur = 0;
        for (ll j = 1; j <= n; j++) {
            cur++;
            if (cur > i * 2)
                cur = 1;
            if (cur > i && cur <= i * 2)
                quy[index][++len[index]] = j;
        }
    }

    for (ll i = 1; i <= 20; i++) {
        if (len[i] == 0)
            break;
        for (ll j = 1; j <= n; j++) {
            b[j] = 0;
        }
        cout << len[i] << endl;
        for (ll j = 1; j <= len[i]; j++) {
            cout << quy[i][j] << " ";
            b[quy[i][j]] = 1;
        }
        cout << endl;
        for (ll j = 1; j <= n; j++) {
            cin >> ret[j];
            if (b[j] != 1)
                ans[j] = min(ans[j], ret[j]);
        }
    }

    cout << "-1" << endl;
    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
/*
0 0 1 1
0 1 0 1
2 0 0 2
0 1 0 1
 */
