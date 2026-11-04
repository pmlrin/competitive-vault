#include <iostream>
using namespace std;

template <class T> void func(T arr[], int step, int depth) {
    if (depth == step) {
        cout << "{ ";
        for (int i = 0; i < depth; i++) {
            if (arr[i]) {
                cout << arr[i] << " ";
            }
        }
        cout << "}" << endl;
        return;
    }
    T tmp = arr[step];
    arr[step] = T();
    func(arr, step + 1, depth);
    arr[step] = tmp;
    func(arr, step + 1, depth);
}

int main() {
    int n;
    char arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(arr, 0, n);
    return 0;
}