#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 150000 + 50;

ll n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n;
        ll a0 = 0, a1 = 0, ap1 = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 0)
                a0++;
            else if (a[i] == -1)
                ap1++;
            else
                a1++;
        }
        cout << a0 + (2 * (ap1 % 2)) << endl;
    }
    return 0;
}
