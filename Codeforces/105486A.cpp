#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

ll getlen(ll l, ll r) {
    return r - l + 1;
}

void solve() {
    ll n, opt = 0;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    PII op[n + 10];
    ll tailarr = 0;
    for (ll i = n; i >= 1; i--) {
        if (s[i] == '-') {
            tailarr = i + 1;
            break;
        }
    }
    if (tailarr == 0) {
        cout << "No" << endl;
        return;
    }
    if (s[1] == '-') {
        cout << "No" << endl;
        return;
    }
    ll taillen = n - tailarr + 1;
    if (taillen < 3) {
        cout << "No" << endl;
        return;
    }
    for (ll i = n; i >= tailarr + 2; i--) {
        opt++;
        op[opt].first = 1;
        op[opt].second = getlen(1, i);
    }
    for (ll i = 2; i <= tailarr - 2; i++) {
        if (s[i] == '>') {
            opt++;
            op[opt].first = i;
            op[opt].second = getlen(i, tailarr + 2);
        }
    }
    cout << "Yes" << " " << opt << endl;
    for (ll i = 1; i <= opt; i++) {
        cout << op[i].first << " " << op[i].second << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    //T=1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

/*
1
>-->->->>-->>>
>---------->>>
>-->------->>>
>-->->----->>>
>-->->->>-->>>

>->>>>>

 */
