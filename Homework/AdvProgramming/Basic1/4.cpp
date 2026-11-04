#include <iostream>
using namespace std;

void sort(int &a, int &b) {
    if (a < b)
        return;
    swap(a, b);
}

int main() {
    int a = 12, b = 7;
    sort(a, b);
    cout << a << " " << b << endl;
    a = 8, b = 234;
    sort(a, b);
    cout << a << " " << b << endl;
    return 0;
}
