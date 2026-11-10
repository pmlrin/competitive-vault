#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e6 + 10, inf = 1e17, MUL = (1ll << 20);

ll n, ans[N];
vector<ll> pre[N], suf[N];

ll f(ll l, ll r) {
    if (l == r) {
        pre[1].push_back(MUL);
        suf[1].push_back(MUL);
        return ans[1] = 1;
    }
    if (ans[r - l + 1]) {
        return ans[r - l + 1];
    }

    ll mid = (l + r) / 2;
    ll lans = f(l, mid), rans = f(mid + 1, r), ret = 0;
    ll len = r - l + 1, llen = mid - l + 1, rlen = r - mid;
    map<ll, ll> b;
    for (ll i = l; i <= mid; i++) {
        b[suf[llen][i - l + 1] - (i - l + 1) * MUL]++;
    }
    for (ll i = mid + 1; i <= r; i++) {
        ret += b[(i - l + 1) * MUL - pre[rlen][i - mid] - llen * MUL];
    }

    for (ll i = l; i <= mid; i++) {
        pre[len].push_back(pre[llen][i - l + 1]);
    }
    for (ll i = mid + 1; i <= r; i++) {
        pre[len].push_back((pre[llen][llen] + pre[rlen][i - mid] + llen * MUL) /
                           2);
    }
    for (ll i = l; i <= mid; i++) {
        suf[len].push_back((suf[llen][i - l + 1] + suf[rlen][1] + llen * MUL) /
                           2);
    }
    for (ll i = mid + 1; i <= r; i++) {
        suf[len].push_back(suf[rlen][i - mid] + llen * MUL);
    }
    return ans[len] = lans + rans + ret;
}

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ans[i] = 0;
        pre[i].clear();
        suf[i].clear();
        pre[i].push_back(0);
        suf[i].push_back(0);
    }
    cout << f(1, n) << "\n";
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

/*
sufL-L=R-preR
*/