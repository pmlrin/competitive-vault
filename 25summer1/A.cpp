#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 100000 + 10;

struct str {
    string s;
    ll rnk, len;
} S[N];

ll n;
string tmp, ans = "";

bool cmp(str x, str y) {
    ll len = x.len + y.len, cnt1 = 0, cnt2 = 0, hcnt = 0, thcnt = 0;
    string t = x.s + y.s;
    for (ll i = 0; i <= len - 1; i++) {
        if (t[i] == 'h')
            hcnt++;
    }
    thcnt = hcnt;
    for (ll i = 0; i <= len - 1; i++) {
        if (t[i] == 's')
            cnt1 += thcnt;
        else
            thcnt--;
    }
    thcnt = hcnt;
    t = y.s + x.s;
    for (ll i = 0; i <= len - 1; i++) {
        if (t[i] == 's')
            cnt2 += thcnt;
        else
            thcnt--;
    }
    return cnt1 > cnt2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll hcnt = 0, cnt = 0, slen = 0, maxlen = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> tmp;
        ll len = tmp.size(), rnk = 0, index = 0;
        for (ll j = len - 1; j >= 0; j--) {
            if (tmp[j] == 'h')
                rnk += (1ll << index);
            index++;
        }
        maxlen = max(maxlen, len);
        S[i].s = tmp;
        S[i].rnk = rnk;
        S[i].len = len;
    }
    stable_sort(S + 1, S + 1 + n, cmp);
    for (ll i = 1; i <= n; i++)
        ans += S[i].s;
    slen = ans.size();
    for (ll i = 0; i <= slen - 1; i++) {
        if (ans[i] == 'h')
            hcnt++;
    }
    for (ll i = 0; i <= slen - 1; i++) {
        if (ans[i] == 's')
            cnt += hcnt;
        else
            hcnt--;
    }
    // cout << ans << endl;
    cout << cnt << endl;
    return 0;
}
/*
2
sh
ssh

2
sh
shs

9
s
h
ss
sh
hs
hh
sss
shs
hsh

4
s
h
ss
hh

4
sssh
sshs
shss
sshh
 */
