#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>

const ll N = 500000 + 10;

ll n, k, ans[N], cnt = 0;
ll f[N][2], g[N][2];
string s, t;

void dfs(ll step, ll uedg, ll dedg, ll ba) {
    if (step > n)
        return;
    if (ans[n - step] >= k * 2)
        return;
    if (uedg == 0 && dedg == 0) {
        ans[n - step + 1] += ba;
        dfs(step + 1, 0, 0, ba * 2);
    } else if (uedg == 1 && dedg == 0) {
        if (s[step] == 0) {
            ans[n - step + 1] += ba;
            dfs(step + 1, 1, 0, ba);
            dfs(step + 1, 0, 0, ba);
        } else {
            dfs(step + 1, 1, 0, ba);
        }
    } else if (uedg == 0 && dedg == 1) {
        if (t[step] == 1) {
            ans[n - step + 1] += ba;
            dfs(step + 1, 0, 0, ba);
            dfs(step + 1, 0, 1, ba);
        } else {
            dfs(step + 1, 0, 1, ba);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tmp = 1;
    cin >> n >> k >> s >> t;
    s = ' ' + s, t = ' ' + t;
    for (ll i = 1; i <= n; i++) {
        if (s[i] == 'a')
            s[i] = 0;
        else
            s[i] = 1;
        if (t[i] == 'a')
            t[i] = 0;
        else
            t[i] = 1;
    }
    while (s[tmp] == t[tmp] && tmp <= n)
        tmp++, cnt++;
    ans[n - tmp + 1] = 2;
    dfs(tmp + 1, 1, 0, 1); // 0
    dfs(tmp + 1, 0, 1, 1); // 1
    for (ll i = n; i >= 1; i--) {
        if (k >= ans[i]) {
            k -= ans[i];
            cnt += ans[i] * i;
        } else {
            cnt += k * i;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}
