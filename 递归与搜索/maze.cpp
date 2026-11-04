#include <bits/stdc++.h>
using namespace std;
int main() {
    mt19937 rnd(time(0));
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 300; j++) {
            if (rnd() % 2) {
                cout << "¨v";
            } else {
                cout << "¨u";
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}