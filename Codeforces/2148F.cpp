#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

ll n, cur, maxn[N];
vector<ll> a[N];

vector<ll> max(vector<ll> a, vector<ll> b) {
    if (a[0] <= cur)
        return b;
    if (b[0] <= cur)
        return a;
    for (ll i = cur + 1; i <= a[0] && i <= b[0]; i++) {
        if (a[i] != b[i]) {
            if (a[i] < b[i])
                return a;
            return b;
        }
    }
    if (a[0] < b[0])
        return a;
    return b;
}

void debug() {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= a[i][0]; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void solve() {
    cin >> n;
    for (ll i = 1, len; i <= n; i++) {
        cin >> len;
        a[i].clear();
        a[i].push_back(len);
        for (ll j = 1, tmp; j <= len; j++) {
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }
    cur = 0;
    ll plen = n;
    while (1) {
        maxn[cur + 1] = maxn[0] = inf;
        for (ll i = 1; i <= plen; i++) {
            ll flag = 1;
            for (ll j = cur + 1; j <= a[i][0] && j <= maxn[0]; j++) {
                if (a[i][j] < maxn[j]) {
                    maxn[0] = a[i][0];
                    for (ll k = cur + 1; k <= a[i][0]; k++)
                        maxn[k] = a[i][k];
                    flag = 0;
                    break;
                }
                if (a[i][j] > maxn[j]) {
                    flag = 0;
                    break;
                }
            }
            if (a[i][0] < maxn[0] && flag) {
                maxn[0] = a[i][0];
                for (ll k = cur + 1; k <= a[i][0]; k++)
                    maxn[k] = a[i][k];
            }
        }
        if (maxn[0] <= cur || maxn[0] == inf)
            break;
        for (ll i = cur + 1; i <= maxn[0]; i++)
            cout << maxn[i] << " ";
        cur = maxn[0];

        ll len = 0;
        for (ll i = 1; i <= plen; i++) {
            if (a[i][0] <= cur)
                continue;
            a[++len] = a[i];
        }
        plen = len;
    }
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
