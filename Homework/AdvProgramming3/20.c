#include <stdio.h>
#include <string.h>
typedef long long ll;
const ll N = 100 + 39;

int main() {
    ll T, n;
    char s[N];
    scanf("%lld", &T);
    while (T--) {
        scanf("%s", s);
        n = strlen(s);
        if (s[0] == '0' && n == 1) {
            printf("0\n");
            continue;
        }
        for (ll i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                n--;
            } else {
                break;
            }
        }
        for (ll i = n - 1; i >= 0; i--) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}