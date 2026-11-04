#include <stdio.h>
#include <string.h>

/**
 * 评测环境已经实现了划分函数，你只需且必须调用该函数完成数组划分。
 * 待划分的区间起始位置b、结束位置e。区间为左闭右开，不含右端元素。
 * 返回划分后的枢轴位置。若区间为空或无效，返回结束位置e。
 */
int *partition(int *b, int *e) {
    int p = *b;
    e--;
    while (b < e) {
        while (b < e && *e >= p)
            e--;
        *b = *e;
        while (b < e && *b <= p)
            b++;
        *e = *b;
    }
    *b = p;
    return b;
}

/**
 * 对整型区间[b, e)实现快速排序算法。区间为左闭右开，不含右端点。
 * 指针b为区间开始位置，指针e为区间结束位置。
 */
void quicksort(int *b, int *e) {
    if (e - b <= 1) {
        return;
    }
    int *mid = partition(b, e);
    quicksort(b, mid);
    quicksort(mid + 1, e);
}

int main() {
    int a[] = {9, 3, 5, 2, 5, 6};
    quicksort(a, a + 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}