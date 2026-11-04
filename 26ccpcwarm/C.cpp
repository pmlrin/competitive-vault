#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

ll kmp(const string &s1, const string &s2) {
    ll n = s1.length();
    ll m = s2.length();
    ll kmp[m + 5] = {};
    ll x = 0;
    kmp[0] = 0;
    for (ll i = 1; i < m; i++) {
        while (x != 0 && s2[i] != s2[x])
            x = kmp[x - 1];
        if (s2[i] == s2[x]) {
            x++;
            kmp[i] = x;
        }
    }
    ll j = 0;
    ll flag = 0;
    for (ll i = 0; i < n; i++) {
        while (j != 0 && s1[i] != s2[j])
            j = kmp[j - 1];
        if (s1[i] == s2[j])
            j++;
        if (j == m) {
            return i - m + 1;
        }
    }
}

void solve() {
    ll type;
    cin >> type;
    if (type == 1) {
        ll n;
        string A, B;
        cin >> n >> A >> B;
        B += B;
        cout << kmp(B, A) << endl;
    } else {
        ll s, q, n;
        string B;
        cin >> s >> B >> q;
        n = B.size();
        for (ll i = 1, u; i <= q; i++) {
            cin >> u;
            cout << B[(u + s) % n];
        }
        cout << endl;
    }
}

int main() {
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
