#include <iostream>
using namespace std;
namespace MyNameSpace {
int value = 10;
void print() { cout << "Hello from MyNamespace!" << endl; }
namespace ChildNamespace {
int value = 10;
int value2 = 20;
} // namespace ChildNamespace
} // namespace MyNameSpace