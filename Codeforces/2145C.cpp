#include <bits/stdc++.h>
using namespace std;
typedef int ll;
#define PII pair<ll,ll>
const ll N = 2e5 + 10, O = 2e5 + 5;

ll n, p[N];
vector<ll> Rval[N * 2];
string s;

void solve() {
    cin >> n >> s;
    for (ll i = max(0, O - n * 2); i <= min(O + n, N * 2 - 1); i++)
        Rval[i].clear();
    for (ll i = 0; i <= n - 1; i++) {
        if (s[i] == 'a')
            p[i + 1] = -1;
        else
            p[i + 1] = 1;
    }
    for (ll i = 1; i <= n; i++) {
        p[i] = p[i - 1] + p[i];
    }
    for (ll i = n; i >= 1; i--) {
        Rval[O + p[i]].push_back(i);
    }
    if (p[n] == 0) {
        cout << 0 << endl;
        return;
    }
    ll ans = n;
    for (ll i = 1; i <= n; i++) {
        ll Lval = p[i - 1], sum = p[n];
        ll pos = Lval + sum;
        if (pos < -n || pos > n)
            continue;
        while (Rval[O + pos].size() >= 1 && Rval[O + pos].back() < i)
            Rval[O + pos].pop_back();
        if (Rval[O + pos].size() <= 0)
            continue;
        ans = min(ans, Rval[O + pos].back() - i + 1);
    }
    if (ans == n)
        cout << -1 << endl;
    else
        cout << ans << endl;
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
3
abb
 */
