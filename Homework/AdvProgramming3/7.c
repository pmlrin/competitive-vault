#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        printf("%d", i % 10);
        for (int j = 1; j <= i * 2 - 3; j++) {
            printf(" ");
        }
        if (i > 1) {
            printf("%d", i % 10);
        }
        printf("\n");
    }
    for (int i = 1; i <= n * 2 - 1; i++) {
        printf("%d", n % 10);
    }
    printf("\n");
}