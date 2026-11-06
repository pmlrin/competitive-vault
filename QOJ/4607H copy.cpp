#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, u = 1;
    cin >> n;
    vector<int> vec;
    vec.push_back(1);
    for (int i = 2; i <= n; i++) {
        cout << "? " << u << " " << i << endl;
        bool op;
        cin >> op;
        if (op) {

        } else {
            vec.push_back(i);
            u = i;
        }
    }
    set<int> pos0, pos1, pos2;
    pos2.insert(u);
    for (int i = vec.size() - 2; i >= 0; i--) {
        cout << "? " << u << " " << vec[i] << endl;
        bool op;
        cin >> op;
        if (op) {
            break;
        } else {
            pos2.insert(vec[i]);
        }
    }
    cout << "! ";
    for (int x : pos0)
        cout << x << " ";
    for (int x : pos1)
        cout << x << " ";
    for (int x : pos2)
        cout << x << " ";
    cout << endl;
}

int main() {
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
