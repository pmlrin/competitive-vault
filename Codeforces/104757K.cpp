#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 3500 + 50;

ll n, ans = 0;
string pre[N], suf[N];
string s;
map<string, map<string, ll> > b[N];
set<string> jud;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> s;
        s = ' ' + s;
        ll len = s.size() - 1;
        pre[0] = suf[len + 1] = "@";
        for (ll j = 1; j <= len; j++) {
            pre[j] = pre[j - 1] + s[j];
        }
        for (ll j = len; j >= 1; j--) {
            suf[j] = s[j] + suf[j + 1];
        }
        for (ll j = 1; j <= len - 1; j++) {
            string val1 = "", val2 = "";
            val1.push_back(s[j]);
            val1.push_back(s[j + 1]);
            val2 += pre[j - 1];
            val2 += suf[j + 2];
            b[len * 25 + j][val1][val2]++;
        }
    }
    for (ll i = 1; i <= 3000; i++) {
        for (auto [keyi,vali]: b[i]) {
            for (auto [keyj,valj]: b[i]) {
                if (keyi[1] == keyj[1] || keyi[0] == keyj[0])
                    continue;
                jud.clear();
                for (auto [p,q]: vali) {
                    if (vali.count(p) >= 1 && valj.count(p) >= 1)
                        jud.insert(p);
                }
                if (jud.size() == 1)
                    ans++;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
