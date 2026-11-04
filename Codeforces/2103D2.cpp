#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

ll n, a[N], ans[N];

ll nxt(ll x, ll cur) {
    for (ll i = x + 1; i <= n; i++) {
        if (a[i] < cur)
            continue;
        if (a[i] > cur)
            return -i;
        if (a[i] == cur)
            return i;
    }
    return 0;
}

ll pre(ll x, ll cur) {
    for (ll i = x - 1; i >= 1; i--) {
        if (a[i] < cur)
            continue;
        if (a[i] > cur)
            return -i;
        if (a[i] == cur)
            return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        ll m = 0, l = 1, r = n;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            m = max(m, a[i]);
            ans[i] = 0;
        }
        for (ll i = 1; i <= n; i++) {
            if (a[i] == -1)
                a[i] = m + 1;
        }
        for (ll i = 1; i <= m + 1; i++) {
            ll j = 0, flag = 1;
            if (a[j] != i)
                j = nxt(j, i);
            for (; j > 0; j = nxt(j, i)) {
                if (ans[j])
                    break;
                if (i % 2)
                    ans[j] = r--;
                else
                    ans[j] = l++;
            }
            j = n;
            if (a[j] != i)
                j = pre(j, i);
            while (flag) {
                for (; j > 0; j = pre(j, i)) {
                    if (ans[j]) {
                        flag = 0;
                        break;
                    }
                    if (i % 2)
                        ans[j] = r--;
                    else
                        ans[j] = l++;
                }
                if (j == 0)
                    break;
                j = pre(-j, i);
            }
        }
        for (ll i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}

/*
1
6
1 3 1 2 1 -1

1
5
1 -1 1 2 1

1
8
3 1 2 1 -1 1 1 2

1
111
1 3 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 6 1 2 1 3 1 2 1 4 1 2 1 3 1  2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 -1 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1  2 1 4 1 2 1 1 1

*/
