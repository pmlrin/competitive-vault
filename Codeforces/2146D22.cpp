#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 2e5 * 40;

struct Trie {
    ll index = 0, t[N][2] = {}, d[N] = {};

    void init() {
        index = 0;
        d[0] = 0;
        t[0][0] = t[0][1] = 0;
    }

    void insert(ll num) {
        ll cur = 0;
        d[cur]++;
        for (ll i = 1; i <= 30; i++) {
            if (t[cur][num % 2] == 0) {
                t[cur][num % 2] = ++index;
                d[index] = 0;
                t[index][0] = t[index][1] = 0;
            }
            cur = t[cur][num % 2];
            d[cur]++;
            num /= 2;
        }
    }

    PII query(ll num) {
        ll cur = 0, ret = 0, mir = 0;
        if (d[cur] <= 0)
            return {0, 0};
        d[cur]--;
        for (ll i = 1; i <= 30; i++) {
            if (t[cur][(num % 2) ^ 1] && d[t[cur][(num % 2) ^ 1]] >= 1) {
                cur = t[cur][(num % 2) ^ 1];
                ret += (1ll << (i - 1));
                mir += (((num % 2) ^ 1) << (i - 1));
                d[cur]--;
                num /= 2;
            } else if (t[cur][num % 2] && d[t[cur][num % 2]] >= 1) {
                cur = t[cur][num % 2];
                ret += ((num % 2) << (i - 1));
                mir += ((num % 2) << (i - 1));
                d[cur]--;
                num /= 2;
            } else
                return {ret, mir};
        }
        return {ret, mir};
    }
} Tree;

ll l, r, ans, a[N];

void solve() {
    cin >> l >> r;
    Tree.init();
    ans = 0;
    for (ll i = l; i <= r; i++)
        Tree.insert(i);
    for (ll i = l; i <= r; i++) {
        PII ret = Tree.query(i);
        ans += ret.first;
        a[i - l + 1] = ret.second;
    }
    cout << ans << endl;
    for (ll i = l; i <= r; i++)
        cout << a[i - l + 1] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
