#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, M = 52;

ll n, p[M + 10], d[M + 10], dcnt;

void insert(ll x) {
    for (ll i = M; i >= 0; i--) {
        if ((x >> i) & 1ll) {
            if (!p[i]) {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
    }
    // 运行到这里说明可以表示 0
}

ll queryMax(ll ret = 0) {
    for (ll i = M; i >= 0; i--) {
        ret = max(ret, ret ^ p[i]);
    }
    return ret;
}

void rebuild() { // 重建为行简化阶梯形，其中 d[] 去除 0 位
    dcnt = 0;
    for (ll i = M; i >= 0; i--)
        for (ll j = i - 1; j >= 0; j--)
            if (p[i] & (1ll << j)) {
                p[i] ^= p[j];
            }
    for (ll i = 0; i <= M; i++)
        if (p[i]) {
            d[dcnt++] = p[i];
        }
}

ll kthMin(int k) {
    if (k >= (1ll << dcnt)) {
        return -1;
    }
    ll ans = 0;
    for (ll i = M; i >= 0; i--)
        if (k & (1ll << i)) {
            ans ^= d[i];
        }
    return ans;
}

ll rankMin(ll x) {
    ll ans = 0;
    for (ll i = dcnt - 1; i >= 0; i--)
        if (x >= d[i])
            ans += (1 << i), x ^= d[i];
    return ans;
}

void solve() {
    cin >> n;
    for (ll i = 1, a; i <= n; i++) {
        cin >> a;
        insert(a);
    }
    cout << queryMax() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}