#include <stdio.h>

/**
 * 参考函数原型，补全并实现以下6个交换函数。
 */
void swap_char(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}
void swap_short(short *a, short *b) {
    short t = *a;
    *a = *b;
    *b = t;
}
void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void swap_long(long *a, long *b) {
    long t = *a;
    *a = *b;
    *b = t;
}
void swap_float(float *a, float *b) {
    float t = *a;
    *a = *b;
    *b = t;
}
void swap_double(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

int main() {}