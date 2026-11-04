#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 100000 + 50, inf = 1145141919810, mod = 1000000000 + 7;
const ll M = 100000 + 50;

ll n, a[N], nxt[N], top = 0, num[N];
PII stk[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll q, ans, l, r;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n - 1; i++) {
        a[i] = abs(a[i + 1] - a[i]);
    }
    a[n] = inf;
    /*for (ll i = 1; i <= n - 1; i++)
        cout << a[i] << " ";
    cout << endl;*/
    for (ll i = 1; i <= n - 1; i++) {
        while (stk[top].first < a[i] && top >= 1) {
            nxt[stk[top--].second] = i;
        }
        stk[++top] = (PII){a[i], i};
    }
    /*for (ll i = 1; i <= n - 1; i++)
        cout << nxt[i] << " ";
    cout << endl;*/
    for (ll i = 1; i <= q; i++) {
        cin >> l >> r;
        ans = 0, r--;
        for (ll j = l; j <= r; j++) {
            num[j] = 1;
        }
        for (ll j = l; j <= r; j++) {
            if (nxt[j] <= r && nxt[j] != 0) {
                ans += a[j] * (nxt[j] - j) * num[j];
                num[nxt[j]] += num[j];
                //cout << a[j] * (nxt[j] - j) * num[j] << endl;
            } else {
                ans += a[j] * (r - j + 1) * num[j];
                //cout << a[j] * (r - j + 1) * num[j] << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
10 3
1 5 2 9 1 3 4 2 1 7
3 8
7 10
1 9

7 1
5 7 7 4 6 6 2
1 7

 */
