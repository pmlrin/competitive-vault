#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    ll stk[n + 10] = {}, top = 0, cnt = 0, num;
    PII ans[n + 10];
    for (ll i = 1; i <= n - 3; i++) {
        cout << "? 1 " << i + 2 << endl;
        cin >> num;
        while (top < num) {
            stk[++top] = i + 1;
        }
        while (top > num) {
            ans[++cnt] = {stk[top], i + 2};
            top--;
        }
        if (num == 0) {
            ans[++cnt] = {1, i + 2};
        }
    }
    while (top > 0) {
        ans[++cnt] = {stk[top], n};
        top--;
    }
    cout << "! ";
    for (ll i = 1; i <= n - 3; i++) {
        cout << ans[i].first << " " << ans[i].second << " ";
    }
    cout << endl;
    cin >> num;
}

int main() {
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
