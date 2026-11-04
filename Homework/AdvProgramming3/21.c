#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll a, b, c, ret = 1;
    scanf("%lld%lld%lld", &a, &b, &c);
    while (b) {
        if (b % 2) {
            ret = ret * a % c;
        }
        a = a * a % c;
        b /= 2;
    }
    printf("%lld\n", ret % c);
    return 0;
}