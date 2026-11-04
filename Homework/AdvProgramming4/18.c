#include <stdio.h>
#include <string.h>

/**
 * 清理串s首尾两端的空格字符，结果串保存到s指向地址。
 */
void trim(char *const s) {
    int len = strlen(s);
    int L = 0, R = len - 1;
    while (L < len && s[L] == ' ') {
        L++;
    }
    while (R >= 0 && s[R] == ' ') {
        R--;
    }
    if (L > R) {
        s[0] = '\0';
        return;
    }
    for (int i = L; i <= R; i++) {
        s[i - L] = s[i];
    }
    s[R - L + 1] = '\0';
}

int main() {
    char a[] = " A B C  ";
    trim(a);
    printf("%s\n", a);
}