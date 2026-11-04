#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

class Staff {
  protected:
    int num;
    char name[18];
    double rateOfAttend;
    double basicSal;
    double prize;
    static int count;

  public:
    Staff() {}
    void Input() {
        num = ++count;
        cout << "请输入编号为" << num << "号员工的信息" << endl;
        cout << "姓名:";
        cin >> name;
        cout << "基本工资:";
        cin >> basicSal;
        cout << "奖金:";
        cin >> prize;
        cout << "出勤率(0~1):";
        cin >> rateOfAttend;
    }
    void Output() const {
        cout << "编号:" << num << endl;
        cout << "姓名:" << name << endl;
        cout << "基本工资:" << basicSal << "元" << endl;
        cout << "奖金:" << prize << "元" << endl;
        cout << "出勤率:" << rateOfAttend * 100 << "%" << endl;
    }
    virtual void OutputWage() const {
        cout << "实发工资:" << basicSal + prize * rateOfAttend << "元" << endl;
    }
};

int Staff::count = 1000;

class Saleman : virtual public Staff {
  protected:
    double deductRate;
    double personAmount;

  public:
    void Input() {
        Staff::Input();
        cout << "销售员提成比例:";
        cin >> deductRate;
        cout << "个人销售额:";
        cin >> personAmount;
    }
    void Output() const {
        Staff::Output();
        cout << "销售员提成比例:" << deductRate << endl;
        cout << "个人销售额:" << personAmount << endl;
    }
    void OutputWage() const {
        cout << "实发工资:"
             << basicSal + prize * rateOfAttend + personAmount * deductRate
             << "元" << endl;
    }
};

class Manager : virtual public Staff {
  protected:
    double totalDeductRate;
    double totalAmount;

  public:
    void Input() {
        Staff::Input();
        cout << "经理提成比例:";
        cin >> totalDeductRate;
        cout << "总销售额:";
        cin >> totalAmount;
    }
    void Output() const {
        Staff::Output();
        cout << "经理提成比例:" << totalDeductRate << endl;
        cout << "总销售额:" << totalAmount << endl;
    }
    void OutputWage() const {
        cout << "实发工资:"
             << basicSal + prize * rateOfAttend + totalAmount * totalDeductRate
             << "元" << endl;
    }
};

class SaleManager : public Saleman, public Manager {
  public:
    void Input() {
        Staff::Input();
        cout << "销售员提成比例:";
        cin >> deductRate;
        cout << "个人销售额:";
        cin >> personAmount;
        cout << "经理提成比例:";
        cin >> totalDeductRate;
        cout << "总销售额:";
        cin >> totalAmount;
    }
    void Output() const {
        Staff::Output();
        cout << "销售员提成比例:" << deductRate << endl;
        cout << "个人销售额:" << personAmount << endl;
        cout << "经理提成比例:" << totalDeductRate << endl;
        cout << "总销售额:" << totalAmount << endl;
    }
    void OutputWage() const {
        cout << "实发工资:"
             << basicSal + prize * rateOfAttend + personAmount * deductRate +
                    totalAmount * totalDeductRate
             << "元" << endl;
    }
};

int main(void) {
    char flag = 'Y';
    while (toupper(flag) == 'Y') {
        cout << "请选择录入类别(1.员工 2.销售员 3.经理 4.销售经理):";
        int n;
        cin >> n;
        if (n == 1) {
            Staff objStaff;
            objStaff.Input();
            objStaff.Output();
            objStaff.OutputWage();
        } else if (n == 2) {
            Saleman objSaleman;
            objSaleman.Input();
            objSaleman.Output();
            objSaleman.OutputWage();
        } else if (n == 3) {
            Manager objManager;
            objManager.Input();
            objManager.Output();
            objManager.OutputWage();
        } else if (n == 4) {
            SaleManager objSaleManager;
            objSaleManager.Input();
            objSaleManager.Output();
            objSaleManager.OutputWage();
        } else {
            cout << "选择有误!" << endl;
        }
        cout << endl << "是否继续录入信息?(Y/N)";
        cin >> flag;
    }
    system("PAUSE");
    return 0;
}