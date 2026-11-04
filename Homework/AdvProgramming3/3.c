#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    scanf("%d:%d %d:%d", &a, &b, &c, &d);
    int tim = (a * 60 + b + c * 60 + d) % (24 * 60);
    printf("%02d:%02d\n", tim / 60, tim % 60);
}