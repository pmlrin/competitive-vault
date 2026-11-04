#include <math.h>
#include <stdio.h>

int main() {
    int n;
    double x, ans = 0;
    scanf("%d %lf", &n, &x);
    for (int i = 1; i <= n; i++) {
        double a;
        int k;
        scanf("%lf %d", &a, &k);
        ans += a * pow(x, k);
    }
    printf("%.2lf\n", ans);
    return 0;
}