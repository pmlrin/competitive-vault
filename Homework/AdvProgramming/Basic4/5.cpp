#include <iostream>
using namespace std;

// 日期类
class Date {
  private:
    int year;  // 年
    int month; // 月
    int day;   // 日

    // 判断是否为闰年
    bool isLeapYear(int y) const {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    // 获取某年某月的天数
    int getDaysInMonth(int y, int m) const {
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && isLeapYear(y))
            return 29;
        return daysInMonth[m];
    }

  public:
    // 构造函数
    Date(int y = 2023, int m = 1, int d = 1) {
        year = y;
        month = m;
        day = d;
    }

    // 重载"+"运算符，实现日期加上天数
    Date operator+(int days) const {
        Date temp = *this;
        int remainDays = days;

        while (remainDays > 0) {
            int daysInCurrentMonth = temp.getDaysInMonth(temp.year, temp.month);
            int daysLeftInMonth = daysInCurrentMonth - temp.day;

            if (remainDays <= daysLeftInMonth) {
                temp.day += remainDays;
                remainDays = 0;
            } else {
                remainDays -= (daysLeftInMonth + 1);
                temp.day = 1;
                temp.month++;

                if (temp.month > 12) {
                    temp.month = 1;
                    temp.year++;
                }
            }
        }

        return temp;
    }

    // 重载"-"运算符，实现日期减去天数
    Date operator-(int days) const {
        Date temp = *this;
        int remainDays = days;

        while (remainDays > 0) {
            if (remainDays < temp.day) {
                temp.day -= remainDays;
                remainDays = 0;
            } else {
                remainDays -= temp.day;
                temp.month--;

                if (temp.month < 1) {
                    temp.month = 12;
                    temp.year--;
                }

                temp.day = temp.getDaysInMonth(temp.year, temp.month);
            }
        }

        return temp;
    }

    // 友元函数：重载"<<"运算符，用于输出日期
    friend ostream &operator<<(ostream &os, const Date &d);

    // 友元函数：重载">>"运算符，用于输入日期
    friend istream &operator>>(istream &is, Date &d);
};

// 重载"<<"运算符的实现
ostream &operator<<(ostream &os, const Date &d) {
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}

// 重载">>"运算符的实现
istream &operator>>(istream &is, Date &d) {
    is >> d.year >> d.month >> d.day;
    return is;
}

int main() {
    Date date1(2024, 2, 15);
    cout << "Initial Date: " << date1 << endl;

    Date date2 = date1 + 10;
    cout << "Date after adding 10 days: " << date2 << endl;

    Date date3 = date1 - 5;
    cout << "Date after subtracting 5 days: " << date3 << endl;

    cout << "Enter a date (yyyy mm dd): ";
    Date date4;
    cin >> date4;
    cout << "You entered: " << date4 << endl;
    return 0;
}
