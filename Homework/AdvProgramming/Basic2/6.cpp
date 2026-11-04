#include <cstring>
#include <iostream>
using namespace std;
class Student {
  private:
    char name[18];
    int num;
    int mathScore;
    int englishScore;
    static int count;
    static int mathTotalScore;
    static int englishTotalScore;

  public:
    Student(const char nm[], int nu, int math, int english) {
        strncpy(name, nm, 17);
        name[17] = '\0';
        num = nu;
        mathScore = math;
        englishScore = english;
        count++;
        mathTotalScore += math;
        englishTotalScore += english;
    }

    void ShowBase() const {
        cout << "姓名: " << name << ", 学号: " << num
             << ", 数学成绩: " << mathScore << ", 英语成绩: " << englishScore
             << endl;
    }

    static void ShowStatic() {
        cout << "人数: " << count << ", 数学总成绩: " << mathTotalScore
             << ", 英语总成绩: " << englishTotalScore << endl;
    }
};

int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;

int main() {
    Student obj1("李明", 1101, 98, 80);
    obj1.ShowBase();
    Student obj2("王杰", 1102, 96, 89);
    obj2.ShowBase();
    Student obj3("吴世宏", 1103, 86, 98);
    obj3.ShowBase();
    Student::ShowStatic();
    return 0;
}
