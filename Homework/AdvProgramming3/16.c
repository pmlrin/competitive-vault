#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    double x, eps;
    scanf("%lf %lf", &x, &eps);
    if (-eps <= x && x <= eps) {
        printf("0\n");
    } else if (x > eps) {
        printf("1\n");
    } else {
        printf("-1\n");
    }
    return 0;
}