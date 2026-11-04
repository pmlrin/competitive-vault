#include <iostream>
using namespace std;

// 数组类
class Array {
  private:
    // 数据成员:
    int *elem; // 数组元素存储空间
    int size;  // 数组元素个数
  public:
    // 公有函数：
    Array(int a[], int sz) : elem(a), size(sz) {} // 构造函数

    int GetSize() // 返回数组元素个数
    {
        return size;
    }

    int &operator[](int pos) // 重载下标运算符[]
    {
        return elem[pos - 1];
    }
};

int main(void) // 主函数
{
    int a[] = {1, 2, 3, 4, 5}; // 定义数组a
    Array obj(a, 5);           // 定义数组对象
    obj[1] = 8;                // 为数组元素赋值

    for (int i = 1; i <= obj.GetSize(); i++) // 依次输出数组各元素之值
        cout << obj[i] << " ";               // 输出第i个元素

    cout << endl;    // 换行
    system("PAUSE"); // 调用库函数system()，输出系统提示信息
    return 0;        // 返回值0，返回操作系统
}
