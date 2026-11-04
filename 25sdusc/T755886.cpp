#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll mod = 1e9 + 7, N = 1e6 + 10;

void guess() {
    ll n;
    cin >> n;
    cout << 1 + (n - 1) * 2 << endl;
}

long double a[N], b[N];

void solve1() {
    ll n;
    cin >> n;
    a[0] = 0;
    for (ll i = 1; i <= n; i++) {
        a[i] = (a[i - 1] * i / n + 1) * n / i;
    }
    cout << fixed << setprecision(6) << a[n] << endl;
}

void init() {
    for (ll i = 1; i <= N - 10; i++) {
        b[i] = b[i - 1] + 1.0 / i;
    }
}

void solve2() {
    ll n;
    cin >> n;
    cout << fixed << setprecision(6) << n * b[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    init();
    while (T--) {
        solve2();
    }
    return 0;
}
/*
a0 = a1 + 1
a1 = (n-1)/n a2 + 1/n a1 +1
a2 = (n-2)/n a3 + 2/n a2 +1
...
an-1 = 1/n an + (n-1)/n an-1 +1
an = 0
*/