#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 400000 + 50;

ll n, a[N], minn, maxx, cur = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    minn = a[1];
    maxx = 0;
    for (ll i = 1; i <= n; i++) {
        minn = min(minn, a[i]);
        a[n + i] = a[i];
    }
    for (ll i = 1; i <= 2 * n; i++) {
        if (a[i] == minn) {
            maxx = max(maxx, cur);
            cur = 0;
        } else
            cur++;
    }
    cout << minn * n + maxx << endl;
    return 0;
}
