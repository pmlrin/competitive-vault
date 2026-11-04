#include <iostream>
using namespace std;

// 复数类
class Complex {
  private:
    double real; // 实部
    double imag; // 虚部

  public:
    // 构造函数
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 重载"+"运算符，实现复数加法
    Complex operator+(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // 重载"*"运算符，实现复数乘法
    // (a+bi)*(c+di) = (ac-bd)+(ad+bc)i
    Complex operator*(const Complex &c) const {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    // 友元函数：重载"<<"运算符，用于打印复数
    friend ostream &operator<<(ostream &os, const Complex &c);
};

// 重载"<<"运算符的实现
ostream &operator<<(ostream &os, const Complex &c) {
    if (c.imag >= 0)
        os << c.real << "+" << c.imag << "i";
    else
        os << c.real << c.imag << "i";
    return os;
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
