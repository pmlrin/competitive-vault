#include <stdio.h>

/*
 * 从数组arr的[beg, end)区间搜索最小元素，返回首个最小元素的下标。
 * 若区间为空则返回结束位置end。
 */
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

int main() {}