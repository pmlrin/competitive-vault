#include <stdio.h>
#include <string.h>

/**
 * 评测环境已经实现了归并函数，你需要调用该函数完成归并操作。
 * 数组a、长度n。数组b、长度m。归并到目标数组w。
 */
void merge(const int a[], const int n, const int b[], const int m, int c[]) {
    int pa = 0, pb = 0, pc = 0;
    while (pa < n && pb < m) {
        if (a[pa] < b[pb]) {
            c[pc++] = a[pa++];
        } else {
            c[pc++] = b[pb++];
        }
    }
    while (pa < n) {
        c[pc++] = a[pa++];
    }
    while (pb < m) {
        c[pc++] = a[pb++];
    }
}

/**
 * 对整型区间[b, e)进行归并排序。区间为左闭右开，不含右端点。
 * 指针b为区间开始位置，指针e为区间结束位置。
 * w[]为调用方提供的工作数组，容量保证不小于(e - b)。
 */
void merge_sort(int *b, int *e, int w[]) {
    if (e - b <= 1) {
        return;
    }
    int *mid = b + (e - b) / 2;
    merge_sort(b, mid, w);
    merge_sort(mid, e, w);
    merge(b, mid - b, mid, e - mid, w);
    for (int i = 0; i < e - b; i++) {
        b[i] = w[i];
    }
}

int main() {
    int a[] = {9, 3, 5, 2, 5, 6}, b[] = {0, 0, 0, 0, 0, 0};
    merge_sort(a, a + 6, b);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}