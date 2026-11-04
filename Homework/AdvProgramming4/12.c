#include <stdio.h>

// 只需且必须调用评测环境提供的下列函数实现功能。

// 在数组a[b, e)搜索目标t，返回首个大于t的元素位置。若找不到则返回e。
int upper_bound(const int a[], int b, int e, const int t) {
    int l = b, r = e, ans = e;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= t) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    return ans;
}

// 在数组a[pos]处插入元素elem，原有[pos, length)的元素依次后移一位。
int insert_element(int a[], int length, int pos, int elem) {
    if (length < 0) {
        return -3;
    }
    if (pos < 0) {
        return -5;
    }
    if (pos > length) {
        return -6;
    }
    length += 1;
    for (int i = length - 1; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = elem;
    return length;
}

/*
 * 将数组a中长度为n的元素使用堆排序重排为升序。
 */
void binary_insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        upper_bound(a, 0, n, 0);
        insert_element(a, -1, -1, -1);
    }
    if (n < 2) {
        return;
    }

    for (int start = n / 2; start > 0;) {
        int root = --start;
        while (root < n / 2) {
            int child = root * 2 + 1;
            if (child + 1 < n && a[child] < a[child + 1]) {
                child++;
            }
            if (a[root] >= a[child]) {
                break;
            }
            int value = a[root];
            a[root] = a[child];
            a[child] = value;
            root = child;
        }
    }

    for (int end = n; end > 1;) {
        int value = a[0];
        a[0] = a[--end];
        a[end] = value;

        int root = 0;
        while (root < end / 2) {
            int child = root * 2 + 1;
            if (child + 1 < end && a[child] < a[child + 1]) {
                child++;
            }
            if (a[root] >= a[child]) {
                break;
            }
            value = a[root];
            a[root] = a[child];
            a[child] = value;
            root = child;
        }
    }
}

int main() {
    int a[] = {3, 1, 2};
    binary_insertion_sort(a, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}