#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e5 + 10, L = 18;

ll dep[N];
vector<ll> e[N];

void dfs(ll root, ll dad) {
    dep[root] = dep[dad] + 1;
    for (auto son : e[root]) {
        if (son == dad) {
            continue;
        }
        dfs(son, root);
    }
}

ll calc(const ll &n, const ll *a) {
    ll ret = 0, top = 0;
    PII stk[n + 10];
    for (ll i = 1; i <= n; i++) {
        e[i].clear();
        dep[i] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        while (top >= 1 && stk[top].first <= a[i]) {
            e[stk[top].second].push_back(i);
            e[i].push_back(stk[top].second);
            top--;
        }
        stk[++top] = {a[i], i};
    }
    for (ll i = 1; i <= n; i++) {
        dep[i] = 1;
    }
    for (ll i = 1; i <= n; i++) {
        ret += dep[i];
    }
    // cout << ret << endl;
    return ret;
}

void solve() {
    ll n, ans = 0;
    cin >> n;
    ll a[n + 10];
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ans += calc(n, a);
    ans -= n;
    for (ll i = 1; i <= n / 2; i++) {
        swap(a[i], a[n - i + 1]);
    }
    ans += calc(n, a);
    cout << ans << endl;
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
/*
4
1 3 2 4
*/