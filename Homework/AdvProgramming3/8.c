#include <stdio.h>
#include <stdlib.h>

int main() {
    double ans = 0;
    for (int i = 1; i <= 12; i++) {
        double val;
        scanf("%lf", &val);
        if (val <= 210)
            ans += val * 0.5469;
        else if (val <= 400)
            ans += val * 0.5969;
        else
            ans += val * 0.8469;
    }
    printf("%.2lf\n", ans);
    return 0;
}