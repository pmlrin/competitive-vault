#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll x, ans = 1;
    scanf("%lld", &x);
    for (ll i = 1; i <= x; i++) {
        ans *= i;
    }
    printf("%lld\n", ans);
    return 0;
}