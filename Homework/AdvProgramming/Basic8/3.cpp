#include <iostream>
using namespace std;
double Division(double a, double b) {
    if (b == 0)
        throw runtime_error("除数为 0!");
    else
        return a / b;
}
int main(void) {
    try {
        double a = 1, b = 0;
        cout << "a/b" << Division(a, b) << endl;
    } catch (...) {
        cout << "异常信息:" << endl;
    } catch (const runtime_error &e) {
        cout << "异常信息:" << e.what() << endl;
    } catch (char const *str) {
        cout << "异常信息:" << str << endl;
    }
    system("PAUSE");
    return 0;
}