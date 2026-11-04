#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
#define lson (root*2)
#define rson (root*2+1)
#define dad (root/2)
const ll N = 1e6 + 10;

struct Heap {
    ll h[N] = {}, n = 0;

    ll up(ll root) {
        while (root > 1 && h[root] < h[dad]) {
            swap(h[root], h[dad]);
            root = dad;
        }
        return root;
    }

    ll down(ll root) {
        while (lson <= n) {
            ll temp = lson;
            if (rson <= n && h[rson] < h[lson])
                temp = rson;
            if (h[temp] >= h[root])
                break;
            swap(h[root], h[temp]);
            root = temp;
        }
        return root;
    }

    void build(ll siz, ll a[]) {
        n = siz;
        for (ll i = 1; i <= n; i++)
            h[i] = a[i];
        for (ll i = n; i >= 1; i--)
            down(i);
    }

    ll top() {
        return h[1];
    }

    ll push(ll val) {
        h[++n] = val;
        return up(n);
    }

    void pop(ll key = 1) {
        swap(h[key], h[n]);
        n--;
        down(1);
    }
};

priority_queue<ll, deque<ll>, greater<ll> > q;

void solve() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll op, tmp;
        cin >> op;
        if (op == 1) {
            cin >> tmp;
            q.push(tmp);
        } else if (op == 2) {
            cout << q.top() << endl;
        } else {
            q.pop();
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
