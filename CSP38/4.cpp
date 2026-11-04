#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, inf = 1e17, mod = 998244353;

ll n, m, ans = 0;
ll fNoccf[N][4];
ll fNoall[N][20];
ll sNoccf[N];
ll sNoall[N];
ll s1ccf[N];
ll s1cspark[N];
ll g1ccf[N];
ll gNoccf[N];
ll rNoccf[N];
ll rNoall[N];
ll r1cspark[N];
ll gall[N];
ll mul26[N];
vector<ll> Seg;

void solve() {
    cin >> n >> m;
    ll lsta = 0, cura;
    for (ll i = 1; i <= m; i++) {
        cin >> cura;
        if (cura - lsta >= 2) {
            Seg.push_back(cura - lsta - 1);
        }
        lsta = cura;
    }
    cura = n + 1;
    if (cura - lsta >= 2) {
        Seg.push_back(cura - lsta - 1);
    }
    if (Seg.empty()) {
        cout << 0 << endl;
        return;
    }

    /*for (auto i : Seg) {
        cout << i << " ";
    }
    cout << endl;*/

    mul26[0] = 1;
    for (ll i = 1; i <= n; i++) {
        mul26[i] = mul26[i - 1] * 26 % mod;
    }

    fNoccf[0][0] = 1;
    fNoall[0][0] = 1;
    sNoccf[0] = 1;
    sNoall[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fNoccf[i][0] = (fNoccf[i - 1][0] * 25 + fNoccf[i - 1][1] * 25 +
                        fNoccf[i - 1][2] * 24) %
                       mod;
        fNoccf[i][1] = (fNoccf[i - 1][0]);
        fNoccf[i][2] = (fNoccf[i - 1][1] + fNoccf[i - 1][2]) % mod;
        sNoccf[i] = (fNoccf[i][0] + fNoccf[i][1] + fNoccf[i][2]) % mod;
        s1ccf[i] = ((mul26[i] - sNoccf[i]) % mod + mod) % mod;

        fNoall[i][0] = (fNoall[i - 1][0] * 25 + fNoall[i - 1][1] * 24 +
                        fNoall[i - 1][2] * 23 + fNoall[i - 1][12] * 24 +
                        fNoall[i - 1][13] * 24 + fNoall[i - 1][14] * 24 +
                        fNoall[i - 1][15] * 24) %
                       mod;

        fNoall[i][1] =
            (fNoall[i - 1][0] + fNoall[i - 1][12] + fNoall[i - 1][13] +
             fNoall[i - 1][14] + fNoall[i - 1][15]) %
            mod;
        fNoall[i][2] = (fNoall[i - 1][1] + fNoall[i - 1][2]) % mod;
        fNoall[i][12] = (fNoall[i - 1][1] + fNoall[i - 1][2]) % mod;
        fNoall[i][13] = (fNoall[i - 1][12]);
        fNoall[i][14] = (fNoall[i - 1][13]);
        fNoall[i][15] = (fNoall[i - 1][14]);
        sNoall[i] =
            (fNoall[i][0] + fNoall[i][1] + fNoall[i][2] + fNoall[i][12] +
             fNoall[i][13] + fNoall[i][14] + fNoall[i][15]) %
            mod;
        s1cspark[i] = ((sNoccf[i] - sNoall[i]) % mod + mod) % mod;

        // cout << sNoccf[i] << endl;
    }
    // cout << endl;

    gall[0] = 1;
    gNoccf[0] = 1;
    for (ll i = 1; i <= Seg.size(); i++) {
        gall[i] = gall[i - 1] * mul26[Seg[i - 1]] % mod;
        gNoccf[i] = gNoccf[i - 1] * sNoccf[Seg[i - 1]] % mod;
        g1ccf[i] = ((gall[i] - gNoccf[i]) % mod + mod) % mod;
    }

    rNoall[Seg.size() + 1] = 1;
    rNoccf[Seg.size() + 1] = 1;
    for (ll i = Seg.size(); i >= 1; i--) {
        rNoall[i] = rNoall[i + 1] * sNoall[Seg[i - 1]] % mod;
        rNoccf[i] = rNoccf[i + 1] * sNoccf[Seg[i - 1]] % mod;
        r1cspark[i] = ((rNoccf[i] - rNoall[i]) % mod + mod) % mod;
    }

    for (ll i = 1; i <= Seg.size(); i++) {
        ll tmp = 0, len = Seg[i - 1];

        for (ll j = 3; j <= len; j++) {
            tmp = (tmp + mul26[j - 3] * s1cspark[len - j] % mod) % mod;
        }
        if (i > 1)
            tmp = tmp * gall[i - 1] % mod;
        tmp = tmp * rNoccf[i + 1] % mod;
        cout << tmp << endl;
        ans = (ans + tmp) % mod;
        tmp = 0;

        for (ll j = 3; j <= len; j++) {
            tmp = (tmp + mul26[j - 3] * sNoall[len - j] % mod) % mod;
        }
        if (i > 1)
            tmp = tmp * gall[i - 1] % mod;
        tmp = tmp * r1cspark[i + 1] % mod;
        cout << tmp << endl;
        ans = (ans + tmp) % mod;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
