#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 0;
priority_queue<ll, deque<ll>, greater<ll> > down; //小根堆
priority_queue<ll> up; //大根堆

void solve() {
    ll n;
    cin >> n;
    for (ll i = 1, tmp; i <= n; i++) {
        cin >> tmp;
        if (up.empty() || up.top() > tmp)
            up.push(tmp);
        else
            down.push(tmp);
        while (up.size() > down.size()) {
            down.push(up.top());
            up.pop();
        }
        while (up.size() <= down.size()) {
            up.push(down.top());
            down.pop();
        }
        if (i % 2)
            cout << up.top() << endl;
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
