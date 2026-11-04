#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

ll n, k, a[N], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ans = a[n / 2 + 1];
    for (ll i = n / 2 + 1; i <= n - 1; i++) {
        while (a[i] == a[i + 1] && i + 1 <= n)
            i++;
        if (i >= n)
            break;
        ll need = a[i + 1] - ans;
        ll len = i - n / 2;
        ll serv = k / len;
        if (serv >= need) {
            k -= need * len;
            ans += need;
        } else {
            k = 0;
            ans += serv;
            break;
        }
    }
    if (k == 0)
        cout << ans << endl;
    else
        cout << ans + k / (n / 2 + 1) << endl;
    return 0;
}

/*
5 3
1 2 3 4 5
 */
