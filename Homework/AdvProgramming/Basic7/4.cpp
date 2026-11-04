#include <iostream>
using namespace std;

template <typename T> T Max(T x, T y) { return x > y ? x : y; }

int main() {
    cout << "Max int: " << Max(1, 2) << endl;
    cout << "Max long: " << Max(1L, 2L) << endl;
    cout << "Max double: " << Max(1.8, 2.3) << endl;
    cout << "Max float: " << Max(1.8f, 2.3f) << endl;
    return 0;
}