#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int max(int a, int b, int c) {
    if (max(a, b) > c)
        return max(a, b);
    return c;
}

int main() {
    int a = 8, b = -12, c = 27;
    cout << max(a, b, c) << endl;
    // 输出3个整数中的最大者
    cout << max(a, b) << endl;
    // 输出两个整数中的最大者
    return 0;
}
