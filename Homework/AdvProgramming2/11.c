#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

void swap(ll *a, ll *b) {
    ll t = *b;
    *b = *a;
    *a = t;
}

int main() {
    ll len[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ll y, m1, d1, m2, d2;
    scanf("%lld %lld %lld %lld %lld", &y, &m1, &d1, &m2, &d2);
    if ((y % 100 == 0 && y % 400 == 0) || (y % 100 && y % 4 == 0)) {
        len[2]++;
    }
    if (m1 == m2) {
        printf("%lld\n", abs(d1 - d2));
        return 0;
    }
    if (m1 > m2) {
        swap(&m1, &m2);
        swap(&d1, &d2);
    }
    ll ans = len[m1] - d1;
    for (ll i = m1 + 1; i < m2; i++) {
        ans += len[i];
    }
    printf("%lld\n", ans + d2);
    return 0;
}