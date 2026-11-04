#include <stdio.h>

/*
 * 数组arr、有效长度length，删除pos位置的元素，后续元素依次前移。
 * 返回值参考题面要求。
 */
int remove_element(int a[], int length, int pos) {
    if (length <= 0) {
        return -2;
    }
    if (pos < 0) {
        return -3;
    }
    if (pos >= length) {
        return -4;
    }
    length--;
    for (int i = pos; i < length; i++) {
        a[i] = a[i + 1];
    }
    return length;
}

int main() {
    int a[] = {0, 0};
    printf("%d\n", remove_element(a, 0, 99));
    printf("%d\n", remove_element(a, 3, -1));
    printf("%d\n", remove_element(a, 99999, 99999));
    printf("%d\n", remove_element(a, 3, 1));
}