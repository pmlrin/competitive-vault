#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

ll check(ll mid) {
    ll ret = 0, tmp;
    cout << "1 1 " << mid << endl;
    cin >> tmp;
    ret -= tmp;
    cout << "2 1 " << mid << endl;
    cin >> tmp;
    ret += tmp;
    return ret;
}

void solve() {
    ll n;
    cin >> n;
    ll L = 1, R = n;
    ll ansl = 1, ansr = n, pos = 0, val = 0;
    ll maxx = check(n);

    while (L <= R) {
        ll mid = (L + R) / 2;
        ll ch = check(mid);
        if (ch == 0) {
            L = mid + 1;
            pos = mid;
            val = ch;
        } else if (ch == maxx) {
            R = mid - 1;
            pos = mid;
            val = ch;
        } else {
            pos = mid;
            val = ch;
            break;
        }
    }
    ansl = pos - val + 1;
    ansr = ansl + maxx - 1;

    cout << "! " << ansl << " " << ansr << endl;
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
3
3 1 2
2 2
4
2 1 3 4
2 4

3 1 2
3 2 2

2 1 3 4
2 2 4 5
 */
