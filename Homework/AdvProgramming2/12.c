#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    ll num[10] = {}, top = 1;
    char op[10] = {};
    scanf("%lld", num);
    while (scanf(" %c %lld", op + top, num + top) != EOF) {
        if (op[top] == '*') {
            num[top - 1] *= num[top];
            top--;
        } else if (op[top] == '/') {
            num[top - 1] /= num[top];
            top--;
        } else if (op[top] == '%') {
            num[top - 1] %= num[top];
            top--;
        }
        top++;
    }
    top--;
    for (ll i = 1; i <= top; i++) {
        if (op[i] == '+') {
            num[0] += num[i];
        } else {
            num[0] -= num[i];
        }
    }
    printf("%lld\n", num[0]);
    return 0;
}