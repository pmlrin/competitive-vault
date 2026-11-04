#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 250000 + 50, M = 1000000000 + 10;

ll n, qu, a[N], pt[N], pc[N];
map<ll, ll> typ;
queue<ll> q;

void solve() {
    cin >> n >> qu;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (typ.count(a[i]) && typ[a[i]] == 1)
            pt[i] = 1;
        else
            pt[i] = 0;
        pc[i] = 0;
        while (a[i] >= 2) {
            a[i] /= 2;
            pc[i]++;
            if (a[i] <= 1)
                break;
            a[i]++;
        }
        pt[i] += pt[i - 1];
        pc[i] += pc[i - 1];
    }
    for (ll i = 1, l, r; i <= qu; i++) {
        cin >> l >> r;
        cout << pc[r] - pc[l - 1] + (pt[r] - pt[l - 1]) / 2 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    for (ll i = 4; i <= M; i *= 2) {
        q.push(i - 1);
    }
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        if (typ.count(now))
            continue;
        typ[now] = 1;
        if (now * 2 - 1 <= M)
            q.push(now * 2 - 1);
    }
    for (auto [key,val]: typ) {
        if (typ.count(key / 2))
            typ[key] = 2;
    }
    while (T--) {
        solve();
    }
    return 0;
}
