#include <stdio.h>
typedef long long ll;
const ll inf = 1e17;

const ll val[] = {0, 36000, 108000, 156000, 120000, 240000, 300000, inf};
const ll per[] = {0, 3, 10, 20, 25, 30, 35, 45};

ll min(ll a, ll b) { return a > b ? b : a; }
ll max(ll a, ll b) { return a > b ? a : b; }
ll calc(ll P) {
    ll ans = 0;
    P = max(P - 60000, 0);
    for (ll i = 1; i <= 7; i++) {
        if (P <= 0) {
            break;
        }
        ans += min(P, val[i]) * per[i] / 100;
        P -= val[i];
    }
    return ans;
}

int main() {
    ll x, ans;
    scanf("%lld", &x);
    ll l = 0, r = inf;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (calc(mid) > x) {
            r = mid - 1;
        } else if (calc(mid) < x) {
            l = mid + 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}