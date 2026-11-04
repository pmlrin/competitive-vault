#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50, inf = 1145141919810;

ll n, m, a[N], in[N], index, ans[N], b[N];
vector<ll> e[N], pos[N];
queue<ll> q;

void add(ll x, ll y) {
    // small <- big
    if (x == 0 || y == 0)
        return;
    e[y].push_back(x);
    in[x] += 1;
    //cout << y << " " << x << endl;
}

void topo() {
    for (ll i = n; i >= 1; i--) {
        if (in[i] == 0) {
            q.push(i);
            ans[i] = index--;
        }
    }
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        for (auto to: e[now]) {
            in[to]--;
            if (in[to] == 0) {
                q.push(to);
                ans[to] = index--;
            }
        }
    }
}

ll nxt(ll x, ll cur) {
    for (ll i = x + 1; i <= n; i++) {
        if (a[i] < cur)
            continue;
        if (a[i] > cur)
            return 0;
        if (a[i] == cur)
            return i;
    }
    return 0;
}

ll pre(ll x, ll cur) {
    for (ll i = x - 1; i >= 1; i--) {
        if (a[i] < cur)
            continue;
        if (a[i] > cur)
            return 0;
        if (a[i] == cur)
            return i;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll flag = 0;
        cin >> n;
        m = 0, index = n;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            m = max(m, a[i]);
            e[i].clear();
            pos[i].clear();
            in[i] = 0;
            b[i] = 0;
        }
        for (ll i = 1; i <= n; i++) {
            if (a[i] == -1)
                a[i] = m + 1;
        }
        for (ll i = 1; i <= n; i++) {
            pos[a[i]].push_back(i);
        }
        for (ll i = m; i >= 1; i--) {
            for (auto j: pos[i + 1]) {
                pos[i].push_back(j);
            }
        }
        for (ll i = 1; i <= m; i++) {
            for (auto j: pos[i + 1]) {
                if (a[j] != i + 1) {
                    if (i % 2) {
                        add(j, pre(j, i));
                        add(j, nxt(j, i));
                    } else {
                        add(pre(j, i), j);
                        add(nxt(j, i), j);
                    }
                }
                for (ll k = j; k; k = pre(k, i)) {
                    if (b[pre(k, i)] == i)
                        continue;
                    b[pre(k, i)] = i;
                    if (i % 2) {
                        add(k, pre(k, i));
                    } else {
                        add(pre(k, i), k);
                    }
                }
                for (ll k = j; k; k = nxt(k, i)) {
                    if (b[nxt(k, i)] == i)
                        continue;
                    b[nxt(k, i)] = i;
                    if (i % 2) {
                        add(k, nxt(k, i));
                    } else {
                        add(nxt(k, i), k);
                    }
                }
            }
            //cout << endl;
        }
        topo();
        for (ll i = 1; i <= n; i++) {
            if (ans[i] == n)
                flag = 1;
            cout << ans[i] << " ";
        }
        assert(flag);
        cout << endl;
    }
    return 0;
}

/*
1
6
1 3 1 2 1 -1

1
5
1 -1 1 2 1

1
8
3 1 2 1 -1 1 1 2

1
111
1 3 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 6 1 2 1 3 1 2 1 4 1 2 1 3 1  2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 -1 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1  2 1 4 1 2 1 1 1

*/
