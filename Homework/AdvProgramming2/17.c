#include <stdio.h>
typedef long long ll;
const ll N = 1e5 + 10, inf = 1e17;

int main() {
    for (ll n; scanf("%lld", &n) != EOF;) {
        ll ans = -inf, min = inf;
        for (ll i = 1, a; i <= n; i++) {
            scanf("%lld", &a);
            if (ans < a - min) {
                ans = a - min;
            }
            if (min > a) {
                min = a;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}