#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 150000 + 50, inf = 1145141919810;

ll n, a[N], sum = 0, max1 = -inf, min1 = inf;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 0) {
            sum += a[i];
            if (a[i] % 2 == 1)
                min1 = min(min1, a[i]);
        }
        if (a[i] < 0 && (a[i] % 2 + 2) % 2 == 1)
            max1 = max(max1, a[i]);
    }
    if (sum % 2)
        cout << sum << endl;
    else
        cout << max(sum + max1, sum - min1) << endl;
    return 0;
}
