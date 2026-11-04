#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    char c;
    ll n;
    scanf("%c %lld", &c, &n);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n * 2 + 1; j++) {
            if (n - j == i - 1 || j - n == i - 1) {
                printf("%c", c);
            } else if (j < n + i - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (ll i = n - 1; i >= 1; i--) {
        for (ll j = 1; j <= n * 2 + 1; j++) {
            if (n - j == i - 1 || j - n == i - 1) {
                printf("%c", c);
            } else if (j < n + i - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}