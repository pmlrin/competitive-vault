#include <iostream>
using namespace std;
class Piont2D {
  public:
    int x;
    int y;
    Piont2D(int x = 0, int y = 0) : x(x), y(y) {
        cout << "调用Piont2D的构造函数" << endl;
    } //(1)
    operator int() const {
        cout << "调用Piont2D的类类型转换函数" << endl;
        return x + y;
    } //(2)
};
class Piont3D {
  public:
    int x;
    int y;
    int z;
    Piont3D(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {
        cout << "调用Piont3D的构造函数1" << endl;
    } //(1)
    Piont3D(Piont2D p) : x(p.x), y(p.y), z(0) {
        cout << "调用Piont3D的构造函数2" << endl;
    } //(2)
    operator Piont2D() const {
        cout << "调用Piont3D的类类型转换函数" << endl;
        return Piont2D(x, y);
    } //(3)
};
int main() {
    Piont2D p2D1 = 2;    // 调用Piont2D的构造函数
    Piont3D p3D1 = 3;    // 调用Piont3D的构造函数1
    int a = p2D1;        // 调用Piont2D的类类型转换函数
    Piont3D p3D2 = p2D1; // 调用Piont3D的构造函数2
    Piont2D p2D3 =
        p3D2; // 调用Piont3D的类类型转换函数，内部调用了Piont2D的构造函数
}