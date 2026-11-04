#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// 电话结构体定义
struct TelephoneType {
    bool delTag;       // 删除标志
    unsigned int seat; // 序号
    char name[16];     // 姓名
    char teleNo[18];   // 电话号码
};

// 电话号码簿类的声明和实现
class TelephoneBook {
  private:
    fstream file; // 电话号码簿文件

    // 辅助函数
    void AddData();    // 添加数据
    void UpdateData(); // 更新数据
    void SearchData(); // 查询数据
    void DeleteData(); // 删除数据
    void Pack();       // 重组文件

  public:
    TelephoneBook();          // 构造函数
    virtual ~TelephoneBook(); // 析构函数
    void Run();               // 运行主程序
};

// 构造函数，以读写二进制方式打开数据文件
TelephoneBook::TelephoneBook() {
    ifstream iFile("telph.dat");

    if (iFile.fail()) {
        // 打开文件失败，表示不存在文件，需要创建
        ofstream oFile("telph.dat");
        if (oFile.fail())
            throw "打开文件失败!";
        oFile.close();
    } else {
        // 存在文件
        iFile.close();
    }

    // 以读写二进制方式打开文件
    file.open("telph.dat", ios::in | ios::out | ios::binary);
    if (file.fail())
        throw "打开文件失败!";
}

// 析构函数
TelephoneBook::~TelephoneBook() { file.close(); }

// 添加数据函数
void TelephoneBook::AddData() {
    TelephoneType telph;
    unsigned int seat;

    cout << "请输入要添加的电话号码信息：" << endl;
    cout << "输入序号: ";
    cin >> seat;
    cin.ignore(); // 忽略换行符

    cout << "输入姓名: ";
    cin.getline(telph.name, 16);

    cout << "输入电话号码: ";
    cin.getline(telph.teleNo, 18);

    telph.seat = seat;
    telph.delTag = false;

    // 定位到文件末尾
    file.seekp(0, ios::end);

    // 写入记录
    file.write((char *)&telph, sizeof(TelephoneType));
    file.flush();

    cout << "添加成功!" << endl;
}

// 查询数据函数
void TelephoneBook::SearchData() {
    TelephoneType telph;
    unsigned int seat;
    int count = 0;

    cout << "输入要查询电话的序号: ";
    cin >> seat;
    cin.ignore();

    // 定位到文件开始
    file.seekg(0);
    file.clear();

    // 逐条读取记录
    file.read((char *)&telph, sizeof(TelephoneType));
    while (!file.eof()) {
        if (telph.seat == seat && !telph.delTag) {
            // 序号相同且记录正常
            cout << "查询成功!" << endl;
            cout << "序号: " << telph.seat << endl;
            cout << "姓名: " << telph.name << endl;
            cout << "电话号码: " << telph.teleNo << endl;
            count++;
            break;
        }
        file.read((char *)&telph, sizeof(TelephoneType));
    }

    if (count == 0) {
        cout << "查询失败，未找到该记录!" << endl;
        file.clear();
    }
}

// 更新数据函数
void TelephoneBook::UpdateData() {
    TelephoneType telph;
    unsigned int seat;
    bool found = false;

    cout << "输入要更新的电话号码序号: ";
    cin >> seat;
    cin.ignore();

    // 定位到文件开始
    file.seekg(0);
    file.clear();

    // 逐条读取记录查找
    file.read((char *)&telph, sizeof(TelephoneType));
    while (!file.eof()) {
        if (telph.seat == seat && !telph.delTag) {
            // 序号相同且记录正常
            found = true;
            cout << "原记录为:" << endl;
            cout << "序号: " << telph.seat << endl;
            cout << "姓名: " << telph.name << endl;
            cout << "电话号码: " << telph.teleNo << endl;

            // 输入新的信息
            cout << "\n请输入新的信息:" << endl;
            cout << "输入新姓名: ";
            cin.getline(telph.name, 16);

            cout << "输入新电话号码: ";
            cin.getline(telph.teleNo, 18);

            // 定位到该记录的位置并写入
            file.seekp(-sizeof(TelephoneType), ios::cur);
            file.write((char *)&telph, sizeof(TelephoneType));
            file.flush();

            cout << "更新成功!" << endl;
            break;
        }
        file.read((char *)&telph, sizeof(TelephoneType));
    }

    if (!found) {
        cout << "更新失败，未找到该记录!" << endl;
        file.clear();
    }
}

// 删除数据函数（做删除标志）
void TelephoneBook::DeleteData() {
    TelephoneType telph;
    unsigned int seat;

    cout << "输入要删除电话的序号: ";
    cin >> seat;
    cin.ignore();

    // 定位到文件开始
    file.seekg(0);
    file.clear();

    // 逐条读取记录查找
    file.read((char *)&telph, sizeof(TelephoneType));
    while (!file.eof()) {
        if (telph.seat == seat && !telph.delTag) {
            // 序号相同且记录正常，未作删除标志
            break;
        }
        file.read((char *)&telph, sizeof(TelephoneType));
    }

    if (!file.eof()) {
        // 查询成功
        cout << "被删除记录为:" << endl;
        cout << "序号: " << telph.seat << endl;
        cout << "姓名: " << telph.name << endl;
        cout << "电话号码: " << telph.teleNo << endl;

        telph.delTag = true; // 设置删除标志

        // 定位到该记录的位置并写入
        file.seekp(-sizeof(TelephoneType), ios::cur);
        file.write((char *)&telph, sizeof(TelephoneType));
        file.flush();

        cout << "删除成功!" << endl;
    } else {
        // 查询失败
        cout << "删除失败，未找到该记录!" << endl;
        file.clear();
    }
}

// 在物理上删除作有删除标记的记录
void TelephoneBook::Pack() {
    ofstream outFile("tem.dat", ios::app | ios::binary); // 建立输出文件对象
    TelephoneType telph;

    // 定位到文件开始
    file.seekg(0);
    file.clear();

    // 读取原文件中的所有记录
    file.read((char *)&telph, sizeof(TelephoneType));
    while (!file.eof()) {
        if (!telph.delTag) {
            // 记录正常，未作删除标志，写入临时文件
            outFile.write((char *)&telph, sizeof(TelephoneType));
        }
        file.read((char *)&telph, sizeof(TelephoneType));
    }

    file.close();    // 关闭原文件
    outFile.close(); // 关闭临时文件

    remove("telph.dat");            // 删除原文件
    rename("tem.dat", "telph.dat"); // 改名临时文件为原文件

    // 重新打开文件
    file.open("telph.dat", ios::in | ios::out | ios::binary);
}

// 运行主程序（处理电话号码簿）
void TelephoneBook::Run() {
    int select;

    do {
        cout << "\n========== 电话号码簿 ==========" << endl;
        cout << "请选择操作:" << endl;
        cout << "1. 增加数据" << endl;
        cout << "2. 更新数据" << endl;
        cout << "3. 查询数据" << endl;
        cout << "4. 删除数据" << endl;
        cout << "5. 重组文件" << endl;
        cout << "6. 退出" << endl;
        cout << "================================" << endl;
        cout << "请输入您的选择(1-6): ";
        cin >> select;
        cin.ignore(); // 忽略换行符

        switch (select) {
        case 1:
            AddData(); // 增加数据
            break;
        case 2:
            UpdateData(); // 更新数据
            break;
        case 3:
            SearchData(); // 查询数据
            break;
        case 4:
            DeleteData(); // 删除数据
            break;
        case 5:
            Pack(); // 在物理上删除作有删除标记的记录
            cout << "文件重组成功!" << endl;
            break;
        case 6:
            cout << "感谢使用，再见!" << endl;
            break;
        default:
            cout << "输入错误，请重新选择!" << endl;
        }

    } while (select != 6); // 选择6将退出
}

// 主函数
int main() {
    try {
        TelephoneBook book;
        book.Run();
    } catch (const char *msg) {
        cerr << "错误: " << msg << endl;
        return 1;
    }

    return 0;
}
