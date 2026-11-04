#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll ans;
    scanf("%lld", &ans);
    for (ll i = 2, a; i <= 5; i++) {
        scanf("%lld", &a);
        if (a > ans) {
            ans = a;
        }
    }
    printf("%lld\n", ans);
    return 0;
}