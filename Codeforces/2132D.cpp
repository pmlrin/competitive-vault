#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 150000 + 50;

ll k, st[100], tmp[100];

ll calc(ll num) {
    ll len = 0, tmp = num, full, res, ret = 0;
    if (num <= 0)
        return 0;
    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    full = (num + 1) / (ll) pow(10, len - 1);
    res = (num + 1) % (ll) pow(10, len - 1);
    ret += full * (full - 1) / 2 * pow(10, len - 1);
    ret += full * calc(pow(10, len - 1) - 1);
    ret += full * res;
    ret += calc(res - 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T, b10 = 1, num, base, add, num2, res, len;
    cin >> T;
    for (ll i = 1; i <= 16; i++) {
        st[i] = i * 9 * b10 + st[i - 1];
        b10 *= 10;
    }
    while (T--) {
        cin >> k;
        for (ll i = 0; i <= 15; i++) {
            if (k <= st[i + 1] && k >= st[i]) {
                base = i;
                break;
            }
        }
        for (ll i = 1; i <= base; i++) {
            k += pow(10, i) - 1;
        }
        num = k / (base + 1);
        res = k % (base + 1);
        num2 = num + 1;
        add = len = 0;
        for (ll i = 1; i <= 16; i++)
            tmp[i] = 0;
        for (ll i = 1; num2 > 0; i++) {
            tmp[i] = num2 % 10;
            num2 /= 10, len++;
        }
        while (res > 0) {
            add += tmp[len];
            res--, len--;
        }
        cout << calc(num) + add << endl;
    }
    return 0;
}

/*
12345678910111213
 */
