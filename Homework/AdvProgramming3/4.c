#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", a / gcd(a, b) * b);
}