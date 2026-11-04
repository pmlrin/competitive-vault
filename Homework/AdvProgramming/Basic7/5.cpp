#include <iostream>
using namespace std;

class Piont2D {
  public:
    int x, y;
    Piont2D(int a = 0, int b = 0) : x(a), y(b) {}
    friend ostream &operator<<(ostream &os, const Piont2D &p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

template <typename T, typename Index> T getElement(T arr[], Index index) {
    return arr[index];
}

int main() {
    int arr1[] = {10, 20, 30};
    cout << "Element at index 1: " << getElement(arr1, 1) << endl;

    Piont2D arr2[] = {Piont2D(1, 2), Piont2D(3, 4), Piont2D(5, 6)};
    Piont2D p = getElement(arr2, 2);
    cout << "Element at index 2: " << p << endl;

    return 0;
}