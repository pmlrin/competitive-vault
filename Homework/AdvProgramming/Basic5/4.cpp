#include <iostream>
using namespace std;

class A {
  public:
    void Show(int x) { cout << "基类重载" << endl; }
    virtual void Show() { cout << "基类虚函数" << endl; }
};

class B : public A {
  public:
    void Show(int x) { cout << "派生类B的重载函数" << endl; }
    void Show() { cout << "派生类B的虚函数" << endl; }
};

int main() {
    B obj;
    obj.Show(10); // 调用派生类的重载
    obj.Show();   // 调用派生类的虚函数
    A *p = &obj;
    p->Show();   // 动态绑定，调用派生类的虚函数
    p->Show(10); // 静态绑定，调用基类的重载，因为重载不是虚的
    return 0;
}