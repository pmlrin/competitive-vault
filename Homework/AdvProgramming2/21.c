#include <stdio.h>
#include <stdlib.h>
typedef int ll;
const ll inf = 1e9;

ll check(ll x) {
    ll a = x % 10, b = x / 10 % 10, c = x / 100;
    a = a * a * a;
    b = b * b * b;
    c = c * c * c;
    if (a + b + c == x) {
        return 1;
    }
    return 0;
}

int main() {
    ll n, ans = 0, dis = inf;
    scanf("%d", &n);
    for (ll i = 100; i <= 999; i++) {
        if (check(i) && abs(n - i) < dis) {
            dis = abs(n - i);
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}