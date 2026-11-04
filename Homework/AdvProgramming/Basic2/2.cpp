#include <cmath>
#include <iostream>
using namespace std;

class Array_max {
  private:
    int array[10];
    int max;

  public:
    void set_value() {
        cout << "Please input 10 numbers" << endl;
        for (int i = 0; i < 10; i++) {
            cin >> array[i];
        }
    }
    void max_value() {
        max = array[0];
        for (int i = 1; i < 10; i++) {
            if (array[i] > max)
                max = array[i];
        }
    }
    void show_value() { cout << "max value: " << max << endl; }
};

int main() {
    Array_max arrmax;    // 定义对象 arrmax
    arrmax.set_value();  // 向数组元素输入数值
    arrmax.max_value();  // 找出数组元素中的最大值
    arrmax.show_value(); // 输出数组元素中的最大值
    return 0;
}