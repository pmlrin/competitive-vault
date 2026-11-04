#include <math.h>
#include <stdio.h>
typedef long long ll;

const ll inf = 1e5 + 10;
ll n, ans = 0;

int main() {
    scanf("%lld", &n);
    for (ll i = 0; i <= n / 3; i++) {
        ll cnt = n - i * 3, ned = n - i;
        if (2 * cnt - ned >= 0 && (2 * cnt - ned) % 3 == 0) {
            ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}