#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long T, a;
    scanf("%llu", &T);
    while (T--) {
        scanf("%llu", &a);
        if ((a & (a - 1)) == 0 && a != 0) {
            printf("Y %llu\n", a);
        } else {
            printf("N %llu\n", a);
        }
    }
}