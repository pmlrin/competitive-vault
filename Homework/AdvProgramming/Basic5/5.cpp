#include <iostream>
#include <vector>
using namespace std;

class Shape {
  public:
    static double sum;
    virtual void Show() = 0;
};

double Shape::sum = 0;

class Circle : public Shape {
  private:
    double r;

  public:
    Circle(double r) : r(r) { sum += 3.14159 * r * r; }
    void Show() { cout << "Circle area: " << 3.14159 * r * r << endl; }
};

class Rectangle : public Shape {
  private:
    double w, h;

  public:
    Rectangle(double w, double h) : w(w), h(h) { sum += w * h; }
    void Show() { cout << "Rectangle area: " << w * h << endl; }
};

int main() {
    vector<Shape *> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    for (auto p : shapes) {
        p->Show();
    }
    cout << "Total area: " << Shape::sum << endl;
    for (auto p : shapes) {
        delete p;
    }
    return 0;
}