#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>

const ll N = 200000 + 10;

struct SEG {
    ll x1, y1, x2, y2;
} a[10];

map<PII, ll> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll flag = 1, f1 = 0, f2 = 0;
    for (ll i = 1; i <= 4; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        if (a[i].x1 != a[i].x2 && a[i].y1 != a[i].y2) // 不平行
            flag = 0;
        if (a[i].x1 == a[i].x2 && a[i].y1 == a[i].y2) // 点
            flag = 0;
        if (a[i].x1 == a[i].x2)
            f1++;
        if (a[i].y1 == a[i].y2)
            f2++;
        b[{a[i].x1, a[i].y1}]++;
        b[{a[i].x2, a[i].y2}]++;
    }
    if (b.size() != 4)
        flag = 0;
    if (f1 != 2 || f2 != 2)
        flag = 0;
    for (auto [p, q]: b) {
        if (q != 2)
            flag = 0;
    }
    // cout << b.size();
    if (flag == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
/*
0 0 0 1
0 0 0 1
0 1 1 1
0 0 1 0
 */
