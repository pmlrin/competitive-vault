#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 0, inf = 1e17;

void solve() {
    ll n;
    cin >> n;
    vector<char> ans;
    ll stk[n + 10], top = 0, las[n + 10] = {};
    PII op[n + 10];
    unordered_map<ll, ll> ins, del;
    for (ll i = 1; i <= n; i++) {
        char o;
        ll x;
        cin >> o >> x;
        op[i] = {o, x};
    }
    for (ll i = n; i >= 1; i--) {
        if (op[i].first == 'T' && ins.count(op[i].second) == 0) {
            las[i] = op[i].second;
            ins[op[i].second]++;
        }
        if (op[i].first == '+') {
            if (ins.count(op[i].second)) {
                ins.erase(op[i].second);
            } else {
                las[i] = op[i].second;
            }
        }
    }
    ins.clear();
    for (ll i = 1; i <= n; i++) {
        if (op[i].first == '+') {
            ans.push_back('+');
            ins[op[i].second]++;
            stk[++top] = op[i].second;
        } else if (op[i].first == 'T') {
            ans.push_back('?');
        } else {
            while (ins.count(op[i].second)) {
                ans.push_back('-');
                ins.erase(stk[top--]);
            }
            ans.push_back('?');
        }
        del[las[i]]++;
        while (del.count(stk[top]) && top >= 1) {
            ans.push_back('-');
            del.erase(stk[top]);
            ins.erase(stk[top--]);
        }
    }
    for (auto c: ans) {
        cout << c;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
