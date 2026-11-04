#include <bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
#define PII pair<ll, ll>
const ll N = 1e5 + 10, L = 18;

long long find(const long long x, const long long *a, const long long n) {
    ll l = 1, r = n, ret = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (a[mid] <= x) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    long long n, a[N], ntal;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> ntal;
    ll id = argc > 1 ? atoi(argv[1]) : 0;
    if (id == 0) {
        char op;
        ll l = LLONG_MIN, r = LLONG_MAX, ans = LLONG_MIN;
        long long inp;
        // l = 1, r = 10;
        while (l <= r) {
            ll mid = (l + r) / 2;
            cout << "? " << (long long)mid << endl;
            cin >> op >> inp;
            cout << find(mid, a, n) << endl;
            cin >> inp;
            if (inp < ntal / 2 + 1) {
                l = mid + 1;
            } else if (inp > ntal / 2 + 1) {
                r = mid - 1;
            } else {
                ans = mid;
                r = mid - 1;
            }
        }
        cout << "! " << (long long)(ans) << endl;
        cin >> op >> inp;
        cout << inp << endl;
    } else {
        char op;
        long long inp;
        while (1) {
            cin >> op >> inp;
            if (op == '?') {
                cout << find(inp, a, n) << endl;
            } else {
                cout << inp << endl;
                return 0;
            }
        }
    }
    return 0;
}
