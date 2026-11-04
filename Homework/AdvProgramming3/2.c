#include <stdio.h>
#include <stdlib.h>

long long f[100];
long long fib(int n) {
    if (f[n])
        return f[n];
    if (n <= 0)
        return f[n] = 0;
    if (n <= 2)
        return f[n] = 1;
    return f[n] = fib(n - 1) + fib(n - 2);
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%lld\n", fib(x));
}