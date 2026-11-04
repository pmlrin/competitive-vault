#include <iostream>
using namespace std;

int Max(int x, int y) { return x > y ? x : y; }
long Max(long x, long y) { return x > y ? x : y; }
double Max(double x, double y) { return x > y ? x : y; }

int main() {
    double d = Max(1.8, 2.3);
    long b = Max(1, 2);
    cout << "double 类型的 d 值为: " << d << endl;
    cout << "long 类型的 b 值为: " << b << endl;
    system("PAUSE");
    return 0;
}