#include <math.h>
#include <stdio.h>

double len(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    double x1, x2, x3, y1, y2, y3, l1, l2, l3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
    l1 = len(x1, y1, x2, y2);
    l2 = len(x1, y1, x3, y3);
    l3 = len(x2, y2, x3, y3);
    double p = (l1 + l2 + l3) / 2;
    if (p - l1 > 0 && p - l2 > 0 && p - l3 > 0) {
        printf("%.2lf %.2lf\n", l1 + l2 + l3,
               sqrt(p * (p - l1) * (p - l2) * (p - l3)));
    } else {
        printf("-1 -1\n");
    }
    return 0;
}