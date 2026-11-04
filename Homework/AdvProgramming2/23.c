#include <stdio.h>
#include <string.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll d, cnt = 0;
    scanf("%lld", &d);
    char s[110] = {};
    while (scanf("%s", s) != EOF) {
        ll len = strlen(s);
        for (ll i = 0; i <= len - 1; i++) {
            if (cnt % 5 == 0 && cnt != 0) {
                printf(" ");
            }
            printf("%c", (s[i] - 'A' + d) % 26 + 'A');
            cnt++;
        }
    }
    printf("\n");
    return 0;
}