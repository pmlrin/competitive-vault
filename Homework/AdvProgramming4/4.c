#include <stdio.h>

/*
 * 将数组`a`区间`[b, e)`内的元素首尾反转，区间外的元素保持不变。
 */
void reverse_array(int a[], int b, int e) {
    for (int i = 1; i <= (e - b) / 2; i++) {
        int t = a[b + i - 1];
        a[b + i - 1] = a[e - i];
        a[e - i] = t;
    }
}

int main() {
    int a[] = {20, 50, 20, 30};
    reverse_array(a, 0, 4);
    for (int i = 0; i <= 3; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}