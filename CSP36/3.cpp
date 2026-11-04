#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll inf = 1e17, mod = 998244353;

ll n, N, q;

struct Cache {
    list<PII> Data;
    map<ll, list<PII>::iterator> Pos;

    Cache() {
        for (ll i = 1; i <= n; i++) {
            Data.push_front({-1, -1});
        }
    }

    vector<string> replace(ll x) {
        vector<string> ret;
        auto back = Data.rbegin();
        if (back->second == 1) {
            ret.push_back("1 " + to_string(back->first));
        }
        Pos.erase(back->first);
        *back = {x, 0};
        return ret;
    }

    vector<string> operation(ll type, ll x) {
        vector<string> ret;
        if (Pos.count(x) == 0) {
            vector<string> tmp = replace(x);
            auto back = Data.end();
            back--;
            Pos[x] = back;
            for (auto i : tmp) {
                ret.push_back(i);
            }
            ret.push_back("0 " + to_string(x));
        }
        auto pos = Pos[x];
        auto [k, v] = *pos;
        Data.erase(pos);
        Data.push_front({k, max(v, type)});
        Pos[k] = Data.begin();
        return ret;
    }
};

ll findCache(ll x) { return x / n % N; }

void solve() {
    vector<string> tmp;
    cin >> n >> N >> q;
    Cache c[N];
    for (ll i = 1, o, p; i <= q; i++) {
        cin >> o >> p;
        tmp = c[findCache(p)].operation(o, p);
        for (auto j : tmp) {
            cout << j << endl;
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
/*
-5 0 -5 100 -5 0 -5
-5 -5 -10 90 85 85 80
*/