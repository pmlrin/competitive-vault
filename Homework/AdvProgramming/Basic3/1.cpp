#include<iostream>
using namespace std;

class A {
public:
    A() { cout << "构造 A" << endl; }
    ~A() { cout << "析构 A" << endl; }
};

class B : public A {
public:
    B() { cout << "构造 B" << endl; }
    ~B() { cout << "析构 B" << endl; }
};

class C : public B {
public:
    C() { cout << "构造 C" << endl; }
    ~C() { cout << "析构 C" << endl; }
};

int main(void) {
    C obj;
    system("PAUSE");
    return 0;
}
