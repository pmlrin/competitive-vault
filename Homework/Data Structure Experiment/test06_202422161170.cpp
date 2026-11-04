#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100;

ll n, depth, flag, vis[N];
string a(' ', N), b(' ', N), c(' ', N);

void dfs(ll u, ll type, ll d, const string &arr) {
    if (u > n) {
        return;
    }
    depth = max(d, depth);
    if (type == 1) {
        if (flag == 1) {
            cout << ",";
        }
        flag = 1;
        cout << (char)(arr[u] - 'A' + 'a');
    }
    dfs(u * 2, type, d + 1, arr);
    if (type == 2) {
        if (flag == 1) {
            cout << ",";
        }
        flag = 1;
        cout << (char)(arr[u] - 'A' + 'a');
    }
    dfs(u * 2 + 1, type, d + 1, arr);
    if (type == 3) {
        if (flag == 1) {
            cout << ",";
        }
        flag = 1;
        cout << (char)(arr[u] - 'A' + 'a');
    }
}

void solve(ll lu, ll ru, ll lv, ll rv, ll root) {
    ll v = -1, mid = -1;
    c[root] = a[lu];
    if (lu == ru) {
        return;
    }
    for (ll i = lv; i <= rv; i++) {
        vis[b[i]] = 1;
        if (b[i] == a[lu]) {
            v = i;
            break;
        }
    }
    for (ll i = ru; i >= lu; i--) {
        if (vis[a[i]]) {
            mid = i;
            break;
        }
    }
    for (ll i = lv; i <= rv; i++) {
        vis[b[i]] = 0;
    }
    if (lu + 1 <= mid) {
        solve(lu + 1, mid, lv, v - 1, root * 2);
    }
    if (mid + 1 <= ru) {
        solve(mid + 1, ru, v + 1, rv, root * 2 + 1);
    }
}

int main() {
    cout << "Ver1\n";

    cout << "input1\n";
    cin >> a;
    cout << "output1\n";
    n = a.size();
    a = " " + a;
    flag = 0;
    depth = 0;
    dfs(1, 1, 1, a);
    cout << "\n";
    flag = 0;
    dfs(1, 2, 1, a);
    cout << "\n";
    flag = 0;
    dfs(1, 3, 1, a);
    cout << "\n";
    cout << n << "\n";
    cout << depth << "\n";

    cout << "input2\n";
    cin >> a >> b;
    cout << "output2\n";
    n = a.size();
    a = " " + a;
    b = " " + b;
    solve(1, n, 1, n, 1);
    depth = 0;
    flag = 0;
    dfs(1, 3, 1, c);
    cout << "\n";
    for (ll i = 1; i <= n; i++) {
        cout << (char)(c[i] - 'A' + 'a') << ",\n"[i == n];
    }

    cout << "end\n";
    system("pause");
    return 0;
}