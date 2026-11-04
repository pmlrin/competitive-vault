#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll x;
    scanf("%lld", &x);
    printf("%lld\n", x * 365 * 24 * 60 * 60);
    return 0;
}