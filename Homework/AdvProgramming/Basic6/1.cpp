#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cout << " ";
    for (int j = 1; j <= 9; j++) {
        cout << j << "*";
    }
    cout << endl;

    for (int i = 1; i <= 9; i++) {
        cout << i << "*";
        for (int j = 1; j <= 9; j++) {
            if (j >= i) {
                cout << i * j;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
