#include <stdio.h>

long long cnt = 0, ans[100];

long long f(int x) {
    cnt++;
    if (ans[x]) {
        return ans[x];
    }
    if (x <= 0) {
        return ans[x] = 0;
    }
    if (x <= 2) {
        return ans[x] = 1;
    }
    return ans[x] = f(x - 1) + f(x - 2);
}

int main() {
    long long x;
    scanf("%lld", &x);
    printf("%lld\n", f(x));
    printf("%lld\n", cnt);
    return 0;
}