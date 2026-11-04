#include <stdio.h>

// 评测环境提供了以下三个函数，无需定义或实现。
// 你只需且必须调用这三个函数实现功能，否则会判为WA或RE。

// 交换数组a在下标i和j处的两个元素。
void swap_elements(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

// 返回数组a的[beg, end)区间内的最小元素首次出现的下标（索引）
int min_element(const int arr[], int beg, int end) {
    if (beg >= end) {
        return end;
    }
    int pos = beg, min = arr[beg];
    for (int i = beg; i < end; i++) {
        if (arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

// 该函数实现了题目要求的输出格式，直接调用即可。
void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
 * 按照题目要求实现“选择排序”，将数组a重排为升序。
 * 评测环境已经定义数组并填充数据，你只需使用即可。
 */
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos = min_element(a, i, n);
        swap_elements(a, i, pos);
        print(a, n);
    }
}

int main() {
    int a[] = {5, 1, 4, 2, 3};
    selection_sort(a, 5);
}