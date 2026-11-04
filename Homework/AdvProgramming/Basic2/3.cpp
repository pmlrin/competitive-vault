#include <cmath>
#include <iostream>
using namespace std;

class Time {
  private:
    int hour, minute, second;

  public:
    void setTime(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            cout << "Invalid data!!" << endl;
            // 如果数据不合法，拒绝设定数据。
            return;
        }
        hour = h;
        minute = m;
        second = s;
    }
    void displayTime() {
        printf("Time: %02d:%02d:%02d\n", hour, minute, second);
    }
    void addOneSecond() {
        second++;
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
        hour %= 24;
    }
};

int main() {
    Time t;
    t.setTime(15, 30, 45); // 设置时间为15:30:45
    t.displayTime();       // 显示时间
    t.addOneSecond();      // 秒数增加1
    t.displayTime();       // 再次显示时间
    cout << endl;
    t.setTime(15, 30, 75); // 设置时间为15:30:75
    t.displayTime();       // 显示时间
    t.addOneSecond();      // 秒数增加1
    t.displayTime();       // 再次显示时间
    cout << endl;
    t.setTime(15, 30, 59); // 设置时间为15:30:59
    t.displayTime();       // 显示时间
    t.addOneSecond();      // 秒数增加1
    t.displayTime();       // 再次显示时间
    cout << endl;
    t.setTime(3, 59, 59); // 设置时间为03:59:59
    t.displayTime();      // 显示时间
    t.addOneSecond();     // 秒数增加1
    t.displayTime();      // 再次显示时间
    return 0;
}