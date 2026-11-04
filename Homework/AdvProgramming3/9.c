#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return a > b ? b : a; }

int main() {
    int x, y, ans = 10;
    scanf("%d%d", &x, &y);
    x -= 3;
    if (x > 0) {
        ans += min(x, 7) * 2;
        x -= 7;
        if (x > 0) {
            ans += x * 3;
        }
    }
    ans += y / 5 * 2;
    printf("%d\n", ans);
    return 0;
}