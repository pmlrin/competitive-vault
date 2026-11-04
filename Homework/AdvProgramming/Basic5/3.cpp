#include <iostream>
using namespace std;

class Base {
  protected:
    int m;

  public:
    Base(int a) : m(a) {}
    virtual void Show() { cout << m << endl; }
};

class Derived : public Base {
  private:
    int n;

  public:
    Derived(int a, int b) : Base(a), n(b) {}
    void Show() {
        cout << n << ", ";
        Base::Show();
    }
};

int main() {
    Base *p;
    Base obj1(168);
    p = &obj1;
    p->Show();
    Derived obj2(158, 158);
    p = &obj2;
    p->Show();
    // 强制调用基类的Show
    p->Base::Show();
    return 0;
}