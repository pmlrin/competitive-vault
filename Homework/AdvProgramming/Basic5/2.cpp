#include <iostream>
using namespace std;

class Base {
  public:
    virtual void Show() { cout << "调用 Base:Show()" << endl; }
};

class Derived : public Base {
  public:
    void Show() override { cout << "调用 Derived:Show()" << endl; }
};

void Refers(Base &obj) { obj.Show(); }

int main() {
    Base obj1;
    Refers(obj1);
    Derived obj2;
    Refers(obj2);
    return 0;
}