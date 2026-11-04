#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
const ll N = 200000 + 50;

struct CompareMin {
    bool operator()(const PII &a, const PII &b) const {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

priority_queue<PII, vector<PII >, CompareMin> q;
ll m, n;
PII a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll T;
    cin >> T;
    while (T--) {
        ll cur = 0, ans = 0;
        cin >> m >> n;
        for (ll i = 1; i <= m; i++) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first != a[i].second)
                q.push(a[i]);
        }
        while (!q.empty()) {
            while (!q.empty() && q.top().second <= cur)
                q.pop();
            if (q.empty())
                break;
            PII now = q.top();
            q.pop();
            if (cur < now.first) {
                cur += 2;
                ans++;
            } else {
                cur++;
                ans++;
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}
