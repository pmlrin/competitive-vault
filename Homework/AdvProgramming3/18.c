#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

ll fac(ll x) {
    ll ans = 1;
    for (ll i = 1; i <= x; i++) {
        ans *= i;
    }
    return ans;
}

int main() {
    ll T, n, k;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld %lld", &n, &k);
        printf("%lld\n", fac(n) / fac(k) / fac(n - k));
    }
    return 0;
}