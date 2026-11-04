#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll n, t, a[100], cnt = 0;
    scanf("%lld", &n);
    t = n;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            a[++cnt] = i;
            n /= i;
        }
    }
    if (n) {
        a[++cnt] = n;
    }
    printf("%lld = %lld", t, a[1]);
    for (ll i = 2; i <= cnt; i++) {
        printf(" * %lld", a[i]);
    }
    printf("\n");
    return 0;
}