#include <cmath>
#include <iostream>
using namespace std;

class Box {
  public:
    int height;
    int width;
    int length;

    Box(int h, int w, int len) {
        height = h;
        width = w;
        length = len;
    }

    int volume() { return height * width * length; }
};

int main() {
    Box boxes[2] = {Box(12, 20, 25), Box(10, 14, 20)};

    for (int i = 0; i < 2; ++i) {
        cout << "Box " << i + 1 << " volume: " << boxes[i].volume() << endl;
    }
    return 0;
}