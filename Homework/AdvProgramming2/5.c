#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld %lld\n", (4 * a - b) / 2, (b - 2 * a) / 2);
    return 0;
}