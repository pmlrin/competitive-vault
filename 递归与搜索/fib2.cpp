#include <stdio.h>

long long cnt = 0;

long long f(int x) {
    cnt++;
    if (x <= 0) {
        return 0;
    }
    if (x <= 2) {
        return 1;
    }
    return f(x - 1) + f(x - 2);
}

int main() {
    long long x;
    scanf("%lld", &x);
    printf("%lld\n", f(x));
    printf("%lld\n", cnt);
    return 0;
}