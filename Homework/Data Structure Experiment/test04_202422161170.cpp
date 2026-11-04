#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

template <class T> struct DSU {
    T fa[N];
    DSU(ll n = N - 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    T find(T x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return fa[x];
    }
    void unite(T x, T y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    }
};

int main() {
    ll n, m;
    cout << "Ver1\n";
    cout << "input\n";
    cin >> n >> m;
    DSU<ll> dsu(n);
    for (ll i = 1; i <= m; i++) {
        string s;
        cin >> s;
        dsu.unite(s[1] - '0', s[3] - '0');
    }
    cout << "output\n";
    vector<ll> ans[n + 1];
    for (ll i = 1; i <= n; i++) {
        ans[dsu.find(i)].push_back(i);
    }
    for (ll i = 1; i <= n; i++) {
        if (!ans[i].empty()) {
            cout << "(";
            for (auto x : ans[i]) {
                cout << x << ",)"[x == ans[i].back()];
            }
            cout << "\n";
        }
    }
    cout << "end\n";
    system("pause");
    return 0;
}