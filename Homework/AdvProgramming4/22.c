#include <stdio.h>
#include <string.h>

/**
 * 串s仅含大小写字母。删除有序串s中的重复字符，但保持原有字符顺序。
 * 返回：处理后的串长度。
 */
int unique_chars(char *s) {
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
    return j;
}

int main() {}