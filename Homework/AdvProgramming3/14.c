#include <math.h>
#include <stdio.h>
typedef long long ll;

const ll val[] = {0, 1, 2, 5, 10, 20, 50, 100};

int main() {
    ll T;
    scanf("%lld", &T);
    while (T--) {
        ll m, ans = 0;
        scanf("%lld", &m);
        for (ll i = 7; i >= 1; i--) {
            ans += m / val[i];
            m -= m / val[i] * val[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}