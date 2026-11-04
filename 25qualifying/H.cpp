#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int row[20] = {}, col[20] = {};
    for (int index = 2; index <= 10; index++) {
        vector<int> a;
        int b[100] = {};
        for (int i = 1; i <= index; i++)
            a.push_back(i);
        do {
            int cnt = 0;
            for (int i = 0; i < index - 1; i++) {
                if (abs(a[i] - a[i + 1]) == 1)
                    cnt++;
            }
            b[cnt]++;
        } while (next_permutation(a.begin(), a.end()));
        cout << index << " : ";
        for (int i = 0; i < index; i++)
            cout << b[i] << ' ';
        cout << endl;
    }
}

signed main() {
    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
