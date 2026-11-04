#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll n, ans = 0;
    scanf("%lld", &n);
    for (ll i = 1, a; i <= n; i++) {
        scanf("%lld", &a);
        ans += a;
        printf("%lld", ans);
        if (i == n) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}