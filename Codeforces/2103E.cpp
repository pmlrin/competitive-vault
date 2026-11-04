#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

ll n, k, a[N], oi[N * 3], oj[N * 3], ox[N * 3], cyc[N];
PII d[N];
map<ll, ll> b;
vector<ll> loop;

bool cmp(PII x,PII y) {
    return x.first < y.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll fin = 1, fail = 1, m = 0;
        ll ti, tj, tx, pos0, cur, flag = 1;
        ll curl = 0, lenl = 0;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            d[i] = (PII){a[i], i};
            cyc[i] = 0;
        }
        b.clear();
        loop.clear();
        for (ll i = 1; i <= n; i++) {
            if (a[i - 1] > a[i]) {
                fin = 0;
            }
            if (b.count(k - a[i]) >= 1) {
                fail++;
                ti = i;
                tx = a[i];
            }
            b[a[i]] = 1;
        }
        if (fin == 1) {
            cout << 0 << endl;
            continue;
        }
        if (fail == 1) {
            cout << -1 << endl;
            continue;
        }
        for (ll i = 1; i <= n; i++) {
            if (a[i] == k - tx) {
                tj = i;
                break;
            }
        }
        pos0 = ti;
        if (a[1] == 0 && a[n] == k) {
        } else if (a[1] == k && a[n] == 0) {
            ti = 1, tj = n, tx = k;
            a[ti] -= tx, a[tj] += tx;
            if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; }
        } else {
            a[ti] -= tx, a[tj] += tx;
            if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; } //ti 0  tj k
            pos0 = ti;
            if (a[n] != k) {
                ti = tj, tj = pos0, tx = a[n];
                a[ti] -= tx, a[tj] += tx;
                if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; } //ti 0
                ti = ti, tj = n, tx = a[ti];
                a[ti] -= tx, a[tj] += tx;
                if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; } //pos0 0  n k
                pos0 = ti;
            }
            if (a[ti] == 0)
                pos0 = ti;
            ti = n, tj = pos0, tx = a[1];
            a[ti] -= tx, a[tj] += tx;
            if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; } //n k
            ti = 1, tj = n, tx = a[1];
            a[ti] -= tx, a[tj] += tx;
            if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; } //1 0 n k
        }
        for (ll i = 1; i <= n; i++)
            d[i] = (PII){a[i], i};
        stable_sort(d + 1, d + 1 + n, cmp);
        b.clear();
        for (ll i = 2, j = 2; i <= n - 1; i++, j++) {
            if (cyc[i])
                continue;
            if (i == d[i].second)
                continue;
            cur = i;
            do {
                cyc[j] = cur;
                j = d[j].second;
            } while (cur != j);
        }
        for (ll i = 2; i <= n - 1; i++) {
            if (cyc[i] == 0)
                continue;
            b[cyc[i]] = i;
        }
        for (auto [bel,id]: b) {
            loop.push_back(bel);
        }
        lenl = loop.size();
        pos0 = cur = 1;
        while (flag) {
            if (pos0 == 1) {
                curl++;
                if (curl > lenl)
                    flag = 0;
                else
                    cur = loop[curl - 1];
            }
            ti = n, tj = pos0, tx = d[cur].first;
            a[ti] -= tx, a[tj] += tx;
            if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; }
            ti = d[cur].second, tj = n, tx = d[cur].first;
            a[ti] -= tx, a[tj] += tx;
            if (ti != tj && tx != 0) { ++m, oi[m] = ti, oj[m] = tj, ox[m] = tx; }
            if (pos0 == 1) {
                d[cur].second = 1;
            }
            pos0 = cur = ti;
            b[pos0] = 1;
        }
        cout << m << endl;
        for (ll i = 1; i <= m; i++) {
            cout << oi[i] << " " << oj[i] << " " << ox[i] << endl;
        }
    }
    return 0;
}
