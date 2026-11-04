#include <math.h>
#include <stdio.h>

const int inf = 1e5 + 10;

int main() {
    int n = 0, sum = 0, max = -inf, min = inf;
    int A = 0, B = 0, C = 0, D = 0, E = 0;
    while (true) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == -1) {
            break;
        }
        if (tmp >= 90) {
            A++;
        } else if (tmp >= 80) {
            B++;
        } else if (tmp >= 70) {
            C++;
        } else if (tmp >= 60) {
            D++;
        } else {
            E++;
        }
        n++;
        sum += tmp;
        if (tmp > max) {
            max = tmp;
        }
        if (tmp < min) {
            min = tmp;
        }
    }
    printf("%.1f %d %d %d %d %d %d %d\n", sum * 1.0 / n, max, min, A, B, C, D,
           E);
    return 0;
}