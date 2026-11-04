#include <iostream>
using namespace std;

class Complex {
  private:
    double realPart;
    double imagPart;

  public:
    Complex(double real = 0, double imag = 0)
        : realPart(real), imagPart(imag) {}

    double GetRealPart() const { return realPart; }
    double GetImagPart() const { return imagPart; }

    friend ostream &operator<<(ostream &os, const Complex &c);
};

ostream &operator<<(ostream &os, const Complex &c) {
    if (c.imagPart == 0) {
        os << c.realPart;
    } else if (c.imagPart > 0) {
        os << c.realPart << "+" << c.imagPart << "i";
    } else {
        os << c.realPart << c.imagPart << "i";
    }
    return os;
}

int main() {
    Complex c1(5, 8);
    Complex c2(5, -8);
    Complex c3(5);

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;

    return 0;
}
