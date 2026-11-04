#include <stdio.h>

int main() {
    int a[200], n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 2; i <= n; i++) {
        int t = a[i], pos = i;
        for (int j = 1; j < i; j++) {
            if (a[j] > t) {
                pos = j;
                break;
            }
        }
        for (int j = i; j > pos; j--) {
            a[j] = a[j - 1];
        }
        a[pos] = t;
        for (int j = 1; j <= n; j++) {
            printf("%d", a[j]);
            if (j < n) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
}