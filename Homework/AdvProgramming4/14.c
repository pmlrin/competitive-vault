#include <stdio.h>

/**
 * 数组a、起始位置b、结束位置e。
 * 待划分的区间是[b, e)，左闭右开区间，不包含右端点。
 */
int partition(int a[], int b, int e) {
    int p = a[b];
    int l = b, r = e - 1;
    while (l < r) {
        while (l < r && a[r] >= p)
            r--;
        a[l] = a[r];
        while (l < r && a[l] <= p)
            l++;
        a[r] = a[l];
    }
    a[l] = p;
    return l;
}

int main() {}