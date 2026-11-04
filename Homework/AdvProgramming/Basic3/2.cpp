#include <iostream>
using namespace std;

class A {
  protected:
    int a;

  public:
    A(int x) : a(x) {}
    void show() const { cout << a << endl; }
};

class B {
  protected:
    int b;

  public:
    B(int x) : b(x) {}
    void Show() const { cout << b << endl; }
};

class C : public A, public B {
  public:
    C(int x, int y) : A(x), B(y) {}
    void Show() const { cout << a << "," << b << endl; }
};

int main(void) {
    C obj(5, 18);
    obj.Show();
    obj.A::show();
    obj.B::Show();
    system("PAUSE");
    return 0;
}