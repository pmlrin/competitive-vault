#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int a = 22;

    cout.setf(ios::dec);
    cout << "Dec: " << a << endl;
    cout.unsetf(ios::dec);

    cout.setf(ios::oct);
    cout << "Oct: " << a << endl;
    cout.unsetf(ios::oct);

    cout.setf(ios::hex);
    cout << "Hex: " << a << endl;
    cout.unsetf(ios::hex);

    cout.setf(ios::showbase);
    cout.setf(ios::dec);
    cout << "Dec with base: " << a << endl;
    cout.unsetf(ios::dec);
    cout.unsetf(ios::showbase);

    cout.setf(ios::oct);
    cout.setf(ios::showbase);
    cout << "Oct with base: " << a << endl;
    cout.unsetf(ios::oct);
    cout.unsetf(ios::showbase);

    cout.setf(ios::hex);
    cout.setf(ios::showbase);
    cout << "Hex with base: " << a << endl;
    cout.unsetf(ios::hex);
    cout.unsetf(ios::showbase);

    return 0;
}
