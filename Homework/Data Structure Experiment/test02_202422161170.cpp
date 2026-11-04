#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

void bubble(ll *a, ll n) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (ll i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                flag = true;
                swap(a[i], a[i + 1]);
            }
        }
    }
}

void insert(ll *a, ll n) {
    for (ll i = 2; i <= n; ++i) {
        ll key = a[i];
        ll j = i - 1;
        while (j >= 1 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void select(ll *a, ll n) {
    for (ll i = 1; i < n; ++i) {
        ll pos = i;
        for (ll j = i + 1; j <= n; ++j) {
            if (a[j] < a[pos]) {
                pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
}

int main() {
    ll type, n, a[N];
    cout << "Ver1\n";
    cout << "input\n";
    for (ll i = 1; i <= 18; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            break;
        }
        n = i;
    }
    cout << "1-bubble sort,2-insert sort,3-select sort\n";
    cin >> type;
    cout << "output\n";
    if (type == 1) {
        bubble(a, n);
        cout << "bubble sort\n";
    } else if (type == 2) {
        insert(a, n);
        cout << "insert sort\n";
    } else {
        select(a, n);
        cout << "select sort\n";
    }
    for (ll i = 1; i <= n; i++) {
        cout << a[i] << ",\n"[i == n];
    }
    cout << "end\n";
    system("pause");
    return 0;
}