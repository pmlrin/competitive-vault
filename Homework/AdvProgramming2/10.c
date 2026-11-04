#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll a[10];
    char b[10] = {0, 'Q', 'S', 'M', 'J', 'C'};
    for (ll i = 1; i <= 5; i++) {
        scanf("%lld", a + i);
    }
    for (ll i = 1; i <= 4; i++) {
        for (ll j = 1; j <= 5 - i; j++) {
            if (a[j] < a[j + 1]) {
                ll ta = a[j];
                char tb = b[j];
                a[j] = a[j + 1];
                b[j] = b[j + 1];
                a[j + 1] = ta;
                b[j + 1] = tb;
            }
        }
    }
    for (ll i = 1; i <= 5; i++) {
        printf("%c", b[i]);
        if (i == 5) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    return 0;
}