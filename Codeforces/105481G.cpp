#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll inf = 11145141919810;

ll n, k;

ll getR(ll x) {
    return x + k - 1;
}

void solve() {
    ll ans = 0;
    cin >> n >> k;
    ll a[n + 10] = {}, cur[n + 10] = {}, bigl[n + 10] = {}, bigr[n + 10] = {};
    vector<ll> pos[n + 10];


    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }


    PII stk[n + 10];
    ll top = 0;
    a[n + 1] = inf;
    for (ll i = 1; i <= n + 1; i++) {
        while (stk[top].first < a[i] && top >= 1) {
            bigr[stk[top].second] = i;
            top--;
        }
        stk[++top] = {a[i], i};
    }

    /*for (ll i = 1; i <= n; i++)
        cout << bigr[i] << " ";
    cout << endl;*/

    top = 0;
    a[0] = inf;
    for (ll i = n; i >= 0; i--) {
        while (stk[top].first < a[i] && top >= 1) {
            bigl[stk[top].second] = i;
            top--;
        }
        stk[++top] = {a[i], i};
    }

    /*for (ll i = 1; i <= n; i++)
        cout << bigl[i] << " ";
    cout << endl;*/

    for (ll i = 1; i <= n; i++) {
        cur[a[i]]++;
        if (pos[a[i]].size() < getR(cur[a[i]]))
            continue;
        ll L = i - bigl[i];
        if (cur[a[i]] >= 2)
            L = min(L, i - pos[a[i]][cur[a[i]] - 2]);
        ll R = bigr[i] - pos[a[i]][getR(cur[a[i]]) - 1];
        if (R <= 0)
            continue;
        ans += L * R;
    }
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
2
 5 2
 1 3 3 2 2
 4 3
 1 4 2 1
 */
