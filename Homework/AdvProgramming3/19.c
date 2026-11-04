#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    unsigned long long T, x, a, b;
    scanf("%llu", &T);
    while (T--) {
        scanf("%llu", &x);
        if (x == 0) {
            printf("fib(%llu)=%llu\n", x, 0);
        } else if (x <= 2) {
            printf("fib(%llu)=%llu\n", x, 1);
        } else {
            a = b = 1;
            for (ll i = 3; i <= x; i++) {
                ll t = a + b;
                b = a;
                a = t;
            }
            printf("fib(%llu)=%llu\n", x, a);
        }
    }
    return 0;
}