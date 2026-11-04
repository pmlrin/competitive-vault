#include <stdio.h>

/*
 * 数组a、区间开始位置b、结束位置，目标值t。
 * 返回值参考题面要求。
 */
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

int main() {}