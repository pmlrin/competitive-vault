#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

class Date {
  private:
    int year;
    int month;
    int day;

  public:
    Date(int y = 1, int m = 1, int d = 1) : year(y), month(m), day(d) {}
    void SetYear(int y) { year = y; }
    void SetMonth(int m) { month = m; }
    void SetDay(int d) { day = d; }
    int GetYear() const { return year; }
    int GetMonth() const { return month; }
    int GetDay() const { return day; }

    Date operator+(int days) const {
        return NumToDate(DateToNum(*this) + days);
    }

    Date operator-(int days) const {
        return NumToDate(DateToNum(*this) - days);
    }

    static bool IsLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    static int GetYearDays(int y) { return IsLeapYear(y) ? 366 : 365; }

    static int GetMonthDays(const Date &d) {
        static const int daysInMonth[] = {0,  31, 28, 31, 30, 31, 30,
                                          31, 31, 30, 31, 30, 31};
        if (d.month == 2) {
            return IsLeapYear(d.year) ? 29 : 28;
        }
        return daysInMonth[d.month];
    }

    static int DateToNum(const Date &d) {
        int total = 0;
        for (int y = 1; y < d.year; ++y) {
            total += GetYearDays(y);
        }
        static const int monthDays[] = {0,  31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};
        for (int m = 1; m < d.month; ++m) {
            total += monthDays[m];
            if (m == 2 && IsLeapYear(d.year)) {
                total += 1;
            }
        }
        total += d.day - 1;
        return total;
    }

    static Date NumToDate(int n) {
        if (n < 0) {
            return Date(1, 1, 1);
        }
        int y = 1;
        while (true) {
            int yearDays = GetYearDays(y);
            if (n < yearDays)
                break;
            n -= yearDays;
            ++y;
        }
        int m = 1;
        while (true) {
            Date tmp(y, m, 1);
            int monthDays = GetMonthDays(tmp);
            if (n < monthDays)
                break;
            n -= monthDays;
            ++m;
        }
        int d = n + 1;
        return Date(y, m, d);
    }

    static int Week(const Date &d) { return (DateToNum(d) + 1) % 7; }
};

int main() {
    int year;
    cout << "输入年份：";
    if (!(cin >> year) || year < 1) {
        cout << "年份必须为公元后正整数。" << endl;
        return 0;
    }
    cout << setw(25) << year << "年" << endl;
    vector<string> monthNames = {"",     "一月",   "二月",  "三月", "四月",
                                 "五月", "六月",   "七月",  "八月", "九月",
                                 "十月", "十一月", "十二月"};
    vector<string> weekNames = {"星期日", "星期一", "星期二", "星期三",
                                "星期四", "星期五", "星期六"};
    for (int m = 1; m <= 12; ++m) {
        cout << "------------------------------------------------" << endl;
        cout << setw(26) << monthNames[m] << endl;
        for (const string &name : weekNames) {
            cout << name << " ";
        }
        cout << endl;
        Date firstDay(year, m, 1);
        int firstWeek = Date::Week(firstDay);
        int days = Date::GetMonthDays(firstDay);
        bool isFirstDay = 1;
        for (int i = 0; i < firstWeek; ++i) {
            cout << (isFirstDay ? setw(4) : setw(7)) << " ";
            isFirstDay = 0;
        }
        for (int d = 1; d <= days; ++d) {
            cout << (isFirstDay ? setw(4) : setw(7)) << d;
            isFirstDay = 0;
            if ((firstWeek + d) % 7 == 0) {
                isFirstDay = 1;
                cout << endl;
            }
        }
        cout << endl
             << "------------------------------------------------" << endl;
    }
    return 0;
}
