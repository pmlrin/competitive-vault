#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    for (int t; scanf("%d", &t) != EOF;) {
        char a[20];
        int len = 0, flag = 1, num = t;
        while (num) {
            a[len++] = num % 10 + '0';
            num /= 10;
        }
        a[len] = '\0';
        for (int L = 0, R = len - 1; L <= R; L++, R--) {
            if (a[L] != a[R]) {
                flag = 0;
                break;
            }
        }
        printf("%d %d\n", flag, t);
    }
    return 0;
}