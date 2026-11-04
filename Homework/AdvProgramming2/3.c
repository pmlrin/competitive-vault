#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    double a = (212 - 32) * 1.0 / 100, b = 32;
    ll y;
    scanf("%lld", &y);
    printf("%lld\n", (ll)((y - b) / a));
    return 0;
}