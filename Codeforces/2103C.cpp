#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

ll n, k, a[N];
ll nump[N], numn[N], maxp[N], maxn[N], minp[N], minn[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll ans = 0;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        nump[0] = numn[n + 1] = 0;
        maxp[0] = maxn[n + 1] = -inf;
        minp[0] = minn[n + 1] = inf;
        for (ll i = 1; i <= n; i++) {
            nump[i] = nump[i - 1];
            if (a[i] > k)
                nump[i]++;
            else
                nump[i]--;
            maxp[i] = max(maxp[i - 1], nump[i]);
            minp[i] = min(minp[i - 1], nump[i]);
        }
        for (ll i = n; i >= 1; i--) {
            numn[i] = numn[i + 1];
            if (a[i] > k)
                numn[i]++;
            else
                numn[i]--;
            maxn[i] = max(maxn[i + 1], numn[i]);
            minn[i] = min(minn[i + 1], numn[i]);
        }
        for (ll i = 1; i <= n - 2; i++) {
            if (minp[i] <= 0 && minn[i + 2] <= 0) {
                ans = 1;
                break;
            }
            if (nump[i] <= 0 && numn[i + 1] - maxn[i + 2] <= 0) {
                ans = 1;
                break;
            }
            if (nump[i + 1] - maxp[i] <= 0 && numn[i + 2] <= 0) {
                ans = 1;
                break;
            }
        }
        if (ans == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
