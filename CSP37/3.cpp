#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 2e3 + 10, inf = 1e17, mod = 1000000007;

ll n, val[N], ans[N], cnt = 0;
vector<ll> e[N];
map<string, ll> var;

ll getVar(string s) {
    if (var.count(s)) {
        return var[s];
    }
    return var[s] = ++cnt;
}

ll dfs(ll now) {
    if (ans[now]) {
        return ans[now];
    }
    ll ret = val[now];
    if (!e[now].empty()) {
        for (auto to : e[now]) {
            ret = (ret + dfs(to)) % mod;
        }
    }
    return ans[now] = ret;
}

void solve() {
    string tmp;
    cin >> n;
    getline(cin, tmp);
    for (ll i = 1; i <= n; i++) {
        ll curVar = 0;
        vector<string> opt(200);
        getline(cin, tmp);
        for (ll j = 0; j < tmp.size(); j++) {
            if (tmp[j] == ' ') {
                curVar++;
                continue;
            }
            opt[curVar].push_back(tmp[j]);
        }
        if (opt[0] == "1") {
            ll tmp = 0;
            curVar = getVar("$" + opt[1]);
            for (ll j = 2; j < opt.size(); j++) {
                if (opt[j][0] != '$') {
                    tmp = (tmp + opt[j].size()) % mod;
                } else {
                    tmp = (tmp + ans[getVar(opt[j])]) % mod;
                }
            }
            e[curVar].clear();
            val[curVar] = tmp;
        } else if (opt[0] == "2") {
            ll tmp = 0;
            vector<ll> tmpe;
            curVar = getVar("$" + opt[1]);
            for (ll j = 2; j < opt.size(); j++) {
                if (opt[j][0] != '$') {
                    tmp = (tmp + opt[j].size()) % mod;
                } else {
                    tmpe.push_back(getVar(opt[j]));
                }
            }
            e[curVar] = tmpe;
            val[curVar] = tmp;
        } else {
            cout << ans[getVar("$" + opt[1])] << endl;
        }
        for (ll i = 1; i <= cnt; i++) {
            ans[i] = 0;
        }
        for (ll i = 1; i <= cnt; i++) {
            if (!ans[i]) {
                dfs(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
