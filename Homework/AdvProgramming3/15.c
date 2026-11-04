#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll x;
    scanf("%lld", &x);
    if ((x % 100 == 0 && x % 400 == 0) || (x % 100 && x % 4 == 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}