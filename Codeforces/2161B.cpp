#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n, num = 0;
    cin >> n;
    string g[n + 10];
    for (ll i = 0; i <= n - 1; i++) {
        cin >> g[i];
    }
    set<ll> jud1, jud2;
    for (ll i = 0; i <= n - 1; i++) {
        for (ll j = 0; j <= n - 1; j++) {
            if (g[i][j] == '#') {
                jud1.insert(i + j);
                jud2.insert(i - j);
                num++;
            }
        }
    }
    auto findsq = [&]() {
        for (ll i = 0; i <= n - 2; i++) {
            for (ll j = 0; j <= n - 2; j++) {
                if (g[i][j] == '#' && g[i][j + 1] == '#' && g[i + 1][j] == '#' && g[i + 1][j + 1] == '#') {
                    return 1;
                }
            }
        }
        return 0;
    };
    if (findsq()) {
        if (num == 4)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    if (num == 0) {
        cout << "YES" << endl;
        return;
    }
    if (*jud1.rbegin() - *jud1.begin() <= 1 || *jud2.rbegin() - *jud2.begin() <= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    //T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
