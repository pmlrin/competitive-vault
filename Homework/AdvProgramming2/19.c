#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll n;
    scanf("%lld", &n);
    for (ll i = 1, a, flag; i <= n; i++) {
        scanf("%lld", &a);
        flag = 1;
        for (ll j = 2; j * j <= a; j++) {
            if (a % j == 0) {
                flag = 0;
                break;
            }
        }
        if (a == 1) {
            flag = 0;
        }
        printf("%lld %lld\n", flag, a);
    }
    return 0;
}