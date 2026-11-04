#include <iostream>
using namespace std;

// 计算器类
class Calculator {
  public:
    // 函数重载：整数加法
    int add(int a, int b) { return a + b; }

    // 函数重载：浮点数加法
    double add(double a, double b) { return a + b; }

    // 整数乘法
    int multiply(int a, int b) { return a * b; }
};

int main() {
    Calculator calc;
    cout << "Add integers: " << calc.add(3, 4) << endl;
    cout << "Add doubles: " << calc.add(3.5, 4.5) << endl;
    cout << "Multiply integers: " << calc.multiply(3, 4) << endl;
    return 0;
}
