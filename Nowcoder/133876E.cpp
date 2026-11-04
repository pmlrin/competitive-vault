#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

ll calc(vector<ll> a) {
    ll n = a.size(), ret = 0;
    for (ll i = 1; i <= n; i++) {
        ret += (2 * i - n - 1) * a[i - 1];
    }
    return ret % n;
}

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a;
    for (ll i = 1, t; i <= n; i++) {
        cin >> t;
        a.push_back(t);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
2a+4b+6c+8d+10e


*/
