#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

// 字符串类
class MyString {
  private:
    char *str; // 字符串指针

  public:
    // 构造函数
    MyString(const char *s = "") {
        if (s == NULL) {
            str = new char[1];
            str[0] = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
    }

    // 拷贝构造函数
    MyString(const MyString &s) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    // 析构函数
    ~MyString() { delete[] str; }

    // 重载"="运算符，实现字符串赋值
    MyString &operator=(const MyString &s) {
        if (this != &s) {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    // 重载"+"运算符，实现字符串连接
    MyString operator+(const MyString &s) const {
        char *temp = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        MyString result(temp);
        delete[] temp;
        return result;
    }

    // 重载"=="运算符，比较两个字符串是否相等
    bool operator==(const MyString &s) const { return strcmp(str, s.str) == 0; }

    // 重载"!="运算符，比较两个字符串是否不相等
    bool operator!=(const MyString &s) const { return strcmp(str, s.str) != 0; }

    // 返回字符串长度
    size_t length() const { return strlen(str); }

    // 提取子串：从pos开始，长度len
    MyString substring(size_t pos, size_t len) const {
        size_t currentLen = strlen(str);
        if (pos >= currentLen || len == 0) {
            return MyString("");
        }
        size_t maxLen = currentLen - pos;
        size_t realLen = (len > maxLen) ? maxLen : len;
        char *tmp = new char[realLen + 1];
        strncpy(tmp, str + pos, realLen);
        tmp[realLen] = '\0';
        MyString result(tmp);
        delete[] tmp;
        return result;
    }

    // 搜索字符，如果找到返回索引，否则返回-1
    int indexOf(char ch) const {
        const char *p = strchr(str, ch);
        return p ? static_cast<int>(p - str) : -1;
    }

    // 转为大写
    void toUpper() {
        for (size_t i = 0; i < strlen(str); ++i) {
            str[i] =
                static_cast<char>(toupper(static_cast<unsigned char>(str[i])));
        }
    }

    // 转为小写
    void toLower() {
        for (size_t i = 0; i < strlen(str); ++i) {
            str[i] =
                static_cast<char>(tolower(static_cast<unsigned char>(str[i])));
        }
    }

    // 友元函数：重载"<<"运算符，用于打印字符串
    friend ostream &operator<<(ostream &os, const MyString &s);
};

// 重载"<<"运算符的实现
ostream &operator<<(ostream &os, const MyString &s) {
    os << s.str;
    return os;
}

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3 = s1 + s2;

    cout << "s1: " << s1 << " (length=" << s1.length() << ")" << endl;
    cout << "s2: " << s2 << " (length=" << s2.length() << ")" << endl;
    cout << "s3: " << s3 << " (length=" << s3.length() << ")" << endl;

    cout << "s3 substring(1, 4): " << s3.substring(1, 4) << endl;
    cout << "s3 indexOf('o'): " << s3.indexOf('o') << endl;

    s3.toUpper();
    cout << "s3 toUpper: " << s3 << endl;

    s3.toLower();
    cout << "s3 toLower: " << s3 << endl;

    if (s1 == s2) {
        cout << "s1 is equal to s2" << endl;
    } else {
        cout << "s1 is not equal to s2" << endl;
    }

    return 0;
}
