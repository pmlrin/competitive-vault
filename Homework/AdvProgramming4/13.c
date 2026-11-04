#include <stdio.h>

/*
 * 数组a、长度n。数组b、长度m。目标数组c。
 */
void merge_array(const int a[], const int n, const int b[], const int m,
                 int c[]) {
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
    while (pb < n) {
        c[pc++] = a[pb++];
    }
}

int main() {
    int a[] = {1, 5, 6}, b[] = {2, 3, 4, 6}, c[100];
    merge_array(a, 3, b, 4, c);
    for (int i = 0; i < 7; i++) {
        printf("%d ", c[i]);
    }
}