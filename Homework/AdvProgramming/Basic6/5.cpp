#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

class Student {
  private:
    int no;
    char name[16];
    int score;

  public:
    Student() : no(0), score(0) { strcpy_s(name, sizeof(name), ""); }

    Student(int n, const char *nm, int s) : no(n), score(s) {
        strcpy_s(name, sizeof(name), nm);
    }

    void Input() { cin >> no >> name >> score; }

    void Show() const {
        cout << setw(10) << no << setw(15) << name << setw(10) << score << endl;
    }

    void WriteToBinary(ofstream &file) const {
        file.write(reinterpret_cast<char *>(const_cast<int *>(&no)),
                   sizeof(int));
        file.write(name, sizeof(name));
        file.write(reinterpret_cast<char *>(const_cast<int *>(&score)),
                   sizeof(int));
    }

    void ReadFromBinary(ifstream &file) {
        file.read(reinterpret_cast<char *>(&no), sizeof(int));
        file.read(name, sizeof(name));
        file.read(reinterpret_cast<char *>(&score), sizeof(int));
    }
};

class StudentManage {
  private:
    static const char *FILENAME;
    static const int MAX_STUDENTS = 50;

    static void Write(Student students[], int count) {
        ofstream file(FILENAME, ios::binary);
        if (!file.is_open()) {
            cerr << "Error: Cannot open file" << endl;
            return;
        }

        file.write(reinterpret_cast<char *>(&count), sizeof(int));
        for (int i = 0; i < count; i++) {
            students[i].WriteToBinary(file);
        }
        file.close();
    }

    static int Read(Student students[]) {
        ifstream file(FILENAME, ios::binary);
        if (!file.is_open()) {
            return 0;
        }

        int count = 0;
        file.read(reinterpret_cast<char *>(&count), sizeof(int));

        if (count > MAX_STUDENTS) {
            file.close();
            return 0;
        }

        for (int i = 0; i < count; i++) {
            students[i].ReadFromBinary(file);
        }

        file.close();
        return count;
    }

    static void Show(const Student students[], int count) {
        if (count == 0) {
            cout << "No data." << endl;
            return;
        }

        cout << setw(10) << "ID" << setw(15) << "Name" << setw(10) << "Score"
             << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < count; i++) {
            students[i].Show();
        }
        cout << "=====================================" << endl;
    }

  public:
    static void Run() {
        Student students[MAX_STUDENTS];
        int studentCount = 0;
        int choice;

        while (true) {
            cout
                << "1. Insert\n2. Display\n3. Save\n4. Load\n5. Exit\nChoice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    students[studentCount].Input();
                    studentCount++;
                }
                break;
            case 2:
                Show(students, studentCount);
                break;
            case 3:
                if (studentCount > 0) {
                    Write(students, studentCount);
                }
                break;
            case 4:
                studentCount = Read(students);
                break;
            case 5:
                return;
            }
        }
    }
};

const char *StudentManage::FILENAME = "stud.dat";

int main() {
    StudentManage::Run();
    return 0;
}
