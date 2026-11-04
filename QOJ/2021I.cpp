#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

struct Data {
    ll num[10];

    Data() { memset(num, 0, sizeof(num)); }

    bool operator<(Data x) {
        for (int i = 1; i <= 8; i++) {
            if (num[i] == x.num[i]) {
                continue;
            }
            return num[i] < x.num[i];
        }
        return 0;
    }
};

ll to_number(string s) {
    ll ret = 0, len = s.size();
    for (ll i = 0; i < len; i++) {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}

void solve() {
    string A, B;
    cin >> A >> B;
    Data dA, dB;
    for (int i = 1; i <= 4; i++) {
        ll pos = A.find(".");
        if (pos != -1) {
            dA.num[i] = to_number(A.substr(0, pos));
            A.replace(0, pos + 1, "");
        } else {
            dA.num[i] = to_number(A);
            break;
        }
    }
    for (int i = 1; i <= 4; i++) {
        ll pos = B.find(".");
        if (pos != -1) {
            dB.num[i] = to_number(B.substr(0, pos));
            B.replace(0, pos + 1, "");
        } else {
            dB.num[i] = to_number(B);
            break;
        }
    }
    if (dA < dB) {
        cout << "B\n";
    } else if (dB < dA) {
        cout << "A\n";
    } else {
        cout << "Equal\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
