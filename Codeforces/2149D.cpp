#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;
const ll inf = 1145141919810;

ll n, prea[N], nxta[N], preb[N], nxtb[N];
string s;

ll calc(ll st, ll ed) {
    if (st > ed)
        return 0;
    return (st + ed) * (ed - st + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll na = 0, nb = 0;
        ll ca = 0, cb = 0;
        ll ans = inf;
        cin >> n >> s;
        for (ll i = 0; i <= n + 3; i++) {
            prea[i] = preb[i] = nxta[i] = nxtb[i] = 0;
        }
        for (ll i = 1; i <= n; i++) {
            if (s[i - 1] == 'a') {
                prea[i] = nxta[i] = i;
                na++;
            } else if (s[i - 1] == 'b') {
                preb[i] = nxtb[i] = i;
                nb++;
            }
        }
        for (ll i = 1; i <= n; i++) {
            prea[i] = prea[i - 1] + prea[i];
            preb[i] = preb[i - 1] + preb[i];
        }
        for (ll i = n; i >= 1; i--) {
            nxta[i] = nxta[i + 1] + nxta[i];
            nxtb[i] = nxtb[i + 1] + nxtb[i];
        }
        for (ll i = 1; i <= n; i++) {
            if (s[i - 1] == 'a')
                ca++;
            else
                cb++;
            ans = min(ans, calc(i - ca + 1, i) - prea[i - 1] + nxta[i] - calc(i + 1, i + na - ca));
            ans = min(ans, calc(i - cb + 1, i) - preb[i - 1] + nxtb[i] - calc(i + 1, i + nb - cb));
        }
        cout << ans << endl;
    }
    return 0;
}

/*
2
32
aaaaaaaaaaaaababaabbbbbbbbbbbbbb
6
bababa

1
6
bababa
 */
