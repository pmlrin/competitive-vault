#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 使用行程编码算法对串s进行压缩，结果从原地址开始保存。串s仅含大小写字母。
 * 返回：处理后的串长度。
 */
int run_length_encode(char *s) {
    int i = 0, j = 0, n = strlen(s);
    while (i < n) {
        char ch = s[i];
        int cnt = 0;
        while (i < n && s[i] == ch) {
            i++;
            cnt++;
        }
        if (cnt > 1) {
            char d[100];
            int t = 0;
            while (cnt > 0) {
                d[t++] = (char)('0' + cnt % 10);
                cnt /= 10;
            }
            while (t > 0) {
                s[j++] = d[--t];
            }
        }
        s[j++] = ch;
    }
    s[j] = '\0';
    return j;
}

int main() {
    char s[] = "AAcAAA";
    printf("%d\n", run_length_encode(s));
}