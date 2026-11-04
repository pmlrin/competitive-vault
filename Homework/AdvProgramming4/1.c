#include <stdio.h>

/*
 * 交换数组a位于i和j处的两个元素。
 */
void swap_elements(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int main() {}