#include <iostream>
using namespace std;

class People {
  protected:
    int age;
    int height;
    int weight;
    static int num;

  public:
    People(int a, int h, int w) {
        age = a;
        height = h;
        weight = w;
        num++;
    }

    void Eatting() { weight++; }
    void Sporting() { height++; }
    void Sleeping() {
        age++;
        height++;
        weight++;
    }
    void Show() const {
        cout << "年龄: " << age << " 岁, 身高: " << height
             << " 厘米, 体重: " << weight << " 市斤" << endl;
    }
    static void ShowNum() { cout << "人数: " << num << endl; }
};

int People::num = 0;

int main() {
    People obj1(8, 120, 60);
    obj1.Eatting();
    obj1.Sporting();
    obj1.Sleeping();
    obj1.Show();

    People obj2(18, 170, 108);
    obj2.Eatting();
    obj2.Sporting();
    obj2.Sleeping();
    obj2.Show();

    People::ShowNum();
    return 0;
}