/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n;
    cin >> n;
    double a[n + 10];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    while (1) {
        for (ll i = 1; i <= n - 1; i++) {
            a[i + 1] += a[i] / 2;
            a[i] /= 2;
        }
        a[1] += a[n] / 2;
        a[n] /= 2;
        for (ll i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
        system("pause");
    }
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
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;

void solve() {
    ll n;
    cin >> n;
    double a[n + 10], sum = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    printf("%.6lf ", (sum / (n * 1.0 + 1)) * 2);
    for (ll i = 1; i <= n - 1; i++) {
        printf("%.6lf ", sum / (n * 1.0 + 1));
    }
    cout << endl;
}

int main() {
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}

/*
7
9 9 9 9 9 9 9
 */

/*
6
3413 235 134 1234 132 1347

1855.71 927.857 927.857 927.857 927.857 927.857
 */
