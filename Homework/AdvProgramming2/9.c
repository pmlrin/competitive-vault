#include <stdio.h>
typedef long long ll;
const ll N = 1e12 + 39;

int main() {
    char c, b[300] = {};
    scanf("%c", &c);
    b['A'] = b['E'] = b['I'] = b['O'] = b['U'] = 1;
    if (c >= 'A' && c <= 'Z') {
        if (b[c]) {
            printf("V\n");
        } else {
            printf("C\n");
        }
    } else if (c >= 'a' && c <= 'z') {
        if (b[c - 'a' + 'A']) {
            printf("v\n");
        } else {
            printf("c\n");
        }
    } else if (c >= '0' && c <= '9') {
        if ((c - '0') % 2) {
            printf("O\n");
        } else {
            printf("E\n");
        }
    } else {
        printf("S\n");
    }
    return 0;
}