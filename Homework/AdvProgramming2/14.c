#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll n;
    scanf("%lld", &n);
    ll cnt = 0, max = n;
    while (n != 1) {
        cnt++;
        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        if (max < n) {
            max = n;
        }
    }
    printf("%lld %lld\n", cnt, max);
    return 0;
}