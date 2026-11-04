#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll p[110];
    p[100] = 1000000000;
    for (ll i = 1; i <= 99; i++)
        p[i] = c;
    for (ll i = 1; i <= 95; i++)
        p[i] = b;
    for (ll i = 1; i <= 50; i++)
        p[i] = a;
    cout << 100 << endl;
    for (ll i = 1; i <= 100; i++)
        cout << p[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
