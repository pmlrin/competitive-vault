#include <stdio.h>
#include <stdlib.h>

int main() {
    int ans = 1, a, b;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= b; i++) {
        ans *= a;
    }
    printf("%d\n", ans);
}