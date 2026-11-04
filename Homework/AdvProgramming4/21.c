#include <stdio.h>
#include <string.h>

/**
 * A、B为“行主序”存储的矩阵，乘积矩阵保存在C中。
 * m、n为矩阵A的行数、列数。
 * n、p为矩阵B的行数、列数。
 */
void matrix_mul(const int A[], const int B[], int C[], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < p; j++) {
                C[i * p + j] += A[i * n + k] * B[k * p + j];
            }
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int c[] = {0, 0, 0, 0, 0, 0};
    matrix_mul(a, b, c, 2, 4, 3);
    for (int i = 0; i < 6; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}