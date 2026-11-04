#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>

const ll N = 20000 + 10;
const ll TA = 1, TR = 2, TD = 3;

string s;
char t[N];
ll a[N], cnt = 0, ans[N], num = 0;

void dfs(ll l, ll r, ll cur) {
    // cout << l << " " << r << endl;
    for (ll i = l; i <= r; i++) {
        if (a[i] == TA) {
            ll L = i + 1, R;
            ll ano = 1;
            for (i = i + 1; i <= r; i++) {
                if (a[i] == TA)
                    ano++;
                if (a[i] == -TA)
                    ano--;
                if (ano == 0)
                    break;
            }
            R = i - 1;
            dfs(L, R, ++num);
        }
        if (a[i] == TD)
            ans[cur]++;
    }
}

int main() {
    while (scanf("%s", t) != EOF)
        s = s + t;
    ll len = s.size();
    for (ll i = 0; i <= len - 1; i++) {
        if (s[i] == '<') {
            if (s[i + 1] == 't') {
                if (s[i + 2] == 'a')
                    a[++cnt] = TA;
                if (s[i + 2] == 'r')
                    a[++cnt] = TR;
                if (s[i + 2] == 'd')
                    a[++cnt] = TD;
            } else if (s[i + 1] == '/') {
                if (s[i + 3] == 'a')
                    a[++cnt] = -TA;
                if (s[i + 3] == 'r')
                    a[++cnt] = -TR;
                if (s[i + 3] == 'd')
                    a[++cnt] = -TD;
            }
        }
    }
    dfs(2, cnt - 1, ++num);
    sort(ans + 1, ans + 1 + num);
    for (ll i = 1; i <= num; i++)
        cout << ans[i] << " ";
    return 0;
}
/*
0 0 0 1
0 0 0 1
0 1 1 1
0 0 1 0
 */
