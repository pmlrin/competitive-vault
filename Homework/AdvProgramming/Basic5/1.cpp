#include <iostream>
using namespace std;

class Base {
  public:
    virtual void f() { cout << "调用 Base:f()" << endl; }
};

class Derived : public Base {
  public:
    void f() override { cout << "调用 Derived:f()" << endl; }
};

int main() {
    Derived obj;
    Base *p = &obj;
    p->f();
    return 0;
}