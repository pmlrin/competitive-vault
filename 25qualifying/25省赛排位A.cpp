#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 150000 + 50;

ll n, b[10];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        cin >> n >> s;
        s = " " + s;
        b[0] = b[1] = 0;
        for (ll i = 1; i <= n; i++)
            b[s[i] - '0']++;
        if (b[0] == 0 && b[1])
            cout << "NO" << endl;
        else if (b[0] && b[1] == 0)
            cout << "YES" << endl;
        else if (b[0] && b[1])
            cout << "YES" << endl;
    }
    return 0;
}
