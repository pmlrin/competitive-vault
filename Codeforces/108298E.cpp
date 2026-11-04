#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        a = abs(a * a - b * b);
        if (a == 3)
            cout << 1 << endl;
        else if (a % 4 == 0)
            cout << (a / 4 - 1) * 3 + 1 << endl;
        else if (a % 4 == 1)
            cout << (a / 4 - 1) * 3 + 2 << endl;
        else if (a % 4 == 3)
            cout << (a / 4 - 1) * 3 + 3 << endl;
    }
    return 0;
}
