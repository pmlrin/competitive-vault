#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>

const ll N = 25;
ll n, a[N], sum = 0;
map<ll, ll> b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t, ans;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        b.clear();
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        for (ll i = 0; i <= (1ll << n) - 1; i++) {
            ll tmp = i, cur = 0, j = 1;
            while (tmp) {
                if (tmp % 2 == 1)
                    cur += a[j];
                tmp /= 2;
                j++;
            }
            b[cur]++;
        }
        for (auto [u,v]: b) {
            if (v >= 2)
                ans = 1;
        }
        if (ans == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

