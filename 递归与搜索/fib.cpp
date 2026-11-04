#include <stdio.h>

int main() {
    long long x, a[100];
    scanf("%lld", &x);
    if (x == 0) {
        printf("0\n");
        return 0;
    }
    if (x <= 2) {
        printf("1\n");
        return 0;
    }
    a[1] = a[2] = 1;
    for (int i = 3; i <= x; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    printf("%lld\n", a[x]);
    return 0;
}