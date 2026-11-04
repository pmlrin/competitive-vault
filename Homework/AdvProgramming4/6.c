#include <stdio.h>

/*
 * 使用题面描述的“冒泡排序”算法，将长度为n的数组a重排为升序。
 */
void bubble_sort(int a[], int n) {
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                int t = a[i + 1];
                a[i + 1] = a[i];
                a[i] = t;
                flag = 1;
            }
        }
        if (flag) {
            for (int i = 0; i < n; i++) {
                if (i < n - 1) {
                    printf("%d ", a[i]);
                } else {
                    printf("%d\n", a[i]);
                }
            }
        }
    }
}

int main() {
    int a[] = {5, 1, 4, 2, 3};
    bubble_sort(a, 5);
}