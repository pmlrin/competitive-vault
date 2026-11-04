#include <cstring>
#include <iostream>
using namespace std;

class Person {
  protected:
    char name[20];
    int age;
    char sex[4];

  public:
    Person(const char *n, int a, const char *s) {
        strcpy(name, n);
        age = a;
        strcpy(sex, s);
    }
    virtual void showInfo() const {
        cout << "Name:" << name;
        cout << ", Age:" << age;
        cout << ", Sex:" << sex << endl;
    }
};

class Teacher : virtual public Person {
  protected:
    char title[20];

  public:
    Teacher(const char *n, int a, const char *s, const char *t)
        : Person(n, a, s) {
        strcpy(title, t);
    }
    void showInfo() const {
        cout << "Name:" << name;
        cout << ", Age:" << age;
        cout << ", Sex:" << sex;
        cout << ", Title:" << title << endl;
    }
};

class Cadre : virtual public Person {
  protected:
    char post[20];

  public:
    Cadre(const char *n, int a, const char *s, const char *p)
        : Person(n, a, s) {
        strcpy(post, p);
    }
    void showInfo() const {
        cout << "Name:" << name;
        cout << ", Age:" << age;
        cout << ", Sex:" << sex;
        cout << ", Post:" << post << endl;
    }
};

class TeacherCadre : public Teacher, public Cadre {
  private:
    double wages;

  public:
    TeacherCadre(const char *n, int a, const char *s, const char *t,
                 const char *p, double w)
        : Person(n, a, s), Teacher(n, a, s, t), Cadre(n, a, s, p), wages(w) {}
    void showInfo() const {
        cout << "Name:" << name;
        cout << ", Age:" << age;
        cout << ", Sex:" << sex;
        cout << ", Title:" << title;
        cout << ", Post:" << post;
        cout << ", Wages:" << wages << endl;
    }
};

int main() {
    Person p("李四", 25, "女");
    p.showInfo();
    cout << endl;

    Teacher t("王五", 35, "男", "教授");
    t.showInfo();
    cout << endl;

    Cadre c("赵六", 40, "男", "主任");
    c.showInfo();
    cout << endl;

    TeacherCadre tc("张三", 30, "男", "教授", "主任", 5000.0);
    tc.showInfo();

    system("PAUSE");
    return 0;
}