#include <stdio.h>
#include <string.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    char c[1100];
    scanf("%s", c);
    ll len = strlen(c), a = 0, l = 0, u = 0, d = 0, s = 0;
    for (ll i = 0; i <= len - 1; i++) {
        if (c[i] >= 'A' && c[i] <= 'Z') {
            a++, u++;
        } else if (c[i] >= 'a' && c[i] <= 'z') {
            a++, l++;
        } else if (c[i] >= '0' && c[i] <= '9') {
            d++;
        } else {
            s++;
        }
    }
    printf("A:%lld\nU:%lld\nL:%lld\nD:%lld\nS:%lld\n", a, u, l, d, s);
    return 0;
}