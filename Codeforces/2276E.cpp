#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    s = " " + s;
    ll P[n + 10][10] = {}, S[n + 10][10] = {};
    P[0][0] = S[n + 1][0] = 1;
    // *2*0*2*5*
    // 012345678
    // 876543210
    for (ll i = 1; i <= n; i++) {
        if (s[i] != '2') {
            P[i][0] = P[i - 1][0] + 1;
        } else {
            P[i][0] = 1;
        }
        if (s[i] == '2') {
            P[i][1] = P[i - 1][0];
        } else {
            P[i][1] = 0;
        }
        if (s[i] != '0') {
            P[i][2] = P[i - 1][1];
        } else {
            P[i][2] = 0;
        }
        if (s[i] == '0') {
            P[i][3] = P[i - 1][2] + P[i - 1][1] + P[i - 1][4] + P[i - 1][5] +
                      P[i - 1][6];
        } else {
            P[i][3] = 0;
        }
        if (s[i] != '2') {
            P[i][4] = P[i - 1][3];
        } else {
            P[i][4] = 0;
        }
        if (s[i] == '2') {
            P[i][5] = P[i - 1][4] + P[i - 1][3];
        } else {
            P[i][5] = 0;
        }
        if (s[i] != '5' && s[i] != '6') {
            P[i][6] = P[i - 1][5];
        } else {
            P[i][6] = 0;
        }
        if (s[i] == '5') {
            P[i][7] = P[i - 1][6] + P[i - 1][5];
        } else {
            P[i][7] = 0;
        }
        if (s[i] != '6') {
            P[i][8] = P[i - 1][7];
        } else {
            P[i][8] = 0;
        }
    }
    for (ll i = n; i >= 1; i--) {
        if (s[i] != '5' && s[i] != '6') {
            S[i][0] = S[i + 1][0] + 1;
        } else {
            S[i][0] = 1;
        }
        if (s[i] == '5') {
            S[i][1] = S[i + 1][0];
        } else {
            S[i][1] = 0;
        }
        if (s[i] != '2' && s[i] != '6') {
            S[i][2] = S[i + 1][1];
        } else {
            S[i][2] = 0;
        }
        if (s[i] == '2') {
            S[i][3] = S[i + 1][2] + S[i + 1][1];
        } else {
            S[i][3] = 0;
        }
        if (s[i] != '0') {
            S[i][4] = S[i + 1][3];
        } else {
            S[i][4] = 0;
        }
        if (s[i] == '0') {
            S[i][5] = S[i + 1][4] + S[i + 1][3] + S[i + 1][6];
        } else {
            S[i][5] = 0;
        }
        if (s[i] != '2') {
            S[i][6] = S[i + 1][5];
        } else {
            S[i][6] = 0;
        }
        if (s[i] == '2') {
            S[i][7] = S[i + 1][6] + S[i + 1][5];
        } else {
            S[i][7] = 0;
        }
        S[i][8] = S[i + 1][7];
    }
    // *2*0*2*5*
    // 012345678
    // 876543210
    for (ll i = 1; i <= n; i++) {
        ll ans = 0;
        ans =
            (P[i][0] + P[i][2] + P[i][4] + P[i][6] + P[i][8] - 1) * S[i + 1][8];
        ans += (P[i][2] + P[i][6]) * S[i + 1][6];
        ans += P[i][4] * S[i + 1][4];
        ans += P[i][6] * S[i + 1][2];
        ans += P[i][8] * (S[i][0] + S[i][2] + S[i][4] + S[i][6]);
        /*for (ll j = 0; j <= 8; j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;*/
        cout << i * (n - i + 1) - ans << " ";
    }
    cout << "\n";
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
