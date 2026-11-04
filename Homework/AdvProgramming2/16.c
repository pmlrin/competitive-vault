#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", gcd(a, b));
    return 0;
}