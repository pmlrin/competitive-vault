#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    return a;
}

double max(double a, double b, double c) {
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    return a;
}

int main() {
    int i1 = 185, i2 = -76, i3 = 567, i;
    double d1 = 56.87, d2 = 90.23, d3 = -3214.78, d;
    i = max(i1, i2, i3); // 调用模板函数时VT被 int 取代
    d = max(d1, d2, d3); // 调用模板函数时VT被 double 取代
    cout << "i_max=" << i << endl;
    cout << "f_max=" << d << endl;
    return 0;
}
