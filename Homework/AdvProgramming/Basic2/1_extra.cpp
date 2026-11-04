#include <cmath>
#include <iostream>
using namespace std;

class Triangle {
  private:
    double a, b, c;

  public:
    void Set() {
        while (true) {
            cout << "Enter the sides of the triangle: ";
            cin >> a >> b >> c;
            double p = Perim() / 2;
            if (p <= a || p <= b || p <= c) {
                cout << "Invalid triangle sides." << endl;
            } else {
                break;
            }
        }
    }
    void Get(double &x, double &y, double &z) {
        x = a;
        y = b;
        z = c;
    }
    double Perim() { return a + b + c; }
    double Area() {
        double p = Perim() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    double a, b, c;
    Triangle tril;
    tril.Set();
    tril.Get(a, b, c);
    cout << "Sides: " << a << " " << b << " " << c << endl;
    cout << "Area: " << tril.Area() << endl;
    return 0;
}