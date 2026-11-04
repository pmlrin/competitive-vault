#include "MyNameSpace.h"
#include <iostream>
int main() {
    // 方法1：使用命名空间名限定
    std::cout << "MyNameSpace::value = " << MyNameSpace::value << std::endl;
    MyNameSpace::print();

    // 方法2：using声明
    {
        using MyNameSpace::value;
        std::cout << "using MyNameSpace::value; value = " << value << std::endl;
    }

    // 方法3：using指令
    {
        using namespace MyNameSpace;
        std::cout << "using namespace MyNameSpace; value = " << value
                  << std::endl;
    }

    // ChildNamespace的三种方法
    // 方法1：完全限定
    std::cout << "MyNameSpace::ChildNamespace::value = "
              << MyNameSpace::ChildNamespace::value << std::endl;

    // 方法2：using声明
    {
        using MyNameSpace::ChildNamespace::value;
        std::cout << "using MyNameSpace::ChildNamespace::value; "
                     "value = "
                  << value << std::endl;
    }

    // 方法3：using指令
    {
        using namespace MyNameSpace::ChildNamespace;
        std::cout << "using namespace MyNameSpace::ChildNamespace; value = "
                  << value << std::endl;
    }

    // 同时使用两个value
    std::cout << "MyNameSpace::value = " << MyNameSpace::value << std::endl;
    std::cout << "MyNameSpace::ChildNamespace::value = "
              << MyNameSpace::ChildNamespace::value << std::endl;

    return 0;
}