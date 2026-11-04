#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 对字符串s旋转k位，结果原地保存在s中。
 */
void rotate(char *s, int k) {
    int n = (int)strlen(s);
    if (n == 0) {
        return;
    }

    k %= n;
    if (k < 0) {
        k += n;
    }

    int left = 0, right = k - 1;
    while (left < right) {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }

    left = k;
    right = n - 1;
    while (left < right) {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }

    left = 0;
    right = n - 1;
    while (left < right) {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

int main() {
    char s[] = "ABCDE";
    rotate(s, 1);
    printf("%s\n", s);
}