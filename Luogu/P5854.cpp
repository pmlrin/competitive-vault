#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll, ll>
const ll N = 1e7 + 39;

ll n, w[N], ls[N], rs[N], stk[N], top = 0;

void solve() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> w[i];
    }
    // stk 维护笛卡尔树中节点对应到序列中的下标
    for (ll i = 1; i <= n; i++) {
        ll k = top; // top 表示操作前的栈顶，k 表示当前栈顶
        while (k > 0 && w[stk[k]] > w[i])
            k--; // 维护右链上的节点
        if (k)
            rs[stk[k]] = i; // 栈顶元素.右儿子 := 当前元素
        if (k < top)
            ls[i] = stk[k + 1]; // 当前元素.左儿子 := 上一个被弹出的元素
        stk[++k] = i;           // 当前元素入栈
        top = k;
    }
    cout << stk[1] << endl; // 根节点编号
    ll ansl = 0, ansr = 0;
    for (ll i = 1; i <= n; i++) {
        ansl ^= i * (ls[i] + 1);
        ansr ^= i * (rs[i] + 1);
        cout << ls[i] << " " << rs[i] << endl; // 每个节点左右儿子
    }
    cout << ansl << " " << ansr << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
/*
11
9
3
7
1
8
12
10
20
15
18
5
*/