#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n, flag = 0;
    cin >> n;
    ll ans[n + 10];
    for (ll i = 2; i <= n - 1; i += 2) {
        ans[i] = i + 1;
        ans[i + 1] = i;
    }
    ans[n] = 1;
    if (n == 3) {
        cout << "2 1 3" << endl;
        return;
    } else if (n % 2 == 1) {
        ans[1] = n - 1;
        ans[n] = 1;
        flag = 1;
    } else {
        for (ll i = 1; i <= n; i++) {
            if (i % 2 == 0 && ((n ^ i) > (i + 1) || (n ^ i) == i) && (n ^ i) <= n) {
                ans[1] = ans[i];
                ans[i] = n;
                flag = 1;
                break;
            }
            if (i % 2 && (n ^ i) > i && (n ^ i) <= n) {
                ans[1] = ans[i];
                ans[i] = n;
                flag = 1;
                break;
            }
        }
    }
    if (flag) {
        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    cout << -1 << endl;
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
8
3
4
5
6
7
8
9
10
*/
