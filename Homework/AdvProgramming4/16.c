#include <stdio.h>

int main() {
    long long N, S, T, d[100] = {};
    scanf("%lld%lld%lld", &N, &S, &T);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", d + i);
    }
    for (int i = N - 1; i >= 1; i--) {
        d[i] *= d[i + 1];
    }
    d[N + 1] = 1;
    for (int i = 1; i <= T; i++) {
        long long ans = 0;
        for (int j = 1, a; j <= N; j++) {
            scanf("%d", &a);
            ans += a * d[j + 1];
        }
        printf("%lld\n", ans * S);
    }
}