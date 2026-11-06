#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N = 2e6 + 100;
const ll INF = 1e18;
int inf = 4e18;
ll tr[N << 2], tag[N << 2];

void build(int u, int l, int r) {
    tag[u] = tr[u] = INF;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u, l, mid);
    build(u, mid + 1, r);
}

void pushup(int u) { tr[u] = min(tr[u << 1], tr[u << 1 | 1]); }
void pushdown(int u) {
    if (tag[u]) {
        tr[u << 1] = tag[u << 1] = tag[u];
        tr[u << 1 | 1] = tag[u << 1 | 1] = tag[u];
        tag[u] = 0;
    }
}

ll query(int u, int l, int r, int L, int R) {
    if (l >= L && r <= R) {
        return tr[u];
    }
    pushdown(u);
    int mid = l + r >> 1;
    ll ans = INF;
    if (L <= mid)
        ans = min(ans, query(u << 1, l, mid, L, R));
    if (R > mid)
        ans = min(ans, query(u << 1 | 1, mid + 1, r, L, R));
    pushup(u);
    return ans;
}

void make(int u, int l, int r, int L, int R, ll x) {
    if (l >= L && r <= R) {
        tr[u] = x;
        tag[u] = x;
        return;
    }
    pushdown(u);
    int mid = l + r >> 1;
    if (L <= mid)
        make(u << 1, l, mid, L, R, x);
    if (R > mid)
        make(u << 1 | 1, mid + 1, r, L, R, x);
    pushup(u);
}

#define PII pair<int, int>
void solve1() {
    int n;
    cin >> n;
    int l[n + 5];
    int r[n + 5];
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        vec.push_back(l[i]);
        vec.push_back(r[i]);
    }
    sort(vec.begin(), vec.end());
    int cnt = 1;
    unordered_map<int, int> mp;
    mp[vec[0]] = ++cnt;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] != vec[i - 1])
            mp[vec[i]] = ++cnt;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = mp[l[i]];
        r[i] = mp[r[i]];
    }
    build(1ll, 1ll, 2 * n);
    make(1ll, 1ll, 2 * n, r[1], r[1], 1);
    for (int j = 2; j <= n; j++) {
        int x = query(1ll, 1ll, 2 * n, 1ll, r[j] - 1) + 1;
        int tmp = query(1ll, 1ll, 2 * n, r[j], r[j]);
        if (x < tmp) {
            make(1ll, 1ll, 2 * n, r[j], r[j], x);
        }
        if (l[j] != 2) {

            make(1ll, 1ll, 2 * n, 1ll, l[j] - 1, inf);
        }
    }
    int ans = query(1ll, 1ll, 2 * n, 1, 2 * n);
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T = 1;
    cin >> T;
    while (T--) {
        solve1();
    }
    return 0;
}
/*

cat
4
1 0
4 3
1 2
4 3
2 3
7 2
6 4
7 1
10 7
10 9
7 9
10 5
4 8
3 7
4 10
1 2


dog
4
1
1
4
1 2 4 6
7
1 5 7 9 13 10 2
10
1 2 5 13 12 19 6 16 8 10


*/