#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17, mod = 998244353;

void solve() {
    string tmp;
    __int128 x = 0;
    cin >> tmp;
    ll len = tmp.size();
    for (ll i = 0; i <= len - 1; i++) {
        if (tmp[i] >= '0' && tmp[i] <= '9') {
            x = x * 10 + tmp[i] - '0';
        }
    }
    x *= 2;
    x -= 100;
    x *= 2;
    x -= 100;
    tmp.clear();
    ll cnt = 0;
    while (x) {
        tmp.push_back(x % 10 + '0');
        cnt++;
        if (cnt == 2) {
            tmp.push_back('.');
        }
        x /= 10;
    }
    for (auto i = tmp.rbegin(); i != tmp.rend(); ++i) {
        cout << *i;
    }
    cout << endl;
}
// 0 1 20 300 4000

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
3
3.75
111705.27
36028797018963968.01
*/
