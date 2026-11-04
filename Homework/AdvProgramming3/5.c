#include <stdio.h>
#include <stdlib.h>

int main() {
    int d, a, b, ans = 0;
    scanf("%d%d%d", &d, &a, &b);
    if (a == 0 && d == 0) {
        ans++;
    }
    for (int i = a; i <= b; i++) {
        int tmp = i;
        while (tmp) {
            if (tmp % 10 == d) {
                ans++;
            }
            tmp /= 10;
        }
    }
    printf("%d\n", ans);
}