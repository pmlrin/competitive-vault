#include <stdio.h>
typedef long long ll;
const ll inf = 1e12 + 39;

const ll val[] = {0, 36000, 108000, 156000, 120000, 240000, 300000, inf};
const ll per[] = {0, 3, 10, 20, 25, 30, 35, 45};

ll min(ll a, ll b) { return a > b ? b : a; }
ll max(ll a, ll b) { return a > b ? a : b; }

int main() {
    ll T;
    scanf("%lld", &T);
    while (T--) {
        ll P, D, F, ans = 0;
        scanf("%lld%lld%lld", &P, &D, &F);
        P = max(P - 60000 - D, 0);
        for (ll i = 1; i <= 7; i++) {
            if (P <= 0) {
                break;
            }
            ans += min(P, val[i]) * per[i] / 100;
            P -= val[i];
        }
        ans = max(0, ans - F);
        printf("%lld\n", ans);
    }
    return 0;
}