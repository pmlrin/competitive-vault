#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 100000 + 50, inf = 1145141919810, mod = 1000000000 + 7;
const ll M = 100000 + 50;

ll n, a[50], b[M], ans = 0;
string s;
map<ll, ll> f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> s;
        s = ' ' + s;
        ll len = s.size() - 1;
        for (ll j = 1; j <= 26; j++)
            a[j] = 0;
        for (ll j = 1; j <= len; j++) {
            a[s[j] - 'a' + 1]++;
        }
        for (ll j = 1; j <= 26; j++) {
            if (a[j] % 2)
                b[i] += (1ll << (j - 1));
        }
        //cout << b[i] << endl;
    }
    for (ll i = 1; i <= n; i++) {
        if (f.count(b[i]))
            ans += f[b[i]];
        for (ll j = 1; j <= 26; j++) {
            if (f.count(b[i] + (1ll << (j - 1))) && (((b[i] >> (j - 1)) & 1) == 0))
                ans += f[b[i] + (1ll << (j - 1))];
        }
        for (ll j = 1; j <= 26; j++) {
            if (f.count(b[i] - (1ll << (j - 1))) && (((b[i] >> (j - 1)) & 1) == 1))
                ans += f[b[i] - (1ll << (j - 1))];
        }
        if (f.count(b[i]) == 0)
            f[b[i]] = 1;
        else
            f[b[i]] += 1;

    }
    cout << ans << endl;
    return 0;
}

/*
5
ab
ab
ab
a
ab
 */
