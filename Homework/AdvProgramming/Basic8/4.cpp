#include <iostream>
#include <vector>
using namespace std;
int Test(vector<int> vec, int i) { return vec.at(i); }
int main(void) {
    try {
        vector<int> vec = {10, 20, 30, 40, 50};
        int i = Test(vec, 10);
    } catch (const runtime_error &e) {
        cout << "异常信息:" << e.what() << endl;
    } catch (const out_of_range &e) {
        cout << "异常信息:" << e.what() << endl;
    } catch (char const *str) {
        cout << "异常信息:" << str << endl;
    }
    system("PAUSE");
    return 0;
}