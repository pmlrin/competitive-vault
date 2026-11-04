#include <bits/stdc++.h>
using namespace std;
namespace _yz {
typedef long long ll;
const ll N = 30000 + 10;
ll n, x, y, ans = 0;
void yzmain() {
    ll tmp, tmpx;
    scanf("%lld%lld%lld", &n, &x, &y);
    if (x == 1) {
        printf("%lld\n", y);
        return;
    }
    if (x == n) {
        printf("%lld\n", n * 2 - 2 + (n - y + 1));
        return;
    }
    if (x <= n / 2) {
        ans = y;
        tmp = n - 1;
        tmpx = x - 1;
        if (y > n / 2) {
            for (ll i = 2; i <= min(x, n - y + 1); i++) {
                ans += tmp * 4 - 1;
                tmp -= 2;
                tmpx--;
            }
            while (tmpx) {
                ans++;
                tmpx--;
            }
        } else {
            for (ll i = 2; i <= min(x, y + 1); i++) {
                ans += tmp * 4 - 1;
                tmp -= 2;
                tmpx--;
            }
            while (tmpx) {
                ans--;
                tmpx--;
            }
        }
        printf("%lld\n", ans);
    } else {
        ans = n * 2 - 2 + (n - y + 1);
        tmp = n - 2;
        tmpx = n - x;
        if (y > n / 2) {
            for (ll i = 2; i <= min(n - x + 1, n - y + 1); i++) {
                ans += tmp * 4 - 1;
                tmp -= 2;
                tmpx--;
            }
            while (tmpx) {
                ans--;
                tmpx--;
            }
        } else {
            for (ll i = 2; i <= min(n - x + 1, y); i++) {
                ans += tmp * 4 - 1;
                tmp -= 2;
                tmpx--;
            }
            while (tmpx) {
                ans++;
                tmpx--;
            }
        }
        printf("%lld\n", ans);
    }

    return;
}
} // namespace _yz
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    _yz::yzmain();
    return 0;
}
/*
6 5 3
*/