#include <bits/stdc++.h>
using namespace std;
#define int long long
//线段树

const int N = 150005;
int a[N];
int mmax[4 * N]; //树
int iindex[4 * N]; //树
int lz[4 * N]; //懒惰标记
//4倍空间

void push_up(int n) {
    mmax[n] = max(mmax[2 * n], mmax[2 * n + 1]); //push_up
    iindex[n] = (mmax[2 * n] >= mmax[2 * n + 1]) ? iindex[2 * n] : iindex[2 * n + 1];
}

void push_down(int n,int mid,int l,int r) {
    lz[2 * n] += lz[n]; //push_down
    lz[2 * n + 1] += lz[n];
    mmax[2 * n] += lz[n];
    mmax[2 * n + 1] += lz[n];
    lz[n] = 0;
}

void build(int n,int l,int r) {
    //树的节点 左区间右区间
    if (l == r) {
        mmax[n] = 0;
        iindex[n] = l;
        return;
    }
    lz[n] = 0;
    mmax[n] = 0;
    int mid = (l + r) >> 1;
    build(2 * n, l, mid);
    build(2 * n + 1, mid + 1, r);
    push_up(n);
}

void update(int n,int l,int r,int x,int y,int k) {
    //树的节点 左区间右区间 要修改的左右区间 加的值
    if (x <= l && y >= r) {
        lz[n] += k;
        mmax[n] += k;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(n, mid, l, r);
    if (x <= mid) {
        update(2 * n, l, mid, x, y, k);
    }
    if (y > mid) {
        update(2 * n + 1, mid + 1, r, x, y, k);
    }
    push_up(n);
}

int rr[1000005], nex[N], pos[1000005];
int b[1000005];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 1000000; i++) {
        rr[i] = -1, pos[i] = -1;
        b[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        rr[a[i]] = max(rr[a[i]], i);
        nex[i] = -1;
        if (pos[a[i]] != -1) {
            nex[pos[a[i]]] = i;
        }
        pos[a[i]] = i;
    }
    build(1ll, 1ll, n);
    int ans = 0, index1 = 2, index2 = 3;
    for (int i = 2; i < n; i++) {
        int x = a[i - 1];
        if (b[x] == 0) {
            b[x] = 1;
            //first time
            if (nex[i - 1] != -1 && rr[x] != nex[i - 1]) {
                update(1ll, 1ll, n, nex[i - 1] + 1, rr[x], 1);
            }
        } else {
            if (nex[i - 1] != -1) {
                update(1ll, 1ll, n, i, nex[i - 1], -1);
            }
        }
        if (mmax[1] > ans) {
            ans = mmax[1], index1 = i, index2 = iindex[1];
        }
    }
    cout << ans << endl << index1 << ' ' << index2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
