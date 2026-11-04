#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 500000 + 50, inf = 1145141919810, mod = 1000000000 + 7;
const ll M = 100000 + 50;

ll n, sx, sy, tx, ty, txpy, txmy;
vector<PII > X, Y, XPY, XMY;
map<PII, char> type;

bool cmp(PII a,PII b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll u, v, len, ans = 0;
    char c;
    cin >> n >> sx >> sy;
    tx = sx, ty = sy, txpy = sx + sy, txmy = sx - sy;
    X.push_back({sx, sy});
    Y.push_back({sx, sy});
    XPY.push_back({sx, sy});
    XMY.push_back({sx, sy});
    for (ll i = 1; i <= n; i++) {
        cin >> c >> u >> v;
        type[{u, v}] = c;
        if (u == tx)
            X.push_back({u, v});
        if (v == ty)
            Y.push_back({u, v});
        if (u + v == txpy)
            XPY.push_back({u, v});
        if (u - v == txmy)
            XMY.push_back({u, v});
    }
    sort(X.begin(), X.end(), cmp);
    sort(Y.begin(), Y.end(), cmp);
    sort(XPY.begin(), XPY.end(), cmp);
    sort(XMY.begin(), XMY.end(), cmp);
    //for (auto i: XPY) { cout << i.first << " " << i.second << endl; }
    len = X.size();
    for (ll i = 0; i <= len - 1; i++) {
        if (X[i].first == sx && X[i].second == sy) {
            PII cur;
            if (i >= 1) {
                cur = X[i - 1];
                if (type[cur] == 'R' || type[cur] == 'Q')
                    ans = 1;
            }
            if (i <= len - 2) {
                cur = X[i + 1];
                if (type[cur] == 'R' || type[cur] == 'Q')
                    ans = 1;
            }
        }
    }
    len = XPY.size();
    for (ll i = 0; i <= len - 1; i++) {
        if (XPY[i].first == sx && XPY[i].second == sy) {
            PII cur;
            if (i >= 1) {
                cur = XPY[i - 1];
                if (type[cur] == 'B' || type[cur] == 'Q')
                    ans = 1;
            }
            if (i <= len - 2) {
                cur = XPY[i + 1];
                if (type[cur] == 'B' || type[cur] == 'Q')
                    ans = 1;
            }
        }
    }
    len = Y.size();
    for (ll i = 0; i <= len - 1; i++) {
        if (Y[i].first == sx && Y[i].second == sy) {
            PII cur;
            if (i >= 1) {
                cur = Y[i - 1];
                if (type[cur] == 'R' || type[cur] == 'Q')
                    ans = 1;
            }
            if (i <= len - 2) {
                cur = Y[i + 1];
                if (type[cur] == 'R' || type[cur] == 'Q')
                    ans = 1;
            }
        }
    }
    len = XMY.size();
    for (ll i = 0; i <= len - 1; i++) {
        if (XMY[i].first == sx && XMY[i].second == sy) {
            PII cur;
            if (i >= 1) {
                cur = XMY[i - 1];
                if (type[cur] == 'B' || type[cur] == 'Q')
                    ans = 1;
            }
            if (i <= len - 2) {
                cur = XMY[i + 1];
                if (type[cur] == 'B' || type[cur] == 'Q')
                    ans = 1;
            }
        }
    }
    if (ans == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

/*
5
ab
ab
ab
a
ab
 */
