#include <math.h>
#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        double a, b, c, p = 0;
        scanf("%lf%lf%lf", &a, &b, &c);
        p = (a + b + c) / 2;
        if (p - a <= 0 || p - b <= 0 || p - c <= 0) {
            printf("-1\n");
        } else {
            double s = sqrt(p * (p - a) * (p - b) * (p - c));
            printf("%.2lf\n", s);
        }
    }
    return 0;
}