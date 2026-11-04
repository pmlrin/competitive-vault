#include <iostream>
using namespace std;
double Division(double a, double b) {
    if (b == 0)
        throw "除数为0";
    else
        return a / b;
}
int main(void) {
    try {
        double a = 1, b = 0;
        cout << "a/b" << Division(a, b) << endl;
    } catch (const runtime_error &e) {
        cout << "异常信息:" << e.what() << endl;
    } catch (char const *str) {
        cout << "异常信息:" << str << endl;
    }
    system("PAUSE");
    return 0;
}